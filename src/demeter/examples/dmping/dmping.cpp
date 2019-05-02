#include "pch.h"
#include <stdio.h>
#include <Logger.h>
#include <Winshim.h>
#include <WinHeap.h>
#include <ndutil.h>
#include <ndcommon.h>
#include <ndtestutil.h>
#include "csv.h"

class NetworkDirectEnvironment
{
public:
    NetworkDirectEnvironment()
    {
		LOG_ENTER();
        if (FAILED(NdStartup()))
            throw Win::Error();
		LOG_VOID_RETURN();
    }

    ~NetworkDirectEnvironment()
    {
		LOG_ENTER();
        NdCleanup();
		LOG_VOID_RETURN();
    }
};

typedef enum _ROLE
{
	role_none,
	role_client,
	role_server
} ROLE;

typedef struct _PARAM_INPUT {
    int count;
    ROLE role;
    const char *ip;
    int port;
    int nSge;
    bool bPoling;
    bool bBlocking;
    SIZE_T nPipeline;
    SIZE_T MaxXfer;
    ULONG HdrLen;
    SIZE_T MaxVolume;
    SIZE_T MaxIterations;
} PARAM_INPUT;

static ROLE getrole(const char *val)
{
	ROLE ans = role_none;
	if (strcmp(val, "client") == 0)
		ans = role_client;
	else if (strcmp(val, "server") == 0)
		ans = role_server;
	return ans;
}

static PARAM_INPUT GetInputFromDict(CSV_DICT& dict)
{
    PARAM_INPUT ans = { 0 };
    ans.count = atoi(dict.lookup("count"));
    ans.role = getrole(dict.lookup("role"));
    ans.ip = dict.lookup("ip");
    ans.nSge = atoi(dict.lookup("nSge"));
    ans.port = atoi(dict.lookup("port"));
    ans.MaxXfer = (SIZE_T)atoll(dict.lookup("MaxXfer"));
    ans.HdrLen = (ULONG)atol(dict.lookup("HdrLen"));
    ans.MaxVolume = (SIZE_T)atoll(dict.lookup("MaxVolume"));
    ans.MaxIterations = (SIZE_T)atoll(dict.lookup("MaxIterations"));
    ans.nPipeline = (SIZE_T)atoll(dict.lookup("nPipeline"));
    ans.bBlocking = strcmp(dict.lookup("bBlocking"), "true") == 0;
    ans.bPoling = strcmp(dict.lookup("bPoling"), "true") == 0;
    return ans;
}

static PARAM_INPUT GetInput(HEAP &heap, const char *csv_file_path)
{
	CSV_DICT dict(heap, csv_file_path);
	return GetInputFromDict(dict);
}

static struct sockaddr_in GetServerAddress(const char *IpAddress)
{
    struct sockaddr_in ans = { 0 };
    int len = sizeof(ans);
    Win::WSAStringToAddressA((char*)IpAddress, AF_INET, 0, (sockaddr*)&ans, &len);
    return ans;
}

typedef struct _DEPTH_THRESHOLD {
	DWORD QueueDepth;
	DWORD InlineRequestThreshold;
} DEPTH_THRESHOLD;

class PingServer : public NdTestServerBase
{
public:
	PingServer(HEAP &heap, PARAM_INPUT &input);
	~PingServer();
	void RunTest(const struct sockaddr_in &v4Src, DWORD queueDepth, DWORD nSge);
private:
	HEAP &m_heap;
	PARAM_INPUT &m_input;

	static DWORD GetQueueDepth(DWORD queueDepth, ND2_ADAPTER_INFO const &info);
	DEPTH_THRESHOLD GetDepthThreshold(DWORD queueDepth);
    void PostReceives(BUFFER<ND2_SGE> &sgl, DWORD len, DWORD QueueDepth);
};

void PingServer::PostReceives(BUFFER<ND2_SGE> &sgl, DWORD len, DWORD QueueDepth)
{
    for (DWORD i = 0; i < QueueDepth; i++)
        NdTestBase::PostReceive(sgl, len);
}

DWORD PingServer::GetQueueDepth(DWORD queueDepth, ND2_ADAPTER_INFO const &info)
{
	DWORD ans = min(info.MaxCompletionQueueDepth, info.MaxReceiveQueueDepth);
	return queueDepth == 0 ? ans : min(queueDepth, ans);
}

DEPTH_THRESHOLD PingServer::GetDepthThreshold(DWORD queueDepth)
{
	DEPTH_THRESHOLD ans = { 0 };
	ND2_ADAPTER_INFO info = { 0 };
	NdTestBase::GetAdapterInfo(&info);
	ans.QueueDepth = GetQueueDepth(queueDepth, info);
	ans.InlineRequestThreshold = info.InlineRequestThreshold;
	return ans;
}

static void print_info(ND2_ADAPTER_INFO &info)
{
#define PU(X,Y) printf("  \"" #X "\": %" #Y ",\n", info.##X)
    printf("ND2_ADAPTER_INFO:\n");
	printf("{\n");
	PU(InfoVersion, u);
	PU(VendorId, u);
	PU(DeviceId, u);
	PU(AdapterId, zu);
	PU(MaxRegistrationSize, zu);
	PU(MaxWindowSize, zu);
	PU(MaxInitiatorSge, u);
	PU(MaxReceiveSge, u);
	PU(MaxReadSge, u);
	PU(MaxTransferLength, u);
	PU(MaxInlineDataSize, u);
	PU(MaxInboundReadLimit, u);
	PU(MaxOutboundReadLimit, u);
	PU(MaxReceiveQueueDepth, u);
	PU(MaxInitiatorQueueDepth, u);
	PU(MaxSharedReceiveQueueDepth, u);
	PU(MaxCompletionQueueDepth, u);
	PU(InlineRequestThreshold, u);
	PU(LargeRequestThreshold, u);
	PU(MaxCallerData, u);
	PU(MaxCalleeData, u);
	PU(AdapterFlags, u);
	printf("}\n");
#undef PU
}

void PingServer::RunTest(const struct sockaddr_in &v4Src, DWORD queueDepth, DWORD nSge)
{
	LOG_ENTER();
	BUFFER<char> buffer(&m_heap, HEAP_ZERO_MEMORY, m_input.MaxXfer + m_input.HdrLen);
	BUFFER<ND2_SGE> sgl(&m_heap, HEAP_ZERO_MEMORY, m_input.nSge);
	PingServer::Init(v4Src);
	NdTestBase::CreateMR();
	NdTestBase::RegisterDataBuffer(buffer, (DWORD)buffer.count(), ND_MR_FLAG_ALLOW_LOCAL_WRITE);
	DEPTH_THRESHOLD dth = GetDepthThreshold(queueDepth);
	NdTestBase::CreateCQ(dth.QueueDepth);
	NdTestBase::CreateConnector();
	NdTestBase::CreateQueuePair(dth.QueueDepth, m_input.nSge, dth.InlineRequestThreshold);
	NdTestServerBase::CreateListener();
	NdTestServerBase::Listen(v4Src);
	//NdTestServerBase::GetConnectionRequest();		// blocks waiting for connection
	DWORD NSge = NdTestBase::PrepareSge(sgl, (DWORD)sgl.count(), buffer, (DWORD)buffer.count(), m_input.HdrLen, m_pMr->GetLocalToken());
    //PostReceives(sgl, NSge, dth.QueueDepth);
    ULONG QueueDepthMinus1 = dth.QueueDepth - 1;
    //NdTestServerBase::Accept(0, 0, &QueueDepthMinus1, sizeof(QueueDepthMinus1));
	NdTestBase::Shutdown();
	LOG_VOID_RETURN();
}

PingServer::PingServer(HEAP &heap, PARAM_INPUT &input) : m_heap(heap), m_input(input)
{
	LOG_ENTER();
	LOG_VOID_RETURN();
}

PingServer::~PingServer()
{
	LOG_ENTER();
	LOG_VOID_RETURN();
}

static void test_server(HEAP &heap, PARAM_INPUT &input)
{
	LOG_ENTER();
	struct sockaddr_in v4Src = GetServerAddress(input.ip);
	v4Src.sin_port = input.port;
	PingServer server(heap, input);
	server.RunTest(v4Src, 0, input.nSge);
	LOG_VOID_RETURN();
}

static void test_client(HEAP &heap, PARAM_INPUT &input)
{
	LOG_ENTER();
	printf("client\n");
	BUFFER<char> buffer(&heap, HEAP_ZERO_MEMORY, input.MaxXfer + input.HdrLen);
	struct sockaddr_in v4Server = GetServerAddress(input.ip);
	LOG_VOID_RETURN();
}

static void work(const char *csv_file_path)
{
    LOG_ENTER();
    WsaScope wsa;                            // enable socket functions
	NetworkDirectEnvironment ndv;		// enable NetworkDirect stuff
    HEAP heap(0, 0, 0);                 // create the heap for memory allocations
    PARAM_INPUT input = GetInput(heap, csv_file_path);
	switch (input.role)
	{
	case role_client:
		test_client(heap, input);
		break;
	case role_server:
		test_server(heap, input);
		break;
	default:
		printf("set role to \"client\" or \"server\"\n");
		break;
	}
    LOG_VOID_RETURN();
}

int main(int arc, char* argv[])
{
    Logger logger("log.json");
    LOG_ENTER();
    int rc;
    try
    {
        work(argv[1]);
        rc = 0;
    }
    catch (char* msg)
    {
        fprintf(stderr, "%s\n", msg);
        rc = -1;
    }
    catch (...)
    {
        fprintf(stderr, "Unhandled exception");
        rc = -2;
    }
    LOG_INT_RETURN(rc);
    return rc;
}
