#include <libraries/logger/Logger.h>
#include <libraries/Winshim/Winshim.h>
#include <libraries/ndutil/ndutil.h>
#include <libraries/ndutil/ndtestutil.h>
#include "params.h"
#include "ndscope.h"
#include "errors.h"
#include "work.h"
#include "client.h"

static void server_work4(
    params_t* const params,
    const struct sockaddr* pAddress,
    IND2Adapter* const pAdapter,
    HANDLE const hOverlappedFile,
    IND2MemoryRegion* const pMemoryRegion,
    ND2_ADAPTER_INFO const* const pInfo,
    IND2CompletionQueue* const pSendCompletionQueue,
    IND2CompletionQueue* const pRecvCompletionQueue,
    IND2QueuePair* const pQueuePair,
    void* buffer,
    size_t size,
    IND2Listener* pListener,
    IND2Connector* pConnector
)
{
    LOG_ENTER();
    OVERLAPPED ov = { 0 };
    HRESULT hr =
        pListener->GetConnectionRequest(
            pConnector,
            &ov
        );
    LOG("IND2Listener::GetConnectionRequest -> %08X", hr);
    if (ND_SUCCESS != hr)
    {
        if (ND_PENDING != hr)
            throw EX_GET_CONNECTION_REQUEST;
        uint64_t count = 1;
        while (ND_PENDING == (hr = pListener->GetOverlappedResult(&ov, FALSE)))
        {
            count += 1;
        }
        LOG("IND2Listener::GetOverlappedResult -> %08X (called %zu times)", hr, count);
        if (ND_SUCCESS != hr)
            throw EX_GET_CONNECTION_REQUEST;
    }

    LOG_VOID_RETURN();
}

static void server_work3(
    params_t* const params,
    const struct sockaddr* pAddress,
    IND2Adapter* const pAdapter,
    HANDLE const hOverlappedFile,
    IND2MemoryRegion* const pMemoryRegion,
    ND2_ADAPTER_INFO const* const pInfo,
    IND2CompletionQueue* const pSendCompletionQueue,
    IND2CompletionQueue* const pRecvCompletionQueue,
    IND2QueuePair* const pQueuePair,
    void* buffer,
    size_t size,
    IND2Listener* pListener
)
{
    LOG_ENTER();
    HRESULT hr = pListener->Bind(pAddress, sizeof(*pAddress));
    LOG("IND2Listener::Bind -> %08X", hr);
    if (ND_SUCCESS != hr)
        throw EX_LISTEN_BIND;

    hr = pListener->Listen(params->backlog);
    LOG("IND2Listener::Listen -> %08X", hr);
    if (ND_SUCCESS != hr)
        throw EX_LISTEN;

    IND2Connector* pConnector = 0;
    hr = pAdapter->CreateConnector(
        IID_IND2Connector,
        hOverlappedFile,
        (void**)&pConnector
    );
    LOG("IND2Adapter::CreateConnector -> %08X", hr);
    if (ND_SUCCESS != hr)
        throw EX_CREATE_CONNECTOR;
    try
    {
        server_work4(
            params,
            pAddress,
            pAdapter,
            hOverlappedFile,
            pMemoryRegion,
            pInfo,
            pSendCompletionQueue,
            pRecvCompletionQueue,
            pQueuePair,
            buffer,
            size,
            pListener,
            pConnector
        );
    }
    catch (...)
    {
        ULONG const ul = pConnector->Release();
        LOG("IND2Connector::Release -> %08X", ul);
        throw;
    }
    ULONG const ul = pConnector->Release();
    LOG("IND2Connector::Release -> %08X", ul);


    LOG_VOID_RETURN();
}

static void server_work2(
    params_t* const params,
    const struct sockaddr* pAddress,
    IND2Adapter* const pAdapter,
    HANDLE const hOverlappedFile,
    IND2MemoryRegion* const pMemoryRegion,
    ND2_ADAPTER_INFO const* const pInfo,
    IND2CompletionQueue* const pSendCompletionQueue,
    IND2CompletionQueue* const pRecvCompletionQueue,
    IND2QueuePair* const pQueuePair,
    void* buffer,
    size_t size
)
{
    LOG_ENTER();
    void* context = (void*)"Receive Context";
    UINT32 LocalToken = pMemoryRegion->GetLocalToken();
    LOG("IND2MemoryRegion::GetLocalToken -> %08X", LocalToken);
    ND2_SGE sge;
    sge.Buffer = buffer;
    sge.BufferLength = (ULONG)size;
    sge.MemoryRegionToken = LocalToken;
    HRESULT hr =
        pQueuePair->Receive(
            context,
            &sge,
            1
        );
    LOG("IND2QueuePair::Receive -> %08X", hr);
    if (ND_SUCCESS != hr)
        throw EX_RECEIVE;
    IND2Listener* pListener = 0;
    hr = pAdapter->CreateListener(
        IID_IND2Listener,
        hOverlappedFile,
        (void**)&pListener
    );
    LOG("IND2Adapter::CreateListener -> %08X", hr);
    if (ND_SUCCESS != hr)
        throw EX_CREATE_LISTENER;
    try
    {
        server_work3(
            params,
            pAddress,
            pAdapter,
            hOverlappedFile,
            pMemoryRegion,
            pInfo,
            pSendCompletionQueue,
            pRecvCompletionQueue,
            pQueuePair,
            buffer,
            size,
            pListener
        );
    }
    catch (...)
    {
        ULONG const ul = pListener->Release();
        LOG("IND2Listener::Release -> %u", ul);
        throw;
    }
    ULONG const ul = pListener->Release();
    LOG("IND2Listener::Release -> %u", ul);
    LOG_VOID_RETURN();
}


static void server_work1(
    params_t* const params,
    const struct sockaddr* pAddress,
    IND2Adapter* const pAdapter,
    HANDLE const hOverlappedFile,
    IND2MemoryRegion* const pMemoryRegion,
    ND2_ADAPTER_INFO const* const pInfo,
    IND2CompletionQueue* const pSendCompletionQueue,
    IND2CompletionQueue* const pRecvCompletionQueue,
    IND2QueuePair* const pQueuePair,
    void* buffer,
    size_t size
)
{
    LOG_ENTER();
    RegisterMemory(pMemoryRegion, buffer, size);
    try
    {
        server_work2(
            params,
            pAddress,
            pAdapter,
            hOverlappedFile,
            pMemoryRegion,
            pInfo,
            pSendCompletionQueue,
            pRecvCompletionQueue,
            pQueuePair,
            buffer,
            size
        );
    }
    catch (...)
    {
        DeregisterMemory(pMemoryRegion);
        throw;
    }
    DeregisterMemory(pMemoryRegion);
    LOG_VOID_RETURN();
}

static void server_work(
    params_t* const params,
    const struct sockaddr* pAddress,
    IND2Adapter* const pAdapter,
    HANDLE const hOverlappedFile,
    IND2MemoryRegion* const pMemoryRegion,
    ND2_ADAPTER_INFO const* const pInfo,
    IND2CompletionQueue* const pSendCompletionQueue,
    IND2CompletionQueue* const pRecvCompletionQueue,
    IND2QueuePair* const pQueuePair
)
{
    LOG_ENTER();
    size_t const size = params->size;
    void* const buffer = malloc(size);
    LOG("malloc %zu -> %p", size, buffer);
    if (!buffer)
        throw EX_MALLOC;
    try
    {
        server_work1(
            params,
            pAddress,
            pAdapter,
            hOverlappedFile,
            pMemoryRegion,
            pInfo,
            pSendCompletionQueue,
            pRecvCompletionQueue,
            pQueuePair,
            buffer,
            size
        );
    }
    catch (...)
    {
        LOG("free %p -> void", buffer);
        free(buffer);
        throw;
    }
    free(buffer);
    LOG("free %p -> void", buffer);
    LOG_VOID_RETURN();
}

static struct sockaddr get_sock_addr(LPSTR AddressString, uint16_t port)
{
    return (struct sockaddr)get_sockaddr(AddressString, AF_INET, port);
}

void server(params_t* const params)
{
    work(params, server_work, get_sock_addr);
}
