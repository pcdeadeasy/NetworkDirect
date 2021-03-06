#pragma once
#include <libraries/ndutil/ndutil.h>
#include <libraries/ndutil/ndtestutil.h>

class NDSPI
{
public:
    static IND2CompletionQueue* ReleaseCompletionQueue(IND2CompletionQueue*);
    static IND2QueuePair* ReleaseQueuePair(IND2QueuePair*);
    static IND2MemoryRegion* ReleaseMemoryRegion(IND2MemoryRegion*);
    static HANDLE CloseOverlappedFile(HANDLE);
    static IND2Adapter* ReleaseAdapter(IND2Adapter*);
    static IND2Connector* ReleaseConnector(IND2Connector*);
    static IND2MemoryRegion* CreateMemoryRegion(IND2Adapter*, HANDLE);
    static void DeregisterMemoryRegionAndWait(IND2MemoryRegion*);
    static void* Free(void*);
    static struct sockaddr_in GetSocketAddress(const char* ip, uint16_t Port);
    static struct sockaddr_in SimplifiedResolveAddress(struct sockaddr_in&);
    static IND2Adapter* SimplifiedOpenAdapter(const struct sockaddr_in&);
    static HANDLE CreateOverlappedEvent();
    static HANDLE CloseOverlappedEvent(HANDLE);
    static HANDLE CreateOverlappedFile(IND2Adapter*);
    static ND2_ADAPTER_INFO GetAdapterInfo(IND2Adapter*);
    static void* Alloc(size_t size);
    static void RegisterMemoryAndWait(IND2MemoryRegion*, const void*, size_t);
    static IND2Connector* SimplifiedCreateConnector(IND2Adapter*, HANDLE);
    static IND2CompletionQueue* SimplifiedCreateCompletionQueue(IND2Adapter*, HANDLE, uint32_t);
    static IND2QueuePair* SimplifiedCreateQueuePair(IND2Adapter* pAdapter, IND2CompletionQueue* pCompletionQueue, uint32_t qp_depth, uint32_t inline_threshold, uint32_t max_nsge);
    static uint32_t GetLocalToken(IND2MemoryRegion* pMemoryRegion);
    static uint32_t GetRemoteToken(IND2MemoryRegion* pMemoryRegion);
    static void Receive(IND2QueuePair* pQueuePair, void* context, ND2_SGE sges[], uint32_t nsge);
    static void Send(IND2QueuePair* pQueuePair, void* context, ND2_SGE sges[], uint32_t nsge, uint32_t flags);
    static void ConnectorBind(IND2Connector* pConnector, sockaddr_in& localAddress);
    static void ConnectAndWait(IND2Connector* pConnector, IND2QueuePair* pQueuePair, const struct sockaddr_in& remoteAddress);
    static void CompleteConnectAndWait(IND2Connector* pConnector);
    static uint32_t GetResults(IND2CompletionQueue* pCompletionQueue, ND2_RESULT results[], uint32_t nResults);
    static HRESULT Notify(IND2CompletionQueue* pCompletionQueue, uint32_t type, OVERLAPPED& ov);
    static IND2Listener* CreateListener(IND2Adapter* pAdapter, HANDLE hOverlappedFile);
    static IND2Listener*  ReleaseListener(IND2Listener* pListener);
    static void ListenerBind(IND2Listener* pListener, const struct sockaddr_in& localAddress);
    static void Listen(IND2Listener* pListener, uint32_t backlog);
    static void GetConnectionRequestAndWait(IND2Listener* pListener, IND2Connector* pConnector);
    static void AcceptAndWait(IND2Connector* pConnector, IND2QueuePair* pQueuePair, uint32_t inboundReadLimit, uint32_t outboundReadLimit);
    static HRESULT GetOverlappedResult(IND2Overlapped* pobj, OVERLAPPED* pov , bool wait);
    static void Wait(IND2Overlapped* pObject, OVERLAPPED* pOverlapped);
};

