#include <libraries/logger/Logger.h>
#include <libraries/Winshim/Winshim.h>
#include <libraries/ndutil/ndutil.h>
#include <libraries/ndutil/ndtestutil.h>
#include "params.h"
#include "ndscope.h"
#include "errors.h"
#include "work.h"

static void stage7(
    params_t* const params,
    work_t work,
    const struct sockaddr* pAddress,
    IND2Adapter* const pAdapter,
    HANDLE const hOverlappedFile,
    IND2MemoryRegion* const pMemoryRegion,
    ND2_ADAPTER_INFO const* const pInfo,
    IND2CompletionQueue* const pSendCompletionQueue,
    IND2CompletionQueue* const pRecvCompletionQueue
)
{
    LOG_ENTER();
    static void* const context = (void*)"CreateQueuePair context";

    ULONG const recvQueueDepth = 3;
    ULONG const sendQueueDepth = 3;
    ULONG const maxRecvRequestSge = 3;
    ULONG const maxSendRequestSge = 3;
    ULONG const inlineDataSize = pInfo->MaxInlineDataSize;

    IND2QueuePair* pQueuePair = 0;
    HRESULT const hr =
        pAdapter->CreateQueuePair(
            IID_IND2QueuePair,
            pSendCompletionQueue,
            pRecvCompletionQueue,
            context,
            recvQueueDepth,
            sendQueueDepth,
            maxRecvRequestSge,
            maxSendRequestSge,
            inlineDataSize,
            (void**)&pQueuePair
        );
    LOG("IND2Adapter::CreateQueuePair -> %08X", hr);
    if (ND_SUCCESS != hr)
        throw EX_CREATE_QUEUE_PAIR;
    try
    {
        (*work)(
            params,
            pAddress,
            pAdapter,
            hOverlappedFile,
            pMemoryRegion,
            pInfo,
            pSendCompletionQueue,
            pRecvCompletionQueue,
            pQueuePair
            );
    }
    catch (...)
    {
        ULONG ul = pQueuePair->Release();
        LOG("IND2QueuePair::Release -> %u", ul);
        throw;
    }
    ULONG ul = pQueuePair->Release();
    LOG("IND2QueuePair::Release -> %u", ul);

    LOG_VOID_RETURN();
}

static void stage6(
    params_t* const params,
    work_t work,
    const struct sockaddr* pAddress,
    IND2Adapter* const pAdapter,
    HANDLE const hOverlappedFile,
    IND2MemoryRegion* const pMemoryRegion,
    ND2_ADAPTER_INFO const* const pInfo,
    IND2CompletionQueue* const pSendCompletionQueue
)
{
    LOG_ENTER();
    IND2CompletionQueue* pRecvCompletionQueue = 0;
    HRESULT hr =
        pAdapter->CreateCompletionQueue(
            IID_IND2CompletionQueue,
            hOverlappedFile,
            pInfo->MaxCompletionQueueDepth,
            0,
            0,
            (void**)(&pRecvCompletionQueue)
        );
    LOG("IND2Adapter::CreateCompletionQueue -> %08X", hr);
    if (ND_SUCCESS != hr)
        throw EX_CREATE_COMPLETION_QUEUE;
    try
    {
        stage7(
            params,
            work,
            pAddress,
            pAdapter,
            hOverlappedFile,
            pMemoryRegion,
            pInfo,
            pSendCompletionQueue,
            pRecvCompletionQueue
        );
    }
    catch (...)
    {
        ULONG ul = pRecvCompletionQueue->Release();
        LOG("IND2CompletionQueue::Release -> %u", ul);
        throw;
    }
    ULONG ul = pRecvCompletionQueue->Release();
    LOG("IND2CompletionQueue::Release -> %u", ul);
    LOG_VOID_RETURN();
}

static void stage5(
    params_t* const params,
    work_t work,
    const struct sockaddr* pAddress,
    IND2Adapter* const pAdapter,
    HANDLE const hOverlappedFile,
    IND2MemoryRegion* const pMemoryRegion,
    ND2_ADAPTER_INFO const* const pInfo
)
{
    LOG_ENTER();
    IND2CompletionQueue* pSendCompletionQueue = 0;
    HRESULT hr =
        pAdapter->CreateCompletionQueue(
            IID_IND2CompletionQueue,
            hOverlappedFile,
            pInfo->MaxCompletionQueueDepth,
            0,
            0,
            (void**)(&pSendCompletionQueue)
        );
    LOG("IND2Adapter::CreateCompletionQueue -> %08X", hr);
    if (ND_SUCCESS != hr)
        throw EX_CREATE_COMPLETION_QUEUE;
    try
    {
        stage6(
            params,
            work,
            pAddress,
            pAdapter,
            hOverlappedFile,
            pMemoryRegion,
            pInfo,
            pSendCompletionQueue
        );
    }
    catch (...)
    {
        ULONG ul = pSendCompletionQueue->Release();
        LOG("IND2CompletionQueue::Release -> %u", ul);
        throw;
    }
    ULONG ul = pSendCompletionQueue->Release();
    LOG("IND2CompletionQueue::Release -> %u", ul);
    LOG_VOID_RETURN();
}

static void stage4(
    params_t* const params,
    work_t work,
    const struct sockaddr* pAddress,
    IND2Adapter* const pAdapter,
    HANDLE const hOverlappedFile,
    IND2MemoryRegion* const pMemoryRegion
)
{
    LOG_ENTER();
    LOG("pMemoryRegion: %p", pMemoryRegion);
    ND2_ADAPTER_INFO info = { 0 };
    info.InfoVersion = ND_VERSION_2;
    ULONG cbInfo = sizeof(info);
    HRESULT hr =
        pAdapter->Query(
            &info,
            &cbInfo
        );
    LOG("IND2Adapter::Query -> %08X", hr);
    if (ND_SUCCESS != hr)
        throw EX_QUERY;
    stage5(
        params,
        work,
        pAddress,
        pAdapter,
        hOverlappedFile,
        pMemoryRegion,
        &info
    );
    LOG_VOID_RETURN();
}

static void stage3(
    params_t* const params,
    work_t work,
    const struct sockaddr* pAddress,
    IND2Adapter* const pAdapter,
    HANDLE const hOverlappedFile
)
{
    LOG_ENTER();
    IND2MemoryRegion* pMemoryRegion = 0;
    HRESULT hr =
        pAdapter->CreateMemoryRegion(
            IID_IND2MemoryRegion,
            hOverlappedFile,
            (void**)&pMemoryRegion
        );
    LOG("IND2Adapter::CreateMemoryRegion -> %08X", hr);
    if (hr != ND_SUCCESS)
        throw EX_CREATE_MEMORY_REGION;
    try
    {
        stage4(
            params,
            work,
            pAddress,
            pAdapter,
            hOverlappedFile,
            pMemoryRegion
        );
    }
    catch (...)
    {
        ULONG ul = pMemoryRegion->Release();
        LOG("IND2MemoryRegion::Release -> %u", ul);
        throw;
    }
    ULONG ul = pMemoryRegion->Release();
    LOG("IND2MemoryRegion::Release -> %u", ul);
    LOG_VOID_RETURN();
}

static void stage2(
    params_t* const params,
    work_t work,
    const struct sockaddr* pAddress,
    IND2Adapter* const pAdapter
)
{
    LOG_ENTER();
    HANDLE  hOverlappedFile = 0;
    HRESULT hr =
        pAdapter->CreateOverlappedFile(
            &hOverlappedFile
        );
    LOG("IND2Adapter::CreateOverlappedFile -> %08X", hr);
    if (hr != ND_SUCCESS)
        throw EX_CREATE_OVERLAPPED_FILE;
    try
    {
        stage3(params, work, pAddress, pAdapter, hOverlappedFile);
    }
    catch (...)
    {
        BOOL b = CloseHandle(hOverlappedFile);
        LOG("CloseHandle -> %d", b);
        throw;
    }
    BOOL b = CloseHandle(hOverlappedFile);
    LOG("CloseHandle -> %d", b);
    LOG_VOID_RETURN();
}

void work(
    params_t* const params,
    work_t work,
    get_local_address_t get_local_address
)
{
    LOG_ENTER();

    struct sockaddr LocalAddress = (*get_local_address)(
        (LPSTR)params->ip.c_str(),
            params->port
            );

    IND2Adapter* pAdapter = 0;
    HRESULT const hr =
        NdOpenAdapter(
            IID_IND2Adapter,
            &LocalAddress,
            sizeof(LocalAddress),
            (void**)&pAdapter
        );
    if (ND_SUCCESS != hr)
        throw EX_OPEN_ADAPTER;

    try
    {
        stage2(params, work, &LocalAddress, pAdapter);
    }
    catch (...)
    {
        ULONG const ul = pAdapter->Release();
        LOG("IND2Adapter::Release -> %u", ul);
        throw;
    }

    ULONG const ul = pAdapter->Release();
    LOG("IND2Adapter::Release -> %u", ul);
    LOG_VOID_RETURN();
}

SOCKADDR get_sockaddr(LPSTR AddressString, INT AddressFamily, uint16_t port)
{
    LOG_ENTER();
    SOCKADDR saddr;
    INT AddressLength = (int)sizeof(saddr);
    // raises an exception on failure therefore no need to look at the return code
    Win::WSAStringToAddressA(
        AddressString,
        AddressFamily,
        0,                          // lpProtocolInfo
        &saddr,                     // lpAddress
        &AddressLength              // lpAddressLength
    );
    ((struct sockaddr_in*)&saddr)->sin_port = htons(port);
    LOG_STRUCT_RETURN(SOCKADDR);
    return saddr;
}

void RegisterMemory(IND2MemoryRegion* pMemoryRegion, void* buffer, size_t size)
{
    LOG_ENTER();
    OVERLAPPED ov = { 0 };
    ULONG const flags =
        ND_MR_FLAG_ALLOW_LOCAL_WRITE |
        ND_MR_FLAG_ALLOW_REMOTE_READ |
        ND_MR_FLAG_ALLOW_REMOTE_WRITE;
    HRESULT hr =
        pMemoryRegion->Register(
            buffer,
            size,
            flags,
            &ov
        );
    LOG("IND2MemoryRegion::Register -> %08X", hr);
    if (ND_SUCCESS != hr)
    {
        if (ND_PENDING != hr)
            throw EX_REGISTER;
        uint64_t count = 1;
        while (ND_PENDING == (hr = pMemoryRegion->GetOverlappedResult(&ov, FALSE)))
        {
            count += 1;
        }
        LOG("IND2MemoryRegion::GetOverlappedResult -> %08X (called %zu times)", hr, count);
        if (ND_SUCCESS != hr)
            throw EX_REGISTER_OV;
    }
    LOG_VOID_RETURN();
}

void DeregisterMemory(IND2MemoryRegion* pMemoryRegion)
{
    // do not throw an exception!
    LOG_ENTER();
    OVERLAPPED ov = { 0 };
    HRESULT hr = pMemoryRegion->Deregister(&ov);
    LOG("IND2MemoryRegion::Deregister -> %08X", hr);
    if (ND_PENDING == hr)
    {
        uint64_t count = 1;
        while (ND_PENDING == (hr = pMemoryRegion->GetOverlappedResult(&ov, FALSE)))
        {
            count += 1;
        }
        LOG("IND2MemoryRegion::GetOverlappedResult -> %08X (called %zu times)", hr, count);
    }
    LOG_VOID_RETURN();
}