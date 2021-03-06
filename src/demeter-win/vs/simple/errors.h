#pragma once

#define EX_HELP_CALLED              1
#define EX_INVALID_PARAMS           2
#define EX_INVALID_ROLE             3
#define EX_INVALID_IP               4
#define EX_INVALID_PORT             5
#define EX_RESOLVE_ADDRESS          6
#define EX_OPEN_ADAPTER             7
#define EX_CREATE_OVERLAPPED_FILE   8
#define EX_CREATE_MEMORY_REGION     9
#define EX_QUERY                    10
#define EX_CREATE_COMPLETION_QUEUE  11
#define EX_CREATE_QUEUE_PAIR        12
#define EX_MALLOC                   13
#define EX_REGISTER                 14
#define EX_REGISTER_OV              15
#define EX_INVALID_SIZE             16
#define EX_RECEIVE                  17
#define EX_CREATE_LISTENER          18
#define EX_LISTEN_BIND              19
#define EX_LISTEN                   20
#define EX_CREATE_CONNECTOR         21
#define EX_GET_CONNECTION_REQUEST   22
#define EX_CONNECTOR_BIND           23
#define EX_CONNECT                  24
#define EX_CREATE_EVENT             25
#define EX_NSGE                     26
#define EX_COMPLETE_CONNECT         27
#define EX_NOTIFY                   28
#define EX_ACCEPT                   29
#define EX_SEND                     30
#define EX_GET_OVERLAPPED_RESULT    31
#define EX_DEREGISTER               32

namespace errors
{
    const char* get_string(int error_number);
    const char* get_ndspi_result_string(int hr);
}
