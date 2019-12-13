#define INITGUID

#include <stdio.h>
#include <libraries/logger/Logger.h>
#include <libraries/Winshim/Winshim.h>
#include <libraries/ndutil/ndutil.h>
#include <libraries/ndutil/ndtestutil.h>
#include "params.h"
#include "ndscope.h"
#include "errors.h"
#include "State.h"
#include "ndspi.h"

void client(params_t* const params, State* const state)
{
    LOG_ENTER();
    state->InitClient(
        params->ip.c_str(),
        params->port,
        params->queue_depth,
        params->size,
        params->nsge);

    ND2_SGE sge = { 
        state->buffer,
        (ULONG)state->buffer_size,
        NDSPI::GetLocalToken(state->pMemoryRegion)
    };
    fprintf(stderr, "initiating a receive\n");
    NDSPI::Receive(state->pQueuePair, (void*)"receive context", &sge, 1);

    NDSPI::ConnectorBind(state->pConnector, state->LocalAddress);
    fprintf(stderr, "connecting to server ...\n");
    NDSPI::ConnectAndWait(state->pConnector,
                         state->pQueuePair,
                         state->RemoteAddress);
    NDSPI::CompleteConnectAndWait(state->pConnector);
    fprintf(stderr, "connection completed\n");

    // Wait for receive result
    ND2_RESULT result;
    while (true)
    {
        if (NDSPI::GetResults(state->pCompletionQueue, &result, 1) == 1)
            break;
        HRESULT hr = NDSPI::Notify(state->pCompletionQueue,
                                   ND_CQ_NOTIFY_ANY,
                                   state->ov);
        if (ND_PENDING == hr)
        {
            //!!! WARNING THIS WILL BLOCK because the second argument is TRUE
            hr = state->pCompletionQueue->GetOverlappedResult(&state->ov, TRUE);
            LOG("IND2CompletionQueue::GetOverlappedResult %p -> %08X",
                state->pCompletionQueue,
                hr);
        }
    }
    fprintf(stderr, "received %u bytes: \"%s\"\n", result.BytesTransferred, (const char*)sge.Buffer);

    LOG_VOID_RETURN();
}

void server(params_t* const params, State* const state)
{
    LOG_ENTER();
    state->InitServer(
        params->ip.c_str(),
        params->port,
        params->queue_depth,
        params->size,
        params->nsge);

    fprintf(stderr, "waiting for a connection ...\n");
    NDSPI::GetConnectionRequestAndWait(state->pListener, 
                                       state->pConnector);
    NDSPI::AcceptAndWait(
        state->pConnector,
        state->pQueuePair,
        state->Info.MaxInboundReadLimit,
        0);
    fprintf(stderr, "connection accepted\n");
    state->buffer = NDSPI::Alloc(params->size);
    state->buffer_size = params->size;
    NDSPI::RegisterMemoryAndWait(
        state->pMemoryRegion,
        state->buffer,
        state->buffer_size);

    ULONG size = sprintf_s(
                (char*)state->buffer,
                state->buffer_size,
                "hello from the server") + 1;
    ND2_SGE 
        sge = { state->buffer, size, NDSPI::GetLocalToken(state->pMemoryRegion) };

    fprintf(stderr, "sending %u bytes: \"%s\"\n", size, (const char*)sge.Buffer);
    NDSPI::Send(state->pQueuePair, (void*)"server context", &sge, 1, 0);

    // Wait for send result
    ND2_RESULT result;
    while (true)
    {
        if (NDSPI::GetResults(state->pCompletionQueue, &result, 1) == 1)
            break;
        HRESULT hr = NDSPI::Notify(state->pCompletionQueue,
                                   ND_CQ_NOTIFY_ANY,
            state->ov);
        if (ND_PENDING == hr)
        {
            //!!! WARNING THIS WILL BLOCK because the second argument is TRUE
            hr = state->pCompletionQueue->GetOverlappedResult(&state->ov, TRUE);
            LOG("IND2CompletionQueue::GetOverlappedResult %p -> %08X",
                state->pCompletionQueue,
                hr);
        }
    }
    fprintf(stderr, "send complete");
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
