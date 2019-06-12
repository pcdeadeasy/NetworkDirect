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

void print_PeerInfo(FILE *file, const PeerInfo& info)
{
    fprintf(file, "{\n");
    fprintf(file, "  \"m_remoteToken\": %u,\n", info.m_remoteToken);
    fprintf(file, "  \"m_remoteAddress\": %zu\n", info.m_remoteAddress);
    fprintf(file, "}\n");
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
};

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
        WaitForCompletionAndCheckContext(Ctxt::Recv);
        printf("\nReceived Client PeerInfo:\n");
        print_PeerInfo(stdout, *pClientInfo);
    }
    NdTestBase::CreateMW();
    NdTestBase::Bind(buffer, (DWORD)buffer.size(), ND_OP_FLAG_ALLOW_WRITE);
    {
        LOG("<- Send remote token and address ->");
        pServerInfo->m_remoteToken = m_pMw->GetRemoteToken();
        pServerInfo->m_remoteAddress = (UINT64)((char*)buffer);
        ND2_SGE sge = { pServerInfo, sizeof(*pServerInfo), m_pMr->GetLocalToken() };
        NdTestBase::Send(&sge, 1, 0, Ctxt::Send);
        LOG("<- Waiting to complete the sending of the server PeerInfo data ->");
        WaitForCompletionAndCheckContext(Ctxt::Send);
        printf("\nSent Server PeerInfo:\n");
        print_PeerInfo(stdout, *pServerInfo);
        printf("\n");
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
        {
            char temporary[1024];
            int rc = Utils::write_adapter_info(temporary, sizeof(temporary), info);
            LOG("ND2_ADAPTER_INFO:\n%s", temporary);
        }
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
        NdTestBase::Send(&sge, count, flags, Ctxt::Send);
        fprintf(stdout, "\nSent Client PeerInfo:\n");
        print_PeerInfo(stdout, *pClientInfo);
    }
    {
        LOG("<- Wait for send completion and incomming peer info message ->");
        bool gotSendCompletion = false;
        bool gotPeerInfoMsg = false;
        while (!(gotSendCompletion && gotPeerInfoMsg))
        {
            WaitForCompletion([&gotSendCompletion, &gotPeerInfoMsg, &pServerInfo](ND2_RESULT *pCompletion)
            {
                printf("\nND2_RESULT:\n");
                Utils::print_result(stdout, *pCompletion);
                void* ctxt = pCompletion->RequestContext;
                if (ctxt == Ctxt::Send)
                {
                    gotSendCompletion = true;
                }
                else if (ctxt == Ctxt::Recv)
                {
                    gotPeerInfoMsg = true;
                    printf("\nReceived Server PeerInfo\n");
                    print_PeerInfo(stdout, *pServerInfo);
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
        NdTestBase::Send(nullptr, 0, 0);
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
