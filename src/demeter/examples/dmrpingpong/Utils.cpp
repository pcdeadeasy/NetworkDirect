#include "pch.h"
#include "Utils.h"


void Utils::print_info(FILE *file, ND2_ADAPTER_INFO &info)
{
#define PU(X,Y) fprintf(file, "  \"" #X "\": %" #Y ",\n", info.##X)
#define EU(X,Y) fprintf(file, "  \"" #X "\": %" #Y "\n", info.##X)
    fprintf(file, "{\n");
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
    fprintf(file, "}\n");
#undef EU
#undef PU
}

void Utils::print_result(FILE *file, const ND2_RESULT &result)
{
#define PU(X,Y) fprintf(file, "  \"" #X "\": %" #Y ",\n", result.##X)
#define QU(X,Y) fprintf(file, "  \"" #X "\": \"%" #Y "\",\n", result.##X)
#define EU(X,Y) fprintf(file, "  \"" #X "\": %" #Y "\n", result.##X)
    fprintf(file, "{\n");
    PU(Status, 08x);
    PU(BytesTransferred, u);
    QU(QueuePairContext, p);
    QU(RequestContext, p);
    fprintf(file, "  \"RequestType\": { \"value\": %u, \"symbol\": \"%s\" },\n", result.RequestType, Utils::request_type(result.RequestType));
    fprintf(file, "}\n");
#undef QU
#undef EU
#undef PU
}

const char* Utils::request_type(ND2_REQUEST_TYPE rtype)
{
#define K(X) case X: return(#X)

    switch (rtype)
    {
        K(Nd2RequestTypeReceive);
        K(Nd2RequestTypeSend);
        K(Nd2RequestTypeBind);
        K(Nd2RequestTypeInvalidate);
        K(Nd2RequestTypeRead);
        K(Nd2RequestTypeWrite);
    default:
        return "Unknown";
    }
#undef K
}

void Utils::print_sge(FILE *file, const ND2_SGE &sge)
{
    fprintf(file, "{\n");
    fprintf(file, "  \"Buffer\": \"%p\",\n", sge.Buffer);
    fprintf(file, "  \"BufferLength\": %u,\n", sge.BufferLength);
    fprintf(file, "  \"MemoryRegionToken\": %u\n", sge.MemoryRegionToken);
    fprintf(file, "}\n");
}

void Utils::hexdumptofile(FILE *file, const void *addr, size_t len)
{
    int i;
    unsigned char buff[17];
    unsigned char *pc = (unsigned char*)addr;

    for (i = 0; i < len; i++)
    {
        if ((i % 16) == 0)
        {
            if (i != 0)
                fprintf(file, "  %s\n", buff);
            fprintf(file, "[%08X] ", i);
        }
        if ((i % 16) == 8)
            fprintf(file, " - %02X", pc[i]);
        else
            fprintf(file, " %02X", pc[i]);
        buff[i % 16] = ((pc[i] < 0x20) || (pc[i] > 0x7e)) ? '.' : pc[i];
        buff[(i % 16) + 1] = '\0';
    }
    while ((i % 16) != 0) {
        fprintf(file, "   ");
        i++;
    }
    fprintf(file, "  %s\n", buff);
}

int Utils::hexdumptostring(char *output, size_t output_size, const void *input, size_t input_size)
{
    int i;
    unsigned char ascii[17];
    unsigned char *pc = (unsigned char*)input;

    int j = 0;
    for (i = 0; i < input_size; i++)
    {
        if ((i % 16) == 0)
        {
            if (i != 0)
                j += sprintf_s(output + j, output_size - j, "  %s\n", ascii);
            j += sprintf_s(output + j, output_size - j, "[%08X] ", i);
        }
        if ((i % 16) == 8)
        {
            j += sprintf_s(output + j, output_size - j, " - %02X", pc[i]);
        }
        else
        {
            j += sprintf_s(output + j, output_size - j, " %02X", pc[i]);
        }
        ascii[i % 16] = ((pc[i] < 0x20) || (pc[i] > 0x7e)) ? '.' : pc[i];
        ascii[(i % 16) + 1] = '\0';
    }
    while ((i % 16) != 0)
    {
        if ((i % 16) == 8)
            j += sprintf_s(output + j, output_size - j, "  ");
        j += sprintf_s(output + j, output_size - j, "   ");
        i++;
    }
    j += sprintf_s(output + j, output_size - j, "  %s\n", ascii);
    return j;
}
