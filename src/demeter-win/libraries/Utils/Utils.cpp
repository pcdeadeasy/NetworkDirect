#include <stdio.h>
#include "Utils.h"


int Utils::write_adapter_info(char * const buffer, size_t buffer_count, const ND2_ADAPTER_INFO &info)
{
#define PU(X, Y) "    \"" #X "\": %" #Y ",\n"
#define EU(X, Y) "    \"" #X "\": %" #Y "\n"
    const char* const fmt =
        "{\n"
        PU(InfoVersion, u)
        PU(VendorId, u)
        PU(DeviceId, u)
        PU(AdapterId, zu)
        PU(MaxRegistrationSize, zu)
        PU(MaxWindowSize, zu)
        PU(MaxInitiatorSge, u)
        PU(MaxReceiveSge, u)
        PU(MaxReadSge, u)
        PU(MaxTransferLength, u)
        PU(MaxInlineDataSize, u)
        PU(MaxInboundReadLimit, u)
        PU(MaxOutboundReadLimit, u)
        PU(MaxReceiveQueueDepth, u)
        PU(MaxInitiatorQueueDepth, u)
        PU(MaxSharedReceiveQueueDepth, u)
        PU(MaxCompletionQueueDepth, u)
        PU(InlineRequestThreshold, u)
        PU(LargeRequestThreshold, u)
        PU(MaxCallerData, u)
        PU(MaxCalleeData, u)
        EU(AdapterFlags, u)
        "}";
    return
        snprintf(
            buffer,
            buffer_count,
            fmt,
            info.InfoVersion,
            info.VendorId,
            info.DeviceId,
            info.AdapterId,
            info.MaxRegistrationSize,
            info.MaxWindowSize,
            info.MaxInitiatorSge,
            info.MaxReceiveSge,
            info.MaxReadSge,
            info.MaxTransferLength,
            info.MaxInlineDataSize,
            info.MaxInboundReadLimit,
            info.MaxOutboundReadLimit,
            info.MaxReceiveQueueDepth,
            info.MaxInitiatorQueueDepth,
            info.MaxSharedReceiveQueueDepth,
            info.MaxCompletionQueueDepth,
            info.InlineRequestThreshold,
            info.LargeRequestThreshold,
            info.MaxCallerData,
            info.MaxCalleeData,
            info.AdapterFlags
        );
#undef EU
#undef PU
}

void Utils::print_adapter_info(FILE *file, ND2_ADAPTER_INFO &info)
{
    char buffer[1024];
    int rc = Utils::write_adapter_info(buffer, sizeof(buffer), info);
    printf("write_adapter_info -> %d\n", rc);
    fprintf(file, "%s\n", buffer);
}


int Utils::write_result(char *buffer, size_t buffer_count, const ND2_RESULT &result)
{
    const char* const fmt =
        "{\n"
        "    \"Status\": \"%s\",\n"
        "    \"BytesTransferred\": %u,\n"
        "    \"QueuePairContext\": \"%p\",\n"
        "    \"RequestContext\": \"%p\",\n"
        "    \"RequestType:\": \"%s\"\n"
        "}";
    int rc = 
        snprintf(
            buffer, 
            buffer_count, 
            fmt, 
            Utils::get_status_string(result.Status),
            result.BytesTransferred,
            result.QueuePairContext,
            result.RequestContext, 
            Utils::request_type(result.RequestType)
        );
    return rc;
}

void Utils::print_result(FILE *file, const ND2_RESULT &result)
{
    char buffer[512];
    int rc = Utils::write_result(buffer, sizeof(buffer), result);
    fprintf(file, "%s\n", buffer);
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

int Utils::sge_to_string(char *output, size_t output_size, const ND2_SGE &sge)
{
    const char* const fmt = 
        "{\n"
        "  \"Buffer\": \"%p\",\n"
        "  \"BufferLength\": %u,\n"
        "  \"MemoryRegionToken\": %u\n"
       "}";
    return sprintf_s(output, output_size, fmt, sge.Buffer, sge.BufferLength, sge.MemoryRegionToken);
}

void Utils::print_sge(FILE *file, const ND2_SGE &sge)
{
    char buffer[512];
    int n = Utils::sge_to_string(buffer, sizeof(buffer), sge);
    fprintf(file, "%s", buffer);
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
        {
            const char *fmt = ((i % 16) == 8) ? " - %02X" : " %02X";
            j += sprintf_s(output + j, output_size - j, fmt, pc[i]);
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

const char* Utils::get_status_string(HRESULT status)
{
#define FOR_RESULT(X) case X: return(#X);
    switch (status)
    {
        FOR_ALL_ND_RESULTS(FOR_RESULT)
    default:
        return "UNDEFINED";
    }
#undef FOR_RESULT
}
