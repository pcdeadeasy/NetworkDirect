#define INITGUID

#include <stdio.h>
#include <libraries/logger/Logger.h>
#include <libraries/Winshim/Winshim.h>
#include <libraries/ndutil/ndutil.h>
#include <libraries/ndutil/ndtestutil.h>
#include "params.h"
#include "ndscope.h"
#include "errors.h"
//#include "work.h"
//#include "client.h"
//#include "server.h"
#include "State.h"
#include "ndspi.h"

uint32_t get_client_cq_depth(uint32_t queueDepth, const ND2_ADAPTER_INFO& info)
{
    LOG_ENTER();
    uint32_t ans = (queueDepth > 0) ? min(queueDepth, info.MaxCompletionQueueDepth) : info.MaxCompletionQueueDepth;
    ans = min(ans, info.MaxInitiatorQueueDepth);
    LOG_ULONG_RETURN(ans);
    return ans;
}

void client(params_t* const params, State* const state)
{
    LOG_ENTER();
    state->RemoteAddress = NDSPI::GetSocketAddress(params->ip.c_str(), params->port);
    state->LocalAddress = NDSPI::ResolveAddress(state->RemoteAddress);
    //++ init
    state->pAdapter = NDSPI::OpenAdapter(state->LocalAddress);
    state->ov.hEvent = NDSPI::CreateOverlappedEvent();
    state->hOverlappedFile = NDSPI::CreateOverlappedFile(state->pAdapter);
    //-- init
    state->Info = NDSPI::GetAdapterInfo(state->pAdapter);
    state->pMemoryRegion = NDSPI::CreateMemoryRegion(state->pAdapter, state->hOverlappedFile);
    uint32_t const cq_depth = get_client_cq_depth(params->queue_depth, state->Info);
    state->pCompletionQueue = NDSPI::CreateCompletionQueue(state->pAdapter, state->hOverlappedFile, cq_depth);
    state->pConnector = NDSPI::CreateConnector(state->pAdapter, state->hOverlappedFile);
    uint32_t const qp_depth = min(cq_depth, state->Info.MaxReceiveQueueDepth);
    state->pQueuePair = NDSPI::CreateQueuePair(state->pAdapter, state->pCompletionQueue, qp_depth, state->Info.InlineRequestThreshold, params->nsge);

    state->buffer = NDSPI::Alloc(params->size);
    state->buffer_size = params->size;
    NDSPI::RegisterMemoryAndWait(state->pMemoryRegion, state->buffer, state->buffer_size);

    ND2_SGE sge = { 0 };
    sge.Buffer = state->buffer;
    sge.BufferLength = (ULONG)state->buffer_size;
    sge.MemoryRegionToken = NDSPI::GetLocalToken(state->pMemoryRegion);
    NDSPI::Receive(state->pQueuePair, (void*)"receive context", &sge, 1);

    NDSPI::ConnectorBind(state->pConnector, state->LocalAddress);
    NDSPI::ConnectAndWait(state->pConnector, state->pQueuePair, state->RemoteAddress);
    NDSPI::CompleteConnectAndWait(state->pConnector);

    // Wait for receive result
    ND2_RESULT result;
    while (true)
    {
        if (NDSPI::GetResults(state->pCompletionQueue, &result, 1) == 1)
            break;
        if (ND_PENDING == NDSPI::Notify(state->pCompletionQueue, ND_CQ_NOTIFY_ANY, state->ov))
        {
            // WARNING WARNING WARNING THIS WILL BLOCK because the second argument is TRUE
            HRESULT hr = state->pCompletionQueue->GetOverlappedResult(&state->ov, TRUE);
            LOG("IND2CompletionQueue::GetOverlappedResult %p -> %08X", state->pCompletionQueue, hr);
        }
    }
    fprintf(stderr, "received: \"%s\"\n", sge.Buffer);

    LOG_VOID_RETURN();
}

void server(params_t* const params, State* const state)
{
    LOG_ENTER();
    state->LocalAddress = NDSPI::GetSocketAddress(params->ip.c_str(), params->port);
    //++ init
    state->pAdapter = NDSPI::OpenAdapter(state->LocalAddress);
    state->ov.hEvent = NDSPI::CreateOverlappedEvent();
    state->hOverlappedFile = NDSPI::CreateOverlappedFile(state->pAdapter);
    //-- init
    state->Info = NDSPI::GetAdapterInfo(state->pAdapter);
    state->pCompletionQueue = NDSPI::CreateCompletionQueue(state->pAdapter, state->hOverlappedFile, state->Info.MaxInitiatorQueueDepth);
    state->pConnector = NDSPI::CreateConnector(state->pAdapter, state->hOverlappedFile);
    state->pMemoryRegion = NDSPI::CreateMemoryRegion(state->pAdapter, state->hOverlappedFile);

    uint32_t depth = min(state->Info.MaxCompletionQueueDepth, state->Info.MaxReceiveQueueDepth);
    state->pQueuePair = NDSPI::CreateQueuePair(state->pAdapter, state->pCompletionQueue, depth, 0, params->nsge);
    state->pListener = NDSPI::CreateListener(state->pAdapter, state->hOverlappedFile);
    NDSPI::ListenerBind(state->pListener, state->LocalAddress);
    NDSPI::Listen(state->pListener, 0);
    NDSPI::GetConnectionRequestAndWait(state->pListener, state->pConnector);
    NDSPI::AcceptAndWait(state->pConnector, state->pQueuePair, state->Info.MaxInboundReadLimit, 0);

    state->buffer = NDSPI::Alloc(params->size);
    state->buffer_size = params->size;
    NDSPI::RegisterMemoryAndWait(state->pMemoryRegion, state->buffer, state->buffer_size);

    int size = sprintf_s((char*)state->buffer, state->buffer_size, "hello from the server") + 1;
    ND2_SGE sge;
    sge.Buffer = state->buffer;
    sge.BufferLength = size;
    sge.MemoryRegionToken = NDSPI::GetLocalToken(state->pMemoryRegion);

    fprintf(stderr, "sending: \"%s\"\n", sge.Buffer);
    NDSPI::Send(state->pQueuePair, (void*)"server context", &sge, 1, 0);

    // Wait for send result
    ND2_RESULT result;
    while (true)
    {
        if (NDSPI::GetResults(state->pCompletionQueue, &result, 1) == 1)
            break;
        if (ND_PENDING == NDSPI::Notify(state->pCompletionQueue, ND_CQ_NOTIFY_ANY, state->ov))
        {
            // WARNING WARNING WARNING THIS WILL BLOCK because the second argument is TRUE
            HRESULT hr = state->pCompletionQueue->GetOverlappedResult(&state->ov, TRUE);
            LOG("IND2CompletionQueue::GetOverlappedResult %p -> %08X", state->pCompletionQueue, hr);
        }
    }
    LOG_VOID_RETURN();
}

void run(params_t* const params, State* const state)
{
    LOG_ENTER();
    if (params->role == "client")
        client(params, state);
    else if (params->role == "server")
        server(params, state);
    else
        throw EX_INVALID_ROLE;
    LOG_VOID_RETURN();
}

int main(int argc, char* argv[])
{
    try
    {
        params_t params = get_params(argc, argv);
        Logger logger("log.json");
        LOG_ENTER();
        WsaScope wsaScope;
        NdScope ndScope;
        State state;
        run(&params, &state);
        LOG_INT_RETURN(0);
    }
    catch (int i)
    {
        fprintf(stderr, "exception %d was caught", i);
    }
    catch (...)
    {
        fprintf(stderr, "uncaught exception");
    }
}
