#include "errors.h"
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