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

void client(params_t* const params, State* const S)
{
    LOG_ENTER();
    S->InitClient(
        params->ip.c_str(),
        params->port,
        params->queue_depth,
        params->size,
        params->nsge);

    uint32_t const LocalToken = NDSPI::GetLocalToken(S->pMemoryRegion);
    ND2_SGE sge = { S->buffer, (ULONG)S->buffer_size, LocalToken };
    fprintf(stderr, "start receive of up to %u bytes\n", sge.BufferLength);
    NDSPI::Receive(S->pQueuePair, (void*)"receive context", &sge, 1);

    NDSPI::ConnectorBind(S->pConnector, S->LocalAddress);
    fprintf(stderr, "connecting to server ...\n");
    NDSPI::ConnectAndWait(S->pConnector, S->pQueuePair, S->RemoteAddress);
    NDSPI::CompleteConnectAndWait(S->pConnector);
    fprintf(stderr, "connection completed\n");

    // Wait for receive result
    ND2_RESULT result;
    while (true)
    {
        if (NDSPI::GetResults(S->pCompletionQueue, &result, 1) == 1)
            break;
        HRESULT hr = 
            NDSPI::Notify(S->pCompletionQueue, ND_CQ_NOTIFY_ANY, S->ov);
        if (ND_PENDING == hr)
        {
            ///!!! THIS WILL BLOCK
            NDSPI::GetOverlappedResult(S->pCompletionQueue, &S->ov, TRUE);
        }
    }
    fprintf(stderr, "The completion queue has a result!\n");
    fprintf(stderr, "RequestContext: \"%s\"\n", (char*)result.RequestContext);
    const char* const fmt = "received %u bytes: \"%s\"\n";
    fprintf(stderr, fmt, result.BytesTransferred, (const char*)sge.Buffer);

    LOG_VOID_RETURN();
}

void server(params_t* const params, State* const S)
{
    LOG_ENTER();
    S->InitServer(
        params->ip.c_str(),
        params->port,
        params->queue_depth,
        params->size,
        params->nsge);

    fprintf(stderr, "waiting for a connection ...\n");
    NDSPI::GetConnectionRequestAndWait(S->pListener, S->pConnector);
    NDSPI::AcceptAndWait(
        S->pConnector,
        S->pQueuePair,
        S->Info.MaxInboundReadLimit,
        0);
    fprintf(stderr, "connection accepted\n");
    S->buffer = NDSPI::Alloc(params->size);
    S->buffer_size = params->size;
    NDSPI::RegisterMemoryAndWait(S->pMemoryRegion, S->buffer, S->buffer_size);

    const char* msg = "hello from the server";
    ULONG size = sprintf_s((char*)S->buffer, S->buffer_size, msg) + 1;
    ND2_SGE sge = { S->buffer, size, NDSPI::GetLocalToken(S->pMemoryRegion) };

    fprintf(stderr, "sending %u bytes: \"%s\"\n", size, (const char*)sge.Buffer);

    void* const context = (void*)"server context";
    NDSPI::Send(S->pQueuePair, context, &sge, 1, 0);

    // Wait for send result
    ND2_RESULT result;
    while (true)
    {
        if (NDSPI::GetResults(S->pCompletionQueue, &result, 1) == 1)
            break;
        HRESULT hr = 
            NDSPI::Notify(S->pCompletionQueue, ND_CQ_NOTIFY_ANY, S->ov);
        if (ND_PENDING == hr)
        {
            //!!! THIS WILL BLOCK
            NDSPI::GetOverlappedResult(S->pCompletionQueue, &S->ov, TRUE);
        }
    }
    fprintf(stderr, "The completion queue has a result!");
    fprintf(stderr, "RequestContext: \"%s\"\n", (char*)result.RequestContext);
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
