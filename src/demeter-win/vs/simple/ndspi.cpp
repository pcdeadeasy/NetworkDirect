#include <libraries/logger/Logger.h>
#include <libraries/Winshim/Winshim.h>
#include <libraries/ndutil/ndutil.h>
#include <libraries/ndutil/ndtestutil.h>
#include "errors.h"
#include "ndspi.h"

ND2_ADAPTER_INFO NDSPI::GetAdapterInfo(IND2Adapter* pAdapter)
{
    LOG_ENTER();
    ND2_ADAPTER_INFO ans = { 0 };
    memset(&ans, 0, sizeof(ans));
    ans.InfoVersion = ND_VERSION_2;
    ULONG size = sizeof(ans);
    HRESULT hr = pAdapter->Query(&ans, &size);
    LOG("IND2Adapter::Query %p -> %08X", pAdapter, hr);
    if (ND_SUCCESS != hr)
        throw EX_QUERY;
    LOG_STRUCT_RETURN(ND2_ADAPTER_INFO);
    return ans;
}

IND2CompletionQueue* NDSPI::SimplifiedCreateCompletionQueue(IND2Adapter* pAdapter, HANDLE hOverlappedFile, uint32_t depth)
{
    LOG_ENTER();
    IND2CompletionQueue* ans = 0;
    HRESULT hr =
        pAdapter->CreateCompletionQueue(
            IID_IND2CompletionQueue,
            hOverlappedFile,
            depth,
            0,
            0,
            (void**)&ans
        );
    LOG("IND2Adapter::CreateCompletionQueue %p -> %08X", pAdapter, hr);
    if (ND_SUCCESS != hr)
        throw EX_CREATE_COMPLETION_QUEUE;
    LOG_PVOID_RETURN(ans);
    return ans;
}

HANDLE NDSPI::CloseOverlappedEvent(HANDLE hEvent)
{
    LOG_ENTER();
    if (hEvent)
    {
        Win::CloseHandle(hEvent);
    }
    LOG_PVOID_RETURN(0);
    return 0;
}

IND2Listener* NDSPI::ReleaseListener(IND2Listener* p)
{
    LOG_ENTER();
    if (p)
    {
        ULONG ul = p->Release();
        LOG("IND2Listener::Release %p -> %u", p, ul);
    }
    LOG_PVOID_RETURN(0);
    return 0;
}

IND2Connector* NDSPI::ReleaseConnector(IND2Connector* p)
{
    LOG_ENTER();
    if (p)
    {
        ULONG ul = p->Release();
        LOG("IND2Connector::Release %p -> %u", p, ul);
    }
    LOG_PVOID_RETURN(0);
    return 0;
}

IND2CompletionQueue* NDSPI::ReleaseCompletionQueue(IND2CompletionQueue* p)
{
    LOG_ENTER();
    if (p)
    {
        ULONG ul = p->Release();
        LOG("IND2CompletionQueue::Release %p -> %u", p, ul);
    }
    LOG_PVOID_RETURN(0);
    return 0;
}

IND2QueuePair* NDSPI::ReleaseQueuePair(IND2QueuePair* p)
{
    LOG_ENTER();
    if (p)
    {
        ULONG ul = p->Release();
        LOG("IND2QueuePair::Release %p -> %u", p, ul);
    }
    LOG_PVOID_RETURN(0);
    return 0;
}

IND2MemoryRegion* NDSPI::ReleaseMemoryRegion(IND2MemoryRegion* p)
{
    LOG_ENTER();
    if (p)
    {
        ULONG ul = p->Release();
        LOG("IND2MemoryRegion::Release %p -> %u", p, ul);
    }
    LOG_PVOID_RETURN(0);
    return 0;
}

IND2Adapter* NDSPI::ReleaseAdapter(IND2Adapter* p)
{
    LOG_ENTER();
    if (p)
    {
        ULONG ul = p->Release();
        LOG("IND2Adapter::Release %p -> %u", p, ul);
    }
    LOG_PVOID_RETURN(0);
    return 0;
}


HANDLE NDSPI::CloseOverlappedFile(HANDLE h)
{
    LOG_ENTER();
    if (h)
    {
        BOOL ans = ::CloseHandle(h);
        LOG("CloseHandle %p -> %d", h, ans);
    }
    LOG_PVOID_RETURN(0);
    return 0;
}

void NDSPI::DeregisterMemoryRegionAndWait(IND2MemoryRegion* p)
{
    LOG_ENTER();
    OVERLAPPED ov = { 0 };
    HRESULT hr = p->Deregister(&ov);
    LOG("IND2MemoryRegion::Deregister %p -> %08X", p, hr);
    if (hr == ND_PENDING)
    {
        uint64_t count = 1;
        while ((hr = p->GetOverlappedResult(&ov, FALSE)) == ND_PENDING)
        {
            count += 1;
        }
        LOG("IND2MemoryRegion::GetOverlappedResult %p -> %08X (%zu times)", p, hr, count);
    }
    LOG_VOID_RETURN();
}

void* NDSPI::Free(void* p)
{
    LOG_ENTER();
    if (p)
    {
        LOG("free %p", p);
        free(p);
    }
    LOG_PVOID_RETURN(0);
    return 0;
}

struct sockaddr_in NDSPI::GetSocketAddress(const char* ip, uint16_t Port)
{
    LOG_ENTER();
    struct sockaddr_in v4Svr = { 0 };
    int AddressLength = (int)sizeof(v4Svr);
#pragma warning( push )
#pragma warning( disable : 4996 ) // suppress deprecation warning
    Win::WSAStringToAddressA((LPSTR)ip, AF_INET, 0, (sockaddr*)&v4Svr, &AddressLength);
#pragma warning( pop )
    v4Svr.sin_port = htons(Port);
    LOG_STRUCT_RETURN(struct sockaddr_in);
    return v4Svr;
}

struct sockaddr_in NDSPI::SimplifiedResolveAddress(struct sockaddr_in& saddrRemote)
{
    LOG_ENTER();
    struct sockaddr_in ans = { 0 };
    size_t len = sizeof(ans);
    HRESULT hr =
        NdResolveAddress(
        (const struct sockaddr*)&saddrRemote,
            sizeof(saddrRemote),
            (struct sockaddr*)&ans,
            &len
        );
    if (ND_SUCCESS != hr)
        throw EX_RESOLVE_ADDRESS;
    LOG_STRUCT_RETURN(struct sockaddr_in);
    return ans;
}

IND2Adapter* NDSPI::SimplifiedOpenAdapter(const struct sockaddr_in& Local)
{
    LOG_ENTER();
    IND2Adapter* ans = 0;
    HRESULT hr =
        NdOpenAdapter(
            IID_IND2Adapter,
            (const struct sockaddr*)&Local,
            sizeof(Local),
            (void**)&ans
        );
    if (ND_SUCCESS != hr)
        throw EX_OPEN_ADAPTER;
    LOG_PVOID_RETURN(ans);
    return ans;
}

HANDLE NDSPI::CreateOverlappedEvent()
{
    LOG_ENTER();
    HANDLE ans = ::CreateEvent(0, 0, 0, 0);
    LOG("CreateEvent -> %p", ans);
    if (0 == ans)
        throw EX_CREATE_EVENT;
    LOG_PVOID_RETURN(ans);
    return ans;
}

IND2Connector* NDSPI::SimplifiedCreateConnector(IND2Adapter* pAdapter, HANDLE hOverlappedFile)
{
    LOG_ENTER();
    IND2Connector* ans = 0;
    HRESULT hr = pAdapter->CreateConnector(IID_IND2Connector, hOverlappedFile, (void**)&ans);
    LOG("IND2Adapter::CreateConnector %p -> %08X", pAdapter, hr);
    if (ND_SUCCESS != hr)
        throw EX_CREATE_CONNECTOR;
    LOG_PVOID_RETURN(ans);
    return ans;
}

void* NDSPI::Alloc(size_t size)
{
    LOG_ENTER();
    if (size == 0)
        throw EX_MALLOC;
    void* ans = malloc(size);
    LOG("malloc %zu -> %p", size, ans);
    if (ans == 0)
        throw EX_MALLOC;
    LOG_PVOID_RETURN(ans);
    return ans;
}

void NDSPI::RegisterMemoryAndWait(IND2MemoryRegion* pMemoryRegion, const void* buffer, size_t size)
{
    LOG_ENTER();
    ULONG const flags = ND_MR_FLAG_ALLOW_LOCAL_WRITE;
    OVERLAPPED ov = { 0 };
    HRESULT hr = pMemoryRegion->Register(buffer, size, flags, &ov);
    LOG("IND2MemoryRegion::Register %p %p -> %08X", pMemoryRegion, buffer, hr);
    if (ND_SUCCESS != hr)
    {
        uint64_t count = 0;
        while (ND_PENDING == hr)
        {
            count += 1;
            hr = pMemoryRegion->GetOverlappedResult(&ov, FALSE);
        }
        LOG("IND2MemoryRegion::GetOverlappedResult %p -> %08X (%zu times)", pMemoryRegion, hr, count);
        if (ND_SUCCESS != hr)
            throw EX_REGISTER;

    }
    LOG_VOID_RETURN();
}

HANDLE NDSPI::CreateOverlappedFile(IND2Adapter* pAdapter)
{
    LOG_ENTER();
    HANDLE ans = 0;
    HRESULT hr = pAdapter->CreateOverlappedFile(&ans);
    LOG("IND2Adapter::CreateOverlappedFile %p -> %08X", hr, ans);
    if (ND_SUCCESS != hr)
        throw EX_CREATE_OVERLAPPED_FILE;
    LOG_PVOID_RETURN(ans);
    return ans;
}

IND2MemoryRegion* NDSPI::CreateMemoryRegion(IND2Adapter* pAdapter, HANDLE hOverlappedFile)
{
    LOG_ENTER();
    IND2MemoryRegion* ans = 0;
    HRESULT hr = pAdapter->CreateMemoryRegion(IID_IND2MemoryRegion, hOverlappedFile, (void**)&ans);
    LOG("IND2Adapter::CreateMemoryRegion %p -> %08X", hr);
    if (ND_SUCCESS != hr)
        throw EX_CREATE_MEMORY_REGION;
    LOG_PVOID_RETURN(ans);
    return ans;
}

IND2QueuePair* NDSPI::SimplifiedCreateQueuePair(
    IND2Adapter* pAdapter,
    IND2CompletionQueue* pCompletionQueue,
    uint32_t qp_depth,
    uint32_t inline_threshold,
    uint32_t max_nsge
)
{
    LOG_ENTER();
    IND2QueuePair* ans = 0;
    HRESULT hr =
        pAdapter->CreateQueuePair(
            IID_IND2QueuePair,
            pCompletionQueue,
            pCompletionQueue,
            0,
            qp_depth,
            qp_depth,
            max_nsge,
            max_nsge,
            inline_threshold,
            (void**)&ans
        );
    LOG("IND2Adapter::CreateQueuePair %p -> %08X", pAdapter, hr);
    if (ND_SUCCESS != hr)
        throw EX_CREATE_QUEUE_PAIR;
    LOG_PVOID_RETURN(ans);
    return ans;
}

uint32_t NDSPI::GetLocalToken(IND2MemoryRegion* pMemoryRegion)
{
    LOG_ENTER();
    uint32_t ans = pMemoryRegion->GetLocalToken();
    LOG("IND2MemoryRegion::GetLocalToken %p -> %u", pMemoryRegion, ans);
    LOG_ULONG_RETURN(ans);
    return ans;
}

uint32_t NDSPI::GetRemoteToken(IND2MemoryRegion* pMemoryRegion)
{
    LOG_ENTER();
    uint32_t ans = pMemoryRegion->GetRemoteToken();
    LOG("IND2MemoryRegion::GetRemoteToken %p -> %u", pMemoryRegion, ans);
    LOG_ULONG_RETURN(ans);
    return ans;
}

void NDSPI::Receive(IND2QueuePair* pQueuePair, void* context, ND2_SGE sges[], uint32_t nsge)
{
    LOG_ENTER();
    HRESULT hr = pQueuePair->Receive(context, sges, nsge);
    LOG("IND2QueuePair::Receive %p -> %08X", pQueuePair, hr);
    if (ND_SUCCESS != hr)
        throw EX_RECEIVE;
    LOG_VOID_RETURN();
}

void NDSPI::Send(IND2QueuePair* pQueuePair, void* context, ND2_SGE sges[], uint32_t nsge, uint32_t flags)
{
    LOG_ENTER();
    HRESULT hr = pQueuePair->Send(context, sges, nsge, flags);
    LOG("IND2QueuePair::Send %p -> %08X", pQueuePair, hr);
    if (ND_SUCCESS != hr)
        throw EX_SEND;
    LOG_VOID_RETURN();
}

void NDSPI::ConnectorBind(IND2Connector* pConnector, sockaddr_in& localAddress)
{
    LOG_ENTER();
    HRESULT hr = pConnector->Bind((const sockaddr*)&localAddress, sizeof(localAddress));
    LOG("IND2Connector::Bind %p -> %08X", pConnector, hr);
    if (ND_SUCCESS != hr)
        throw EX_CONNECTOR_BIND;
    LOG_VOID_RETURN();
}

void NDSPI::ConnectAndWait(IND2Connector* pConnector, IND2QueuePair* pQueuePair, const struct sockaddr_in& remoteAddress)
{
    LOG_ENTER();
    OVERLAPPED ov = { 0 };
    HRESULT hr =
        pConnector->Connect(
            pQueuePair,
            (const sockaddr*)&remoteAddress,
            sizeof(remoteAddress),
            0,  // inboundReadLimit
            0,  // outboundReadLimit
            0,  // pPrivateData
            0,  // cbPrivateData
            &ov
        );
    LOG("IND2Connnector::Connect %p -> %08X", pConnector, hr);
    if (ND_SUCCESS != hr)
    {
        uint64_t count = 0;
        while (ND_PENDING == hr)
        {
            count++;
            hr = pConnector->GetOverlappedResult(&ov, FALSE);
        }
        LOG("IND2Connector::GetOverlappedResult %p -> %08X (%zu times)", pConnector, hr, count);
        if (ND_SUCCESS != hr)
            throw EX_CONNECT;
    }
    LOG_VOID_RETURN();
}

void NDSPI::CompleteConnectAndWait(IND2Connector* pConnector)
{
    LOG_ENTER();
    OVERLAPPED ov = { 0 };
    HRESULT hr = pConnector->CompleteConnect(&ov);
    LOG("IND2Connector::CompleteConnect %p -> %08X", pConnector, hr);
    if (ND_SUCCESS != hr)
    {
        uint64_t count = 0;
        while (ND_PENDING == hr)
        {
            count++;
            hr = pConnector->GetOverlappedResult(&ov, FALSE);
        }
        LOG("IND2Connector::GetOverlappedResult %p -> %08X (%zu times)", pConnector, hr, count);
        if (ND_SUCCESS != hr)
            throw EX_COMPLETE_CONNECT;
    }
    LOG_VOID_RETURN();
}

uint32_t NDSPI::GetResults(IND2CompletionQueue* pCompletionQueue, ND2_RESULT results[], uint32_t nResults)
{
    LOG_ENTER();
    uint32_t ans = pCompletionQueue->GetResults(results, nResults);
    LOG("IND2CompletionQueue::GetResults %p -> %u", pCompletionQueue, ans);
    LOG_ULONG_RETURN(ans);
    return ans;
}

HRESULT NDSPI::Notify(IND2CompletionQueue* pCompletionQueue, uint32_t type, OVERLAPPED& ov)
{
    LOG_ENTER();
    HRESULT hr = pCompletionQueue->Notify(type, &ov);
    LOG("IND2CompletionQueue::Notify %p -> %08X", pCompletionQueue, hr);
    if ((hr != ND_SUCCESS)  && (hr != ND_PENDING))
        throw EX_NOTIFY;
    LOG_HEX_RETURN(hr);
    return hr;
}

IND2Listener* NDSPI::CreateListener(IND2Adapter* pAdapter, HANDLE hOverlappedFile)
{
    LOG_ENTER();
    IND2Listener* ans = 0;
    HRESULT hr = pAdapter->CreateListener(IID_IND2Listener, hOverlappedFile, (void**)&ans);
    LOG("IND2Adapter::CreateListener %p -> %08X", pAdapter, hr);
    if (ND_SUCCESS != hr)
        throw EX_CREATE_LISTENER;
    LOG_PVOID_RETURN(ans);
    return ans;
}

void NDSPI::ListenerBind(IND2Listener* pListener, const struct sockaddr_in& localAddress)
{
    LOG_ENTER();
    HRESULT hr = pListener->Bind((const sockaddr*)&localAddress, sizeof(localAddress));
    LOG("IND2Listener::Bind %p -> %08X", pListener, hr);
    if (ND_SUCCESS != hr)
        throw EX_LISTEN_BIND;
    LOG_VOID_RETURN();
}

void NDSPI::Listen(IND2Listener* pListener, uint32_t backlog)
{
    LOG_ENTER();
    HRESULT hr = pListener->Listen(backlog);
    LOG("IND2Listner::Listen %p -> %08X", pListener, hr);
    if (ND_SUCCESS != hr)
        throw EX_LISTEN;
    LOG_VOID_RETURN();
}

void NDSPI::GetConnectionRequestAndWait(IND2Listener* pListener, IND2Connector* pConnector)
{
    LOG_ENTER();
    OVERLAPPED ov = { 0 };
    HRESULT hr = pListener->GetConnectionRequest(pConnector, &ov);
    if (ND_SUCCESS != hr)
    {
        if (ND_PENDING == hr)
        {
            //!!! WARNING WARNING WARNING this will block
            hr = pListener->GetOverlappedResult(&ov, TRUE);
        }
        if (ND_SUCCESS != hr)
            throw EX_GET_CONNECTION_REQUEST;
    }
    LOG_VOID_RETURN();
}

void NDSPI::AcceptAndWait(IND2Connector* pConnector, IND2QueuePair* pQueuePair, uint32_t inboundReadLimit, uint32_t outboundReadLimit)
{
    LOG_ENTER();
    OVERLAPPED ov = { 0 };
    HRESULT hr =
        pConnector->Accept(
            pQueuePair,
            inboundReadLimit,
            outboundReadLimit,
            0,  // pointer to private data
            0,  // size of private data
            &ov
        );
    LOG("IND2Connector::Accept %p -> %08X", pConnector, hr);
    if (ND_SUCCESS != hr)
    {
        uint64_t count = 0;
        if (ND_PENDING == hr)
        {
            //!!! WARNING WARNING WARNING THIS WILL BLOCK
            hr = pConnector->GetOverlappedResult(&ov, TRUE);
            LOG("IND2Connector::GetOverlappedResult %p -> %08X", pConnector, hr);
        }
        if (ND_SUCCESS != hr)
            throw EX_ACCEPT;

    }
    LOG_VOID_RETURN();
}

HRESULT NDSPI::GetOverlappedResult(IND2Overlapped* pobj, OVERLAPPED* pov, bool wait)
{
    LOG_ENTER();
    HRESULT hr = pobj->GetOverlappedResult(pov, wait);
    LOG("IND2Overlapped::GetOverlappedResult %p (wait:%d) -> %08X", pobj, wait, hr);
    if ((hr != ND_SUCCESS) && (hr != ND_PENDING))
        throw EX_GET_OVERLAPPED_RESULT;
    LOG_HEX_RETURN(hr);
    return hr;
}
