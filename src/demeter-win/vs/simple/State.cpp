#include <libraries/logger/Logger.h>
#include <libraries/Winshim/Winshim.h>
#include "State.h"
#include "ndspi.h"

State::State() :
    pAdapter(0),
    hOverlappedFile(0),
    pMemoryRegion(0),
    pCompletionQueue(0),
    pQueuePair(0),
    pConnector(0),
    pListener(0),
    buffer(0),
    buffer_size(0)
{
    LOG_ENTER();
    memset(&LocalAddress, 0, sizeof(LocalAddress));
    memset(&RemoteAddress, 0, sizeof(RemoteAddress));
    memset(&ov, 0, sizeof(ov));
    LOG_VOID_RETURN();
}

State::~State()
{
    LOG_ENTER();
    pCompletionQueue = NDSPI::ReleaseCompletionQueue(pCompletionQueue);
    pQueuePair = NDSPI::ReleaseQueuePair(pQueuePair);
    pMemoryRegion = NDSPI::ReleaseMemoryRegion(pMemoryRegion);
    hOverlappedFile = NDSPI::CloseOverlappedFile(hOverlappedFile);
    pConnector = NDSPI::ReleaseConnector(pConnector);
    pAdapter = NDSPI::ReleaseAdapter(pAdapter);
    pListener = NDSPI::ReleaseListener(pListener);
    ov.hEvent = NDSPI::CloseOverlappedEvent(ov.hEvent);
    buffer = NDSPI::Free(buffer);
    buffer_size = 0;
    LOG_VOID_RETURN();
}

uint32_t get_client_cq_depth2(uint32_t queueDepth, const ND2_ADAPTER_INFO& info)
{
    LOG_ENTER();
    uint32_t const cqd = info.MaxCompletionQueueDepth;
    uint32_t const iqd = info.MaxInitiatorQueueDepth;
    uint32_t ans = (queueDepth > 0) ? min(queueDepth, cqd) : cqd;
    ans = min(ans, iqd);
    LOG_ULONG_RETURN(ans);
    return ans;
}

void State::InitClient(
    const char* server_ip_address,
    uint16_t server_port,
    uint32_t queue_depth,
    size_t memory_block_size,
    uint32_t nsge
)
{
    LOG_ENTER();
    RemoteAddress = NDSPI::GetSocketAddress(server_ip_address, server_port);
    LocalAddress = NDSPI::SimplifiedResolveAddress(RemoteAddress);
    pAdapter = NDSPI::SimplifiedOpenAdapter(LocalAddress);
    ov.hEvent = NDSPI::CreateOverlappedEvent();
    hOverlappedFile = NDSPI::CreateOverlappedFile(pAdapter);
    Info = NDSPI::GetAdapterInfo(pAdapter);
    pMemoryRegion = NDSPI::CreateMemoryRegion(pAdapter, hOverlappedFile);
    uint32_t const cq_depth = get_client_cq_depth2(queue_depth, Info);
    pCompletionQueue = NDSPI::SimplifiedCreateCompletionQueue(pAdapter, hOverlappedFile, cq_depth);
    pConnector = NDSPI::SimplifiedCreateConnector(pAdapter, hOverlappedFile);
    uint32_t const qp_depth = min(cq_depth, Info.MaxReceiveQueueDepth);
    pQueuePair = NDSPI::SimplifiedCreateQueuePair(pAdapter, pCompletionQueue, qp_depth, Info.InlineRequestThreshold, nsge);
    buffer = NDSPI::Alloc(memory_block_size);
    buffer_size = memory_block_size;
    NDSPI::RegisterMemoryAndWait(pMemoryRegion, buffer, buffer_size);
    LOG_VOID_RETURN();
}

void State::InitServer(
    const char* server_ip_address,
    uint16_t server_port,
    uint32_t queue_depth,
    size_t memory_block_size,
    uint32_t nsge
)
{
    LOG_ENTER();
    LocalAddress = NDSPI::GetSocketAddress(server_ip_address, server_port);
    pAdapter = NDSPI::SimplifiedOpenAdapter(LocalAddress);
    ov.hEvent = NDSPI::CreateOverlappedEvent();
    hOverlappedFile = NDSPI::CreateOverlappedFile(pAdapter);
    Info = NDSPI::GetAdapterInfo(pAdapter);
    pCompletionQueue = NDSPI::SimplifiedCreateCompletionQueue(pAdapter, hOverlappedFile, Info.MaxInitiatorQueueDepth);
    pConnector = NDSPI::SimplifiedCreateConnector(pAdapter, hOverlappedFile);
    pMemoryRegion = NDSPI::CreateMemoryRegion(pAdapter, hOverlappedFile);
    uint32_t depth = min(Info.MaxCompletionQueueDepth, Info.MaxReceiveQueueDepth);
    pQueuePair = NDSPI::SimplifiedCreateQueuePair(pAdapter, pCompletionQueue, depth, 0, nsge);
    pListener = NDSPI::CreateListener(pAdapter, hOverlappedFile);
    NDSPI::ListenerBind(pListener, LocalAddress);
    NDSPI::Listen(pListener, 0);
    LOG_VOID_RETURN();
}
