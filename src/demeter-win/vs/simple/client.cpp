#include <libraries/logger/Logger.h>
#include <libraries/Winshim/Winshim.h>
#include <libraries/ndutil/ndutil.h>
#include <libraries/ndutil/ndtestutil.h>
#include "params.h"
#include "ndscope.h"
#include "errors.h"
#include "work.h"
#include "client.h"


static struct sockaddr get_local_client_address(LPSTR RemoteIpAddress, uint16_t port)
{
    LOG_ENTER();
    struct sockaddr const RemoteAddress = 
        (struct sockaddr)get_sockaddr(RemoteIpAddress, AF_INET, port);
    struct sockaddr LocalAddress = { 0 };
    size_t cbLocalAddress = sizeof(LocalAddress);
    HRESULT hr =
        NdResolveAddress(
            &RemoteAddress,
            sizeof(RemoteAddress),
            &LocalAddress,
            &cbLocalAddress
        );
    if (ND_SUCCESS != hr)
        throw EX_RESOLVE_ADDRESS;
    LOG_STRUCT_RETURN(struct sockaddr);
    return LocalAddress;
}

static void client_work2(
    params_t* const params,
    const struct sockaddr* pAddress,
    IND2Adapter* const pAdapter,
    HANDLE const hOverlappedFile,
    IND2MemoryRegion* const pMemoryRegion,
    ND2_ADAPTER_INFO const* const pInfo,
    IND2CompletionQueue* const pSendCompletionQueue,
    IND2CompletionQueue* const pRecvCompletionQueue,
    IND2QueuePair* const pQueuePair,
    IND2Connector* const pConnector,
    void* const buffer
)
{
    LOG_ENTER();
    HRESULT hr = pConnector->Bind(pAddress, (ULONG)sizeof(*pAddress));
    LOG("IND2Connector::Bind -> %08X", hr);
    LOG_VOID_RETURN();
}

static void client_work1(
    params_t* const params,
    const struct sockaddr* pAddress,
    IND2Adapter* const pAdapter,
    HANDLE const hOverlappedFile,
    IND2MemoryRegion* const pMemoryRegion,
    ND2_ADAPTER_INFO const* const pInfo,
    IND2CompletionQueue* const pSendCompletionQueue,
    IND2CompletionQueue* const pRecvCompletionQueue,
    IND2QueuePair* const pQueuePair,
    IND2Connector* const pConnector,
    void* const buffer
)
{
    LOG_ENTER();
    RegisterMemory(pMemoryRegion, buffer, params->size);
    try
    {
        client_work2(
            params,
            pAddress,
            pAdapter,
            hOverlappedFile,
            pMemoryRegion,
            pInfo,
            pSendCompletionQueue,
            pRecvCompletionQueue,
            pQueuePair,
            pConnector,
            buffer
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


static void client_work(
    params_t* const params,
    const struct sockaddr* pAddress,
    IND2Adapter* const pAdapter,
    HANDLE const hOverlappedFile,
    IND2MemoryRegion* const pMemoryRegion,
    ND2_ADAPTER_INFO const* const pInfo,
    IND2CompletionQueue* const pSendCompletionQueue,
    IND2CompletionQueue* const pRecvCompletionQueue,
    IND2QueuePair* const pQueuePair,
    IND2Connector* const pConnector
)
{
    LOG_ENTER();
    void *buffer = malloc(params->size);
    LOG("malloc %u -> %p", params->size, buffer);
    if (!buffer)
        throw EX_MALLOC;
    try
    {
        client_work1(
            params,
            pAddress,
            pAdapter,
            hOverlappedFile,
            pMemoryRegion,
            pInfo,
            pSendCompletionQueue,
            pRecvCompletionQueue,
            pQueuePair,
            pConnector,
            buffer
        );
    }
    catch (...)
    {
        free(buffer);
        LOG("free %p -> void", buffer);
        throw;
    }
    free(buffer);
    LOG("free %p -> void", buffer);
    LOG_VOID_RETURN();
}

void client(params_t* const params)
{
    work(params, client_work, get_local_client_address);
}
