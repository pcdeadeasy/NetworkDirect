#pragma once

#include <string>
#include <stdint.h>

typedef struct _params {
    std::string role;           // 'client' or 'server'
    std::string ip;             // ip address of the server
    uint16_t port;
    size_t size;                // size of the single memory buffer
    uint32_t backlog;           // used for the call to Listen
    uint32_t queue_depth;
    uint32_t nsge;              // maximum number of sge's supported the queue pair
} params_t;

params_t get_params(int argc, char* argv[]);
