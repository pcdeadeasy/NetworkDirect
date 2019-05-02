#include "pch.h"
#include <Logger.h>
#include <Winshim.h>
#include <WinHeap.h>
#include "Client.h"

Client::Client(Params &params) : m_params(params),
                                 m_availCredits(0)
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
    Win::WSAAddresToStringA((LPSOCKADDR)&addr, (DWORD)sizeof(addr), 0, buffer, &dwAddressStringLength);
    printf("%s: %s\n", name, buffer);
}

void Client::RunTest(const struct sockaddr_in &v4Src, const struct sockaddr_in &v4Dst, DWORD queueDepth, DWORD nSge)
{
    LOG_ENTER();
    print_address(v4Src, "v4Src");
    print_address(v4Dst, "v4Dst");
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

ULONG get_register_data_buffer_flags(Params &params)
{
    LOG_ENTER();
    ULONG ans = ND_MR_FLAG_ALLOW_LOCAL_WRITE;
    if (params.Read)
    {
        ans |= ND_MR_FLAG_RDMA_READ_SINK;
    }
    LOG_ULONG_RETURN(ans);
    return ans;
}

void Client::Work(const struct sockaddr_in& v4Src, const struct sockaddr_in &v4Dst, DWORD queueDepth, DWORD nSge)
{
    LOG_ENTER();
    HEAP heap(0, 0, 0);
    BUFFER<char> buf(&heap, HEAP_ZERO_MEMORY, m_params.MaxXfer + m_params.HdrLen);

    ND2_ADAPTER_INFO info = { 0 };
    NdTestBase::GetAdapterInfo(&info);
    if ((info.AdapterFlags & ND_ADAPTER_FLAG_IN_ORDER_DMA_SUPPORTED) == 0)
    {
        LOG_ERROR_RETURN();
        throw "Adapter does not support in-order RDMA";
    }

    NdTestBase::CreateMR();
    ULONG flags = get_register_data_buffer_flags(m_params);
    NdTestBase::RegisterDataBuffer(buf, (DWORD)buf.size(), flags);
    LOG_VOID_RETURN();
}
