//#include <stdio.h>
//#include <libraries/logger/Logger.h>
#include <libraries/Winshim/Winshim.h>
//#include <libraries/ndutil/ndutil.h>
//#include <libraries/ndutil/ndtestutil.h>
//#include "params.h"
//#include "ndscope.h"
#include "errors.h"
//#include "State.h"
#include "ndspi.h"
#include <unordered_map>


static void init_emap(std::unordered_map<int, const char*>& emap)
{
#define DEFINE(x) emap[x] = #x

    DEFINE(EX_HELP_CALLED);
    DEFINE(EX_INVALID_PARAMS);
    DEFINE(EX_INVALID_ROLE);
    DEFINE(EX_INVALID_IP);
    DEFINE(EX_INVALID_PORT);
    DEFINE(EX_RESOLVE_ADDRESS);
    DEFINE(EX_OPEN_ADAPTER);
    DEFINE(EX_CREATE_OVERLAPPED_FILE);
    DEFINE(EX_CREATE_MEMORY_REGION);
    DEFINE(EX_QUERY);
    DEFINE(EX_CREATE_COMPLETION_QUEUE);
    DEFINE(EX_CREATE_QUEUE_PAIR);
    DEFINE(EX_MALLOC);
    DEFINE(EX_REGISTER);
    DEFINE(EX_REGISTER_OV);
    DEFINE(EX_INVALID_SIZE);
    DEFINE(EX_RECEIVE);
    DEFINE(EX_CREATE_LISTENER);
    DEFINE(EX_LISTEN_BIND);
    DEFINE(EX_LISTEN);
    DEFINE(EX_CREATE_CONNECTOR);
    DEFINE(EX_GET_CONNECTION_REQUEST);
    DEFINE(EX_CONNECTOR_BIND);
    DEFINE(EX_CONNECT);
    DEFINE(EX_CREATE_EVENT);
    DEFINE(EX_NSGE);
    DEFINE(EX_COMPLETE_CONNECT);
    DEFINE(EX_NOTIFY);
    DEFINE(EX_ACCEPT);
    DEFINE(EX_SEND);
    DEFINE(EX_GET_OVERLAPPED_RESULT);
    DEFINE(EX_DEREGISTER);

#undef DEFINE
}


static void init_ndspi_emap(std::unordered_map<int, const char*>& emap)
{
#define DEFINE(x) emap[x] = #x
    DEFINE(ND_SUCCESS);
    DEFINE(ND_TIMEOUT);
    DEFINE(ND_PENDING);
    DEFINE(ND_BUFFER_OVERFLOW);
    DEFINE(ND_DEVICE_BUSY);
    DEFINE(ND_NO_MORE_ENTRIES);
    DEFINE(ND_UNSUCCESSFUL);
    DEFINE(ND_ACCESS_VIOLATION);
    DEFINE(ND_INVALID_HANDLE);
    DEFINE(ND_INVALID_DEVICE_REQUEST);
    DEFINE(ND_INVALID_PARAMETER);
    DEFINE(ND_NO_MEMORY);
    DEFINE(ND_INVALID_PARAMETER_MIX);
    DEFINE(ND_DATA_OVERRUN);
    DEFINE(ND_SHARING_VIOLATION);
    DEFINE(ND_INSUFFICIENT_RESOURCES);
    DEFINE(ND_DEVICE_NOT_READY);
    DEFINE(ND_IO_TIMEOUT);
    DEFINE(ND_NOT_SUPPORTED);
    DEFINE(ND_INTERNAL_ERROR);
    DEFINE(ND_INVALID_PARAMETER_1);
    DEFINE(ND_INVALID_PARAMETER_2);
    DEFINE(ND_INVALID_PARAMETER_3);
    DEFINE(ND_INVALID_PARAMETER_4);
    DEFINE(ND_INVALID_PARAMETER_5);
    DEFINE(ND_INVALID_PARAMETER_6);
    DEFINE(ND_INVALID_PARAMETER_7);
    DEFINE(ND_INVALID_PARAMETER_8);
    DEFINE(ND_INVALID_PARAMETER_9);
    DEFINE(ND_INVALID_PARAMETER_10);
    DEFINE(ND_CANCELED);
    DEFINE(ND_REMOTE_ERROR);
    DEFINE(ND_INVALID_ADDRESS);
    DEFINE(ND_INVALID_DEVICE_STATE);
    DEFINE(ND_INVALID_BUFFER_SIZE);
    DEFINE(ND_TOO_MANY_ADDRESSES);
    DEFINE(ND_ADDRESS_ALREADY_EXISTS);
    DEFINE(ND_CONNECTION_REFUSED);
    DEFINE(ND_CONNECTION_INVALID);
    DEFINE(ND_CONNECTION_ACTIVE);
    DEFINE(ND_NETWORK_UNREACHABLE);
    DEFINE(ND_HOST_UNREACHABLE);
    DEFINE(ND_CONNECTION_ABORTED);
    DEFINE(ND_DEVICE_REMOVED);
#undef DEFINE
}

const char* errors::get_string(int n)
{
    static std::unordered_map<int, const char*> emap;
    if (emap.empty())
    {
        init_emap(emap);
    }
    if (emap.find(n) == emap.end())
    {
        return "undefined exception";
    }
    return emap[n];
}

const char* errors::get_ndspi_result_string(int hr)
{
    static std::unordered_map<int, const char*> emap;
    if (emap.empty())
    {
        init_ndspi_emap(emap);
    }
    if (emap.find(hr) == emap.end())
    {
        return "undefined exception";
    }
    return emap[hr];
}
