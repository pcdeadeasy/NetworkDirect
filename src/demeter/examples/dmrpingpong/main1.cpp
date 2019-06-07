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
    BUFFER<ND2_SGE> sges(&heap, HEAP_ZERO_MEMORY, (ULONG)min(params.nSge, info.MaxInitiatorSge));
    {
        ULONG const flags = ND_MR_FLAG_ALLOW_LOCAL_WRITE | ND_MR_FLAG_ALLOW_REMOTE_WRITE;
        NdTestBase::RegisterDataBuffer(buffer, (DWORD)buffer.size(), flags);
    }
    {
        ND2_SGE sge = { buffer + params.MaxXfer + params.HdrLen, sizeof(PeerInfo), m_pMr->GetLocalToken() };
        NdTestBase::PostReceive(&sge, 1, Ctxt::Recv);
        NdTestBase::PostReceive(&sge, 1, Ctxt::Recv);
    }
    NdTestServerBase::CreateListener();
    {
        const struct sockaddr_in v4Src = GetSocketAddress(params);
        NdTestServerBase::Listen(v4Src);
    }
    NdTestServerBase::GetConnectionRequest();
    NdTestServerBase::Accept(0, 0);

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
    BUFFER<ND2_SGE> sges(&heap, HEAP_ZERO_MEMORY, 2);
    {
        ULONG const flags = ND_MR_FLAG_ALLOW_LOCAL_WRITE | ND_MR_FLAG_ALLOW_REMOTE_WRITE;
        NdTestBase::RegisterDataBuffer(buffer, (DWORD)buffer.size(), flags);
    }
    {
        ND2_ADAPTER_INFO info = GetAdapterInfo();
        Utils::print_info(stdout, info);
        ULONG const queueDepth = min(info.MaxCompletionQueueDepth, info.MaxInitiatorQueueDepth);
        ULONG const nMaxSge = min((ULONG)params.nSge, info.MaxInitiatorSge);
        ULONG const inlineThreshold = info.InlineRequestThreshold;
        NdTestBase::CreateCQ(queueDepth);
        NdTestBase::CreateConnector();
        NdTestBase::CreateQueuePair(min(queueDepth, info.MaxReceiveQueueDepth), (DWORD)params.nSge, inlineThreshold);
    }
    
    LOG("post receive for PeerInfo message");
    {
        PeerInfo *pInfo = (PeerInfo*)(buffer + params.MaxXfer + params.HdrLen);
        ND2_SGE sge = { pInfo, sizeof(PeerInfo), m_pMr->GetLocalToken() };

        fprintf(stdout, "\nPeerInfo located at %p before the send:\n", pInfo);
        print_PeerInfo(stdout, *pInfo);
        Utils::hexdumptofile(stdout, pInfo, sizeof(*pInfo));
        fprintf(stdout, "\nPostReceive\nND2_SGE:\n");
        Utils::print_sge(stdout, sge);
        NdTestBase::PostReceive(&sge, 1, Ctxt::Recv);
    }

    NdTestClientBase::Connect(v4Src, v4Server, 0, 0);
    NdTestClientBase::CompleteConnect();
    NdTestBase::CreateMW();
    NdTestBase::Bind(buffer, (DWORD)buffer.size(), ND_OP_FLAG_ALLOW_WRITE);

    {
        LOG("send remote token and address");
        size_t const offset = params.MaxXfer + params.HdrLen + sizeof(PeerInfo);
        PeerInfo *pPeerInfo = (PeerInfo*)(buffer + offset);
        PeerInfo& peerInfo = *pPeerInfo;
        peerInfo.m_remoteToken = m_pMw->GetRemoteToken();
        peerInfo.m_remoteAddress = (UINT64)((char*)buffer);

        fprintf(stdout, "\nsending PeerInfo:\n");
        print_PeerInfo(stdout, peerInfo);

        ND2_SGE sge = { &peerInfo, sizeof(peerInfo), m_pMr->GetLocalToken() };
        DWORD const count = 1;
        DWORD const flags = 0;

        fprintf(stdout, "\nSend\nND2_SGE:\n");
        Utils::print_sge(stdout, sge);
        NdTestBase::Send(&sge, count, flags, Ctxt::Send);
    }
    {
        LOG("wait for send completion and incomming peer info message");
        bool gotSendCompletion = false;
        bool gotPeerInfoMsg = false;
        while (!(gotSendCompletion && gotPeerInfoMsg))
        {
            WaitForCompletion([&gotSendCompletion, &gotPeerInfoMsg](ND2_RESULT *pCompletion)
            {
                Utils::print_result(stdout, *pCompletion);
                void* ctxt = pCompletion->RequestContext;
                if (ctxt == Ctxt::Send)
                {
                    gotSendCompletion = true;
                }
                else if (ctxt == Ctxt::Recv)
                {
                    gotPeerInfoMsg = true;
                }
                else
                {
                    LOG("Unexpected Context");
                    throw "Unexpected Context";
                }
            }, true);
        }
        {
            size_t const offset = params.MaxXfer + params.HdrLen;
            PeerInfo *pInfo = (PeerInfo*)(buffer + offset);
            printf("\nReceived PeerInfo\n");
            print_PeerInfo(stdout, *pInfo);
        }
    }



    LOG_VOID_RETURN();
}

void main1(Params& params)
{
    LOG_ENTER();
    params.Print(stdout);
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
