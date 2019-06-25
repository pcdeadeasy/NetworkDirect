#include "pch.h"
#include "../../libraries/logger/Logger.h"
#include "../../libraries/Winshim/WinHeap.h"
#include "Client.h"
#include "ctxt.h"
#include "PeerInfo.h"

Client::Client(Params &params) : m_params(params), m_availCredits(0)
{
    LOG_ENTER();
    LOG_VOID_RETURN();
}

Client::~Client()
{
    LOG_ENTER();
    LOG_VOID_RETURN();
}

static void print_address(const struct sockaddr_in& addr, const char *name)
{
    char buffer[100];
    DWORD dwAddressStringLength;
    dwAddressStringLength = (DWORD)sizeof(buffer);
    Win::WSAAddressToStringA((LPSOCKADDR)&addr, (DWORD)sizeof(addr), 0, buffer, &dwAddressStringLength);
    printf("%s: %s\n", name, buffer);
}

void Client::RunTest(const struct sockaddr_in &v4Src, const struct sockaddr_in &v4Dst, DWORD queueDepth, DWORD nSge)
{
    LOG_ENTER();
    NdTestBase::Init(v4Src);
    try
    {
        Work(v4Src, v4Dst, queueDepth, nSge);
    }
    catch (...)
    {
        NdTestBase::Shutdown();
        LOG_ERROR_RETURN();
        throw;
    }
    NdTestBase::Shutdown();
    LOG_VOID_RETURN();
}

static ULONG get_register_data_buffer_flags(Params const &params)
{
    LOG_ENTER();
    ULONG ans;
    if (params.Read)
    {
        ans = ND_MR_FLAG_ALLOW_LOCAL_WRITE | ND_MR_FLAG_RDMA_READ_SINK;
    }
    else if (params.Write)
    {
        ans = ND_MR_FLAG_ALLOW_LOCAL_WRITE;
    }
    else
    {
        ans = 0;
    }
    LOG_ULONG_RETURN(ans);
    return ans;
}

static void make_sure_adapter_supports_in_order_rdma(ND2_ADAPTER_INFO const &info)
{
    LOG_ENTER();
    if ((info.AdapterFlags & ND_ADAPTER_FLAG_IN_ORDER_DMA_SUPPORTED) == 0)
    {
        LOG_ERROR_RETURN();
        throw "Adapter does not support in-order RDMA";
    }
    LOG_VOID_RETURN();
}

typedef struct _CONSTANTS {
    ULONG queueDepth;
    ULONG nMaxSge;
    ULONG inlineThreshold;
    ULONG queuePairDepth;
} CONSTANTS;

static const CONSTANTS get_constants(Params const &params, ND2_ADAPTER_INFO const &info, ULONG queueDepth, ULONG nSge)
{
    LOG_ENTER();
    CONSTANTS ans = { 0 };
    ans.queueDepth = (queueDepth > 0) ? min(queueDepth, info.MaxCompletionQueueDepth) : info.MaxCompletionQueueDepth;
    ans.queueDepth = min(ans.queueDepth, info.MaxInitiatorQueueDepth);
    ans.nMaxSge = min(nSge, info.MaxInitiatorSge);
    ans.inlineThreshold = info.InlineRequestThreshold;
    if (params.Read)
    {
        ans.queueDepth = min(ans.queueDepth, info.MaxOutboundReadLimit);
        ans.nMaxSge = min(nSge, info.MaxReadSge);
    }
    ans.queuePairDepth = min(ans.queueDepth, info.MaxReceiveQueueDepth);
    LOG_STRUCT_RETURN(CONSTANTS);
    return ans;
}

void Client::register_data_buffer(BUFFER<char> &buf)
{
    LOG_ENTER();
    ULONG const flags = get_register_data_buffer_flags(m_params);
    NdTestBase::RegisterDataBuffer(buf, (DWORD)buf.size(), flags);
    LOG_VOID_RETURN();
}

ND2_ADAPTER_INFO const Client::get_adapter_info()
{
    LOG_ENTER();
    ND2_ADAPTER_INFO info = { 0 };
    NdTestBase::GetAdapterInfo(&info);
    LOG_STRUCT_RETURN(ND2_ADAPTER_INFO);
    return info;
}

void Client::post_receive(BUFFER<char> &buf)
{
    LOG_ENTER();
    ND2_SGE sge = { 0 };
    sge.Buffer = buf;
    sge.BufferLength = (ULONG)buf.size();
    sge.MemoryRegionToken = m_pMr->GetLocalToken();
    LOG("IND2MemoryRegion::GetLocalToken -> %08X", sge.MemoryRegionToken);
    NdTestBase::PostReceive(&sge, 1, RECV_CTXT);
    LOG_VOID_RETURN();
}

void Client::Work(const struct sockaddr_in& v4Src, const struct sockaddr_in &v4Dst, DWORD queueDepth, DWORD nSge)
{
    LOG_ENTER();
    HEAP heap(0, 0, 0);
    BUFFER<char> buf(&heap, HEAP_ZERO_MEMORY, m_params.MaxXfer + m_params.HdrLen);
    ND2_ADAPTER_INFO const info = get_adapter_info();
    CONSTANTS const constants = get_constants(m_params, info, queueDepth, nSge);
    BUFFER<ND2_SGE> sges(&heap, HEAP_ZERO_MEMORY, constants.nMaxSge);
    NdTestBase::CreateMR();
    register_data_buffer(buf);
    NdTestBase::CreateCQ(constants.queueDepth);
    NdTestBase::CreateConnector();
    NdTestBase::CreateQueuePair(constants.queuePairDepth, nSge, constants.inlineThreshold);
    post_receive(buf);
    NdTestClientBase::Connect(v4Src, v4Dst, 0, m_params.Read ? constants.queueDepth : 0);
    NdTestClientBase::CompleteConnect();
    WaitForCompletionAndCheckContext(RECV_CTXT);

    PeerInfo *pInfo = (PeerInfo*)((void*)buf);
    print_peerinfo(*pInfo, stdout);
    send_terminate_message();

    LOG_VOID_RETURN();
}

void Client::send_terminate_message()
{
    LOG_ENTER();
    NdTestBase::Send(nullptr, 0, 0);
    WaitForCompletion();
    LOG_VOID_RETURN();
}
