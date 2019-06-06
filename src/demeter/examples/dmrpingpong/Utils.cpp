#include "pch.h"
#include "Utils.h"


void Utils::print_info(FILE *file, ND2_ADAPTER_INFO &info)
{
#define PU(X,Y) fprintf(file, "  \"" #X "\": %" #Y ",\n", info.##X)
#define EU(X,Y) fprintf(file, "  \"" #X "\": %" #Y "\n", info.##X)
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
    EU(AdapterFlags, u);
    printf("}\n");
#undef PU
}
