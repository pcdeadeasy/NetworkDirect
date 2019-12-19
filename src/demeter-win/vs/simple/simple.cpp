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
#include <libraries/Utils/Utils.h>


void reverse(void* pv, size_t size)
{
    uint8_t* bytes = (uint8_t*)pv;
    size_t i = 0;
    size_t j = size - 1;
    while (i < j)
    {
        uint8_t t = bytes[i];
        bytes[i] = bytes[j];
        bytes[j] = t;
        i++;
        j--;
    }
}

uint32_t get_dword(const void* Blob)
{
    uint32_t ans;
    memcpy(&ans, Blob, sizeof(ans));
    reverse(&ans, sizeof(ans));
    return ans;
}

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
        if (ND_SUCCESS != hr)
        {
            if (ND_PENDING != hr)
                throw EX_NOTIFY;
            NDSPI::Wait(S->pCompletionQueue, &S->ov);
        }
    }
    fprintf(stderr, "The completion queue has a result!\n");
    fprintf(stderr, "RequestContext: \"%s\"\n", (char*)result.RequestContext);

    char buffer[4048];
    Utils::hexdumptostring(buffer, sizeof(buffer), sge.Buffer, result.BytesTransferred);
    fprintf(stderr, "\nreceived %u bytes:\n%s", result.BytesTransferred, buffer);

    const uint8_t* Blob = (const uint8_t*)sge.Buffer;

    fprintf(stderr, "\n");
    fprintf(stderr, "h_magic:    %08X\n", get_dword(&Blob[0]));
    fprintf(stderr, "h_bytes:    %08X\n", get_dword(&Blob[4]));
    fprintf(stderr, "h_sgasegs:  %08X\n", get_dword(&Blob[8]));
    fprintf(stderr, "lengths[0]: %08X\n", get_dword(&Blob[12]));
    fprintf(stderr, "lengths[1]: %08X\n", get_dword(&Blob[16]));
    fprintf(stderr, "lengths[2]: %08X\n", get_dword(&Blob[20]));

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
    NDSPI::AcceptAndWait(S->pConnector,
                         S->pQueuePair,
                         S->Info.MaxInboundReadLimit,
                         0);
    fprintf(stderr, "connection accepted\n");
    S->buffer = NDSPI::Alloc(params->size);
    S->buffer_size = params->size;
    NDSPI::RegisterMemoryAndWait(S->pMemoryRegion, S->buffer, S->buffer_size);

    {
        char header[] =
            "\x10\x10\x20\x10" // h_magic
            "\x00\x00\x00\x16" // h_bytes
            "\x00\x00\x00\x01" // h_sgasegs
            "\x00\x00\x00\x16" // length 0
            "\x00\x00\x00\x00" // length 1
            "\x00\x00\x00"     // length 2 (terminating null has been appended)
            ;

        char data[] = "hello from the client"; // terminating null has been appended

        char* dst = (char*)S->buffer;
        void* dst0 = &dst[0];
        void* dst1 = &dst[sizeof(header)];
        memcpy(dst0, header, sizeof(header));
        memcpy(dst1, data, sizeof(data));

        ND2_SGE sges[2];
        sges[0].Buffer = dst0;
        sges[0].BufferLength = (ULONG)sizeof(header);
        sges[0].MemoryRegionToken = NDSPI::GetLocalToken(S->pMemoryRegion);
        sges[1].Buffer = dst1;
        sges[1].BufferLength = (ULONG)sizeof(data);
        sges[1].MemoryRegionToken = NDSPI::GetLocalToken(S->pMemoryRegion);


        fprintf(stderr, "sizeof(header): %zX\n", sizeof(header));
        fprintf(stderr, "sizeof(data): %zX\n", sizeof(data));
        void* const context = (void*)"server context";
        NDSPI::Send(S->pQueuePair, context, sges, 2, 0);
    }

    // Wait for send result
    ND2_RESULT result;
    while (true)
    {
        if (NDSPI::GetResults(S->pCompletionQueue, &result, 1) == 1)
            break;
        HRESULT hr = NDSPI::Notify(S->pCompletionQueue,
                                   ND_CQ_NOTIFY_ANY,
                                   S->ov);
        if (ND_PENDING == hr)
        {
            NDSPI::Wait(S->pCompletionQueue, &S->ov);
        }
    }
    fprintf(stderr, "The completion queue has a result!\n");
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
        fprintf(stderr, "exception %d was caught: \"%s\"\n", i, errors::get_string(i));
    }
    catch (...)
    {
        fprintf(stderr, "uncaught exception");
    }
}
