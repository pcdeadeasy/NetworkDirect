#include "pch.h"
#include <stdio.h>
#include <Logger.h>
#include <Winshim.h>
#include <WinHeap.h>
#include <ndutil.h>
#include <ndtestutil.h>
#include "csv.h"

class NetworkDirectEnvironment
{
public:
    NetworkDirectEnvironment()
    {
        if (FAILED(NdStartup()))
            throw Win::Error();
    }

    ~NetworkDirectEnvironment()
    {
        NdCleanup();
    }
};

struct PARAMS {
    int count;
    const char *role;
    const char *ip;
    int port;
    int nSge;
    bool bPoling;
    bool bBlocking;
    SIZE_T nPipeline;
    SIZE_T MaxXfer;
    ULONG HdrLen;
    SIZE_T MaxVolume;
    SIZE_T MaxIterations;
};

struct PARAMS GetParams(CSV_DICT& dict)
{
    PARAMS ans = { 0 };
    ans.count = atoi(dict.lookup("count"));
    ans.role = dict.lookup("role");
    ans.ip = dict.lookup("ip");
    ans.nSge = atoi(dict.lookup("nSge"));
    ans.port = atoi(dict.lookup("port"));
    ans.MaxXfer = (SIZE_T)atoll(dict.lookup("MaxXfer"));
    ans.HdrLen = (ULONG)atol(dict.lookup("HdrLen"));
    ans.MaxVolume = (SIZE_T)atoll(dict.lookup("MaxVolume"));
    ans.MaxIterations = (SIZE_T)atoll(dict.lookup("MaxIterations"));
    ans.nPipeline = (SIZE_T)atoll(dict.lookup("nPipeline"));
    ans.bBlocking = strcmp(dict.lookup("bBlocking"), "true") == 0;
    ans.bPoling = strcmp(dict.lookup("bPoling"), "true") == 0;
    return ans;
}

static struct sockaddr_in GetServerAddress(const char *IpAddress)
{
    struct sockaddr_in ans = { 0 };
    int len = sizeof(ans);
    Win::WSAStringToAddressA((char*)IpAddress, AF_INET, 0, (sockaddr*)&ans, &len);
    return ans;
}

void work(const char *csv_file_path)
{
    LOG_ENTER();
    WSA wsa;                            // enable socket functions
    HEAP heap(0, 0, 0);                 // create the heap for memory allocations
    CSV_DICT dict(heap, csv_file_path);
    struct PARAMS params = GetParams(dict);
    struct sockaddr_in v4Server = GetServerAddress(params.ip);
    BUFFER<char> buffer(&heap, HEAP_ZERO_MEMORY, params.MaxXfer + params.HdrLen);
    LOG_VOID_RETURN();
}

int main(int arc, char* argv[])
{
    Logger logger("log.json");
    LOG_ENTER();
    int rc;
    try
    {
        work(argv[1]);
        rc = 0;
    }
    catch (char* msg)
    {
        fprintf(stderr, "%s\n", msg);
        rc = -1;
    }
    catch (...)
    {
        fprintf(stderr, "Unhandled exception");
        rc = -2;
    }
    LOG_INT_RETURN(rc);
    return rc;
}
