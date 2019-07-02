#include "pch.h"
#include "../../libraries/logger/Logger.h"
#include "../../libraries/Winshim/WinHeap.h"
#include "../../libraries/Utils/Utils.h"
#include "Server.h"
#include "ctxt.h"
#include "PeerInfo.h"

static bool supports_in_order_dma(ND2_ADAPTER_INFO &info)
{
    return (info.AdapterFlags & ND_ADAPTER_FLAG_IN_ORDER_DMA_SUPPORTED) != 0;
}

static void check_in_order_dma_is_supported(ND2_ADAPTER_INFO &info)
{
    LOG_ENTER();
    if (!supports_in_order_dma(info))
    {
        LOG_ERROR_RETURN();
        throw "Card does not support in-order RDMA";
    }
    LOG_VOID_RETURN();
}

Server::Server(Params &params) : m_params(params)
{
    LOG_ENTER();
    LOG_VOID_RETURN();
}

Server::~Server()
{
    LOG_ENTER();
    LOG_VOID_RETURN();
}

static DWORD get_register_flags(Params& params)
{
    DWORD ans = ND_MR_FLAG_ALLOW_LOCAL_WRITE;
    ans |= params.Read ? ND_MR_FLAG_ALLOW_REMOTE_READ : ND_MR_FLAG_ALLOW_REMOTE_WRITE;
    return ans;
}
ND2_ADAPTER_INFO Server::initialize(BUFFER<char> &Buf)
{
    LOG_ENTER();
    ND2_ADAPTER_INFO info = { 0 };
    NdTestBase::GetAdapterInfo(&info);
    Utils::print_adapter_info(stdout, info);
    check_in_order_dma_is_supported(info);
    NdTestBase::CreateCQ(info.MaxCompletionQueueDepth);
    NdTestBase::CreateConnector();
    DWORD const queueDepth = min(info.MaxCompletionQueueDepth, info.MaxReceiveQueueDepth);
    NdTestBase::CreateQueuePair(queueDepth, 1);
    NdTestBase::CreateMR();
    NdTestBase::RegisterDataBuffer(Buf, (DWORD)Buf.size(), get_register_flags(m_params));
    LOG_STRUCT_RETURN(ND2_ADAPTER_INFO);
    return info;
}

ND2_SGE Server::get_sge(BUFFER<char> &buf)
{
    LOG_ENTER();
    ND2_SGE sge = { 0 };
    sge.Buffer = buf;
    sge.BufferLength = (ULONG)buf.size();
    sge.MemoryRegionToken = m_pMr->GetLocalToken();
    LOG("IND2MemoryRegion::GetLocalToken -> %08X", sge.MemoryRegionToken);
    LOG_STRUCT_RETURN(ND2_SGE);
    return sge;
}

void Server::post_receive_for_terminate_message(BUFFER<char> &buf)
{
    LOG_ENTER();
    ND2_SGE sge = get_sge(buf);
    NdTestBase::PostReceive(&sge, 1, RECV_CTXT);
    LOG_VOID_RETURN();
}

static DWORD get_bind_flags(Params& params)
{
    return params.Read ? ND_OP_FLAG_ALLOW_READ : ND_OP_FLAG_ALLOW_WRITE;
}

void Server::work(const struct sockaddr_in& v4Src)
{
    LOG_ENTER();
    HEAP heap(0, 0, 0);                             // create private heap
    BUFFER<char> buf(&heap, HEAP_ZERO_MEMORY, m_params.MaxXfer + m_params.HdrLen);
    ND2_ADAPTER_INFO info = initialize(buf);
    ND2_SGE sge = get_sge(buf);                     // must be preceeded by initialize
    NdTestBase::PostReceive(&sge, 1, RECV_CTXT);    // post receive for terminate message
    NdTestServerBase::CreateListener();
    NdTestServerBase::Listen(v4Src);
    NdTestServerBase::GetConnectionRequest();       // blocks waiting for connection
    NdTestServerBase::Accept(info.MaxInboundReadLimit, 0);
    NdTestBase::CreateMW();
    NdTestBase::Bind(buf, (DWORD)buf.size(), get_bind_flags(m_params));
    send_remote_token_and_address(info, buf);
    WaitForCompletionAndCheckContext(SEND_CTXT);    // wait for send completion
    WaitForCompletionAndCheckContext(RECV_CTXT);    // wait for terminate message
    LOG_VOID_RETURN();
}

void Server::send_remote_token_and_address(ND2_ADAPTER_INFO &info, BUFFER<char> &buf)
{
    ND2_SGE sge = get_sge(buf);
    PeerInfo *pInfo = (PeerInfo*)(void*)buf;
    pInfo->RemoteToken = m_pMw->GetRemoteToken();
    LOG("IND2MemoryWindow::GetRemoteToken -> %08X", pInfo->RemoteToken);
    pInfo->IncommingReadLimit = info.MaxInboundReadLimit;
    pInfo->RemoteAddress = (unsigned __int64)(void*)buf;
    NdTestBase::Send(&sge, 1, 0, SEND_CTXT);
}

void Server::RunTest(const struct sockaddr_in& v4Src, DWORD, DWORD)
{
    LOG_ENTER();
    NdTestBase::Init(v4Src);
    try
    {
        work(v4Src);
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
