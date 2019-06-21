#pragma once

class Utils
{
public:
    static int write_adapter_info(char * const buffer, size_t buffer_count, const ND2_ADAPTER_INFO &info);
    static void print_adapter_info(FILE *file, ND2_ADAPTER_INFO &info);
    static int write_result(char *buffer, size_t buffer_count, const ND2_RESULT &result);
    static void print_result(FILE *file, const ND2_RESULT &result);
    static const char* request_type(ND2_REQUEST_TYPE rtype);
    static void print_sge(FILE *file, const ND2_SGE &sge);
    static void hexdumptofile(FILE *file, const void *addr, size_t len);
    static int hexdumptostring(char *output, size_t output_size, const void *input, size_t input_size);
    static const char* get_status_string(HRESULT status);

};

#define FOR_ALL_ND_RESULTS(X)       \
    X(ND_SUCCESS)                   \
    X(ND_TIMEOUT)                   \
    X(ND_PENDING)                   \
    X(ND_BUFFER_OVERFLOW)           \
    X(ND_DEVICE_BUSY)               \
    X(ND_NO_MORE_ENTRIES)           \
    X(ND_UNSUCCESSFUL)              \
    X(ND_ACCESS_VIOLATION)          \
    X(ND_INVALID_HANDLE)            \
    X(ND_INVALID_DEVICE_REQUEST)    \
    X(ND_INVALID_PARAMETER)         \
    X(ND_NO_MEMORY)                 \
    X(ND_INVALID_PARAMETER_MIX)     \
    X(ND_DATA_OVERRUN)              \
    X(ND_SHARING_VIOLATION)         \
    X(ND_INSUFFICIENT_RESOURCES)    \
    X(ND_DEVICE_NOT_READY)          \
    X(ND_IO_TIMEOUT)                \
    X(ND_NOT_SUPPORTED)             \
    X(ND_INTERNAL_ERROR)            \
    X(ND_INVALID_PARAMETER_1)       \
    X(ND_INVALID_PARAMETER_2)       \
    X(ND_INVALID_PARAMETER_3)       \
    X(ND_INVALID_PARAMETER_4)       \
    X(ND_INVALID_PARAMETER_5)       \
    X(ND_INVALID_PARAMETER_6)       \
    X(ND_INVALID_PARAMETER_7)       \
    X(ND_INVALID_PARAMETER_8)       \
    X(ND_INVALID_PARAMETER_9)       \
    X(ND_INVALID_PARAMETER_10)      \
    X(ND_CANCELED)                  \
    X(ND_REMOTE_ERROR)              \
    X(ND_INVALID_ADDRESS)           \
    X(ND_INVALID_DEVICE_STATE)      \
    X(ND_INVALID_BUFFER_SIZE)       \
    X(ND_TOO_MANY_ADDRESSES)        \
    X(ND_ADDRESS_ALREADY_EXISTS)    \
    X(ND_CONNECTION_REFUSED)        \
    X(ND_CONNECTION_INVALID)        \
    X(ND_CONNECTION_ACTIVE)         \
    X(ND_NETWORK_UNREACHABLE)       \
    X(ND_HOST_UNREACHABLE)          \
    X(ND_CONNECTION_ABORTED)        \
    X(ND_DEVICE_REMOVED)
