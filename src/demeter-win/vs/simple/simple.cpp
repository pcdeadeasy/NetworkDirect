#define INITGUID

#include <libraries/logger/Logger.h>
#include <libraries/Winshim/Winshim.h>
#include <libraries/ndutil/ndutil.h>
#include <libraries/ndutil/ndtestutil.h>
#include "params.h"
#include "ndscope.h"
#include "errors.h"
#include "work.h"
#include "client.h"
#include "server.h"


void run(params_t* const params)
{
    LOG_ENTER();
    if (params->role == "client")
        client(params);
    else if (params->role == "server")
        server(params);
    else
        throw EX_INVALID_ROLE;
    LOG_VOID_RETURN();
}

int main(int argc, char* argv[])
{
    try
    {
        params_t params = get_params(argc, argv);
        Logger logger;
        LOG_ENTER();
        WsaScope wsaScope;
        NdScope ndScope;
        run(&params);
        LOG_INT_RETURN(0);
    }
    catch (int i)
    {
        fprintf(stderr, "exception %d was caught", i);
    }
    catch (...)
    {
        fprintf(stderr, "uncaught exception");
    }
}
