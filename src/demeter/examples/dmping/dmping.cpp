#include "pch.h"
#include <stdio.h>
#include <Logger.h>
#include <Winshim.h>
#include <WinHeap.h>
#include <ndutil.h>
#include <ndtestutil.h>
#include "Args.h"
#include "json.h"

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

void work()
{
    WSA wsa;
    HEAP Heap(0, 0, 0);
    NetworkDirectEnvironment networkDirectEnvironment;
    LOG("Finished the initialization");
}

int main(int arc, char* argv[])
{
    Logger logger("log.json");
    LOG_ENTER();
    try
    {
        WSA wsa;
        HEAP heap(0, 0, 0);
        ARGS args(&heap, argv[1]);
        printf("role: %d\n", args.get_role());
        printf("count: %d\n", args.get_count());
    }
    catch (char* msg)
    {
        fprintf(stderr, "%s\n", msg);
    }
    catch (...)
    {
    }
    LOG_INT_RETURN(0);
    return 0;
}
