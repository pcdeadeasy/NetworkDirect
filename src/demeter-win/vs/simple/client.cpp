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
    struct sockaddr const RemoteAddress = (struct sockaddr)get_sockaddr(RemoteIpAddress, AF_INET, port);
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

static void client_work(
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
    LOG_VOID_RETURN();
}

void client(params_t* const params)
{
    work(params, client_work, get_local_client_address);
}
