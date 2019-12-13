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
