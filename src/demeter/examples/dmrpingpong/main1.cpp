#include "pch.h"
#include "ndcommon.h"
#include "ndtestutil.h"
#include <logging.h>
#include <Logger.h>
#include <Winshim.h>
#include <WinHeap.h>
#include "Params.h"
#include "Utils.h"

class Ctxt {
public:
    static void* Recv;
    static void* Send;
    static void* Read;
    static void* Write;
};

void* Ctxt::Recv = (void*)0x1000;
void* Ctxt::Send = (void*)0x2000;
void* Ctxt::Read = (void*)0x3000;
void* Ctxt::Write = (void*)0x4000;

typedef struct _PeerInfo 
{
    UINT32 m_remoteToken;
    UINT64 m_remoteAddress;
} PeerInfo;

int write_PeerInfo(char* const buffer, size_t buffer_size, const PeerInfo& info)
{
    const char* const fmt =
        "{\n"
        "  \"m_remoteToken\": %u,\n"
        "  \"m_remoteAddress\": %zu\n"
        "}";
    return
        snprintf(
            buffer,
            buffer_size,
            fmt,
            info.m_remoteToken,
            info.m_remoteAddress
        );
}

void print_PeerInfo(FILE *file, const PeerInfo& info)
{
    char buffer[256];
    write_PeerInfo(buffer, sizeof(buffer), info);
    fprintf(file, "%s\n", buffer);
}

static struct sockaddr_in GetPlainSocketAddress(const char* ip)
{
    LOG_ENTER();
    struct sockaddr_in ans = { 0 };
    int len = sizeof(ans);
    Win::WSAStringToAddressA((char*)ip, AF_INET, 0, (sockaddr*)&ans, &len);
    LOG_STRUCT_RETURN(struct sockaddr_in);
    return ans;
}

static struct sockaddr_in GetSocketAddress(const Params& params)
{
    LOG_ENTER();
    struct sockaddr_in ans = GetPlainSocketAddress(params.Ip);
    ans.sin_port = params.Port;
    LOG_STRUCT_RETURN(struct sockaddr_in);
    return ans;
}

#define LOG_PARAMS(X)                       \
{                                           \
    char temp[2048];                        \
    X.WriteToBuffer(temp, sizeof(temp));    \
    LOG("Params:\n%s", temp);               \
}

#define LOG_ADAPTER_INFO(X)                                                 \
{                                                                           \
    char temporary[1024];                                                   \
    int rc = Utils::write_adapter_info(temporary, sizeof(temporary), X);    \
    LOG(#X ":\n%s", temporary);                                             \
}

#define PLOG_PEERINFO(X, Y)                 \
{                                           \
    char buf[512];                          \
    fprintf(stdout, Y "\n");                \
    print_PeerInfo(stdout, X);              \
    write_PeerInfo(buf, sizeof(buf), X);    \
    LOG(#X ":\n%s", buf);                   \
}

#define PLOG_RESULT(X)                              \
{                                                   \
    char tbuf[512];                                 \
    Utils::write_result(tbuf, sizeof(tbuf), X);     \
    LOG(#X ":\n%s", tbuf);                          \
    printf(#X ":\n%s\n", tbuf);                     \
}

class Server : public NdTestServerBase
{
public:
    Server() {}
    ~Server() {}
    void Run(const Params& params);
    void RunWorker(const Params& params);
    void RunTest(const struct sockaddr_in& v4Src, DWORD queueDepth, DWORD nSge)
    {
        throw "Don't call this!";
    }
    ND2_ADAPTER_INFO GetAdapterInfo();
    ND2_RESULT WaitForCompletionAndCheckContext(void *expectedContext);
};

ND2_RESULT Server::WaitForCompletionAndCheckContext(void *expectedContext)
{
    LOG_ENTER();
    ND2_RESULT result = { 0 };
    WaitForCompletion([&expectedContext, &result](ND2_RESULT *pComp)
    {
        result = *pComp;
        if (ND_SUCCESS != pComp->Status)
        {
            LOG_ERROR_UNEQUAL(pComp->Status, ND_SUCCESS);
            LogIfErrorExit(pComp->Status, ND_SUCCESS, "Unexpected completion status", __LINE__);
        }
        if (expectedContext != pComp->RequestContext)
        {
            LOG_ERROR_RETURN();
            LogErrorExit("Unexpected completion\n", __LINE__);
        }
    }, true);
    LOG_STRUCT_RETURN(ND2_RESULT);
    return result;
}

class Client : public NdTestClientBase
{
public:
    Client() {}
    ~Client() {}
    void Run(const Params& params);
    void RunWorker(const Params& params, const struct sockaddr_in& v4Src, const struct sockaddr_in &v4Server);
    ND2_ADAPTER_INFO GetAdapterInfo();
    void RunTest(const struct sockaddr_in& v4Src, const struct sockaddr_in& v4Dst, DWORD queueDepth, DWORD nSge)
    {
        throw "Don't call this!";
    }
};

static size_t ServerPeerInfoOffset(const Params& params)
{
    return params.MaxXfer + params.HdrLen + sizeof(PeerInfo);
}

static size_t ClientPeerInfoOffset(const Params& params)
{
    return params.MaxXfer + params.HdrLen;
}

void Server::Run(const Params& params)
{
    LOG_ENTER();
    struct sockaddr_in v4Src = GetSocketAddress(params);
    NdTestBase::Init(v4Src);
    try
    {
        RunWorker(params);
    }
    catch (...)
    {
        NdTestBase::Shutdown();
        throw;
    }
    NdTestBase::Shutdown();
    LOG_VOID_RETURN();
}

void Server::RunWorker(const Params& params)
{
    LOG_ENTER();
    LOG_PARAMS(params);
    ND2_ADAPTER_INFO info = GetAdapterInfo();
    {
        char temporary[1024];
        int rc = Utils::write_adapter_info(temporary, sizeof(temporary), info);
        LOG("ND2_ADAPTER_INFO:\n%s", temporary);
    }
    NdTestBase::CreateCQ(info.MaxCompletionQueueDepth);
    NdTestBase::CreateConnector();
    {
        ULONG const u32QueueDepth = min(info.MaxCompletionQueueDepth, info.MaxInitiatorQueueDepth);
        ULONG const u32InlineThreshold = info.InlineRequestThreshold;
        ULONG const u32QueuePairDepth = min(u32QueueDepth, info.MaxReceiveQueueDepth);
        NdTestBase::CreateQueuePair(u32QueuePairDepth, (DWORD)params.nSge, u32InlineThreshold);
    }
    NdTestBase::CreateMR();
    HEAP heap(0, 0, 0);
    BUFFER<char> buffer(&heap, HEAP_ZERO_MEMORY, params.MaxXfer + params.HdrLen + 2 * sizeof(PeerInfo));
    PeerInfo* const pServerInfo = (PeerInfo*)(buffer + ServerPeerInfoOffset(params));
    PeerInfo* const pClientInfo = (PeerInfo*)(buffer + ClientPeerInfoOffset(params));
    {
        LOG("<- Register the data buffer ->");
        ULONG const flags = ND_MR_FLAG_ALLOW_LOCAL_WRITE | ND_MR_FLAG_ALLOW_REMOTE_WRITE;
        NdTestBase::RegisterDataBuffer(buffer, (DWORD)buffer.size(), flags);
    }
    {
        LOG("<- Post receive for peerInfo and terminate messages ->");
        ND2_SGE sge = { pClientInfo, sizeof(*pClientInfo), m_pMr->GetLocalToken() };
        NdTestBase::PostReceive(&sge, 1, Ctxt::Recv);
        NdTestBase::PostReceive(&sge, 1, Ctxt::Recv);
    }
    NdTestServerBase::CreateListener();
    NdTestServerBase::Listen(GetSocketAddress(params));
    NdTestServerBase::GetConnectionRequest();
    NdTestServerBase::Accept(0, 0);

    {
        LOG("<- Wait for incoming peer info message ->");
        printf("waiting for the arrival of the client's PeerInfo structure ...\n");
        ND2_RESULT result = WaitForCompletionAndCheckContext(Ctxt::Recv);
        PLOG_RESULT(result);
        PLOG_PEERINFO(*pClientInfo, "received client PeerInfo");
    }
    NdTestBase::CreateMW();
    NdTestBase::Bind(buffer, (DWORD)buffer.size(), ND_OP_FLAG_ALLOW_WRITE);
    {
        LOG("<- Send remote token and address ->");
        pServerInfo->m_remoteToken = m_pMw->GetRemoteToken();
        pServerInfo->m_remoteAddress = (UINT64)((char*)buffer);
        ND2_SGE sge = { pServerInfo, sizeof(*pServerInfo), m_pMr->GetLocalToken() };
        printf("\nsending Server Peerinfo ... (ctxt = %p)\n", Ctxt::Send);
        NdTestBase::Send(&sge, 1, 0, Ctxt::Send);
        printf("sent Server's PeerInfo structure\n");
        print_PeerInfo(stdout, *pServerInfo);
        LOG("<- Waiting to complete the sending of the server PeerInfo data ->");
        printf("waiting on the completion of the send ...\n");
        ND2_RESULT result = WaitForCompletionAndCheckContext(Ctxt::Send);
        {
            char buf[512];
            Utils::write_result(buf, sizeof(buf), result);
            printf("send has been complted and this is the result ...\nND2_RESULT:\n%s\n", buf);
        }
        {
            char buf[512];
            write_PeerInfo(buf, sizeof(buf), *pServerInfo);
            LOG("sent server PeerInfo:\n%s", buf);
        }
    }
    {
        printf("\nwaiting for the terminatation message ...\n");
        ND2_RESULT result = WaitForCompletionAndCheckContext(Ctxt::Recv);
        {
            char buf[512];
            Utils::write_result(buf, sizeof(buf), result);
            printf("ND2_RESULT:\n%s\n", buf);
        }
    }
    LOG_VOID_RETURN();
}

ND2_ADAPTER_INFO Server::GetAdapterInfo()
{
    LOG_ENTER();
    ND2_ADAPTER_INFO info = { 0 };
    NdTestBase::GetAdapterInfo(&info);
    if ((info.AdapterFlags & ND_ADAPTER_FLAG_IN_ORDER_DMA_SUPPORTED) == 0)
    {
        throw "Adapter does not support RDMA";
    }
    LOG_STRUCT_RETURN(ND2_ADAPTER_INFO);
    return info;
}

ND2_ADAPTER_INFO Client::GetAdapterInfo()
{
    LOG_ENTER();
    ND2_ADAPTER_INFO info = { 0 };
    NdTestBase::GetAdapterInfo(&info);
    if ((info.AdapterFlags & ND_ADAPTER_FLAG_IN_ORDER_DMA_SUPPORTED) == 0)
    {
        throw "Adapter does not support RDMA";
    }
    LOG_STRUCT_RETURN(ND2_ADAPTER_INFO);
    return info;
}

void Client::Run(const Params& params)
{
    LOG_ENTER();
    struct sockaddr_in v4Server = GetSocketAddress(params);
    struct sockaddr_in v4Src = { 0 };
    size_t len = sizeof(v4Src);
    HRESULT hr = NdResolveAddress((const struct sockaddr*)&v4Server, sizeof(v4Server), (struct sockaddr*)&v4Src, &len);
    if (FAILED(hr))
    {
        throw "NdResovleAddress failed";
    }
    NdTestBase::Init(v4Src);
    try
    {
        RunWorker(params, v4Src, v4Server);
    }
    catch (...)
    {
        NdTestBase::Shutdown();
        throw;
    }
    NdTestBase::Shutdown();
    LOG_VOID_RETURN();
}

void Client::RunWorker(const Params& params, const struct sockaddr_in& v4Src, const struct sockaddr_in &v4Server)
{
    LOG_ENTER();
    LOG_PARAMS(params);
    NdTestBase::CreateMR();
    HEAP heap(0, 0, 0);
    BUFFER<char> buffer(&heap, HEAP_ZERO_MEMORY, params.MaxXfer + params.HdrLen + 2 * sizeof(PeerInfo));
    PeerInfo* const pServerInfo = (PeerInfo*)(buffer + ServerPeerInfoOffset(params));
    PeerInfo* const pClientInfo = (PeerInfo*)(buffer + ClientPeerInfoOffset(params));
    {
        ULONG const flags = ND_MR_FLAG_ALLOW_LOCAL_WRITE | ND_MR_FLAG_ALLOW_REMOTE_WRITE;
        NdTestBase::RegisterDataBuffer(buffer, (DWORD)buffer.size(), flags);
    }
    {
        ND2_ADAPTER_INFO info = GetAdapterInfo();
        LOG_ADAPTER_INFO(info);
        ULONG const queueDepth = min(info.MaxCompletionQueueDepth, info.MaxInitiatorQueueDepth);
        ULONG const nMaxSge = min((ULONG)params.nSge, info.MaxInitiatorSge);
        ULONG const inlineThreshold = info.InlineRequestThreshold;
        NdTestBase::CreateCQ(queueDepth);
        NdTestBase::CreateConnector();
        NdTestBase::CreateQueuePair(min(queueDepth, info.MaxReceiveQueueDepth), (DWORD)params.nSge, inlineThreshold);
    }
    
    LOG("<- Post receive for PeerInfo message ->");
    {
        ND2_SGE sge = { pServerInfo, sizeof(*pServerInfo), m_pMr->GetLocalToken() };
        NdTestBase::PostReceive(&sge, 1, Ctxt::Recv);
    }

    NdTestClientBase::Connect(v4Src, v4Server, 0, 0);
    NdTestClientBase::CompleteConnect();
    NdTestBase::CreateMW();
    NdTestBase::Bind(buffer, (DWORD)buffer.size(), ND_OP_FLAG_ALLOW_WRITE);

    {
        LOG("<- Send client remote token and address to the server ->");
        pClientInfo->m_remoteToken = m_pMw->GetRemoteToken();
        pClientInfo->m_remoteAddress = (UINT64)((char*)buffer);

        ND2_SGE sge = { pClientInfo, sizeof(*pClientInfo), m_pMr->GetLocalToken() };
        DWORD const count = 1;
        DWORD const flags = 0;
        printf("\nsending client Peerinfo to the server (ctxt = %p)...\n", Ctxt::Send);
        NdTestBase::Send(&sge, count, flags, Ctxt::Send);
        PLOG_PEERINFO(*pClientInfo, "sent client PeerInfo asynchronously ...")
        LOG("<- Wait for send completion and incomming peer info message ->");
        printf("\nwaiting on the completion of either the send or the receive ...\n");
        bool gotSendCompletion = false;
        bool gotPeerInfoMsg = false;
        while (!(gotSendCompletion && gotPeerInfoMsg))
        {
            WaitForCompletion([&gotSendCompletion, &gotPeerInfoMsg, &pServerInfo](ND2_RESULT *pCompletion)
            {
                printf("\n");
                PLOG_RESULT(*pCompletion);
                void* ctxt = pCompletion->RequestContext;
                if (ctxt == Ctxt::Send)
                {
                    printf("the send was successful\n");
                    gotSendCompletion = true;
                }
                else if (ctxt == Ctxt::Recv)
                {
                    printf("the receive was successful\n");
                    gotPeerInfoMsg = true;
                    PLOG_PEERINFO(*pServerInfo, "received server PeerInfo");
                }
                else
                {
                    LOG("<- Unexpected Context ->");
                    throw "Unexpected Context";
                }
            }, true);
        }
    }
    {
        LOG("<- Send terminate message ->");
        printf("\nSending the terminate message ...\n");
        NdTestBase::Send(nullptr, 0, 0);
        WaitForCompletion([](ND2_RESULT *pCompletion)
        {
            PLOG_RESULT(*pCompletion);
        }, true);

    }
    LOG_VOID_RETURN();
}

void main1(Params& params)
{
    printf("Version: %zu\n", params.Version);
    LOG_ENTER();
    if (params.Server) 
    {
        Server server;
        server.Run(params);
    }
    else if (params.Client)
    {
        Client client;
        client.Run(params);
    }
    LOG_VOID_RETURN();
}
