#pragma once
#include <ndcommon.h>

class Utils
{
public:
    static void print_info(FILE *file, ND2_ADAPTER_INFO &info);
    static void print_result(FILE *file, const ND2_RESULT &result);
    static const char* request_type(ND2_REQUEST_TYPE rtype);
    static void print_sge(FILE *file, const ND2_SGE &sge);
    static void hexdumptofile(FILE *file, const void *addr, size_t len);
    static int hexdumptostring(char *output, size_t output_size, const void *input, size_t input_size);
};

