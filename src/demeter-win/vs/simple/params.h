#pragma once

#include <string>
#include <stdint.h>

typedef struct _params {
    std::string role;
    std::string ip;
    uint16_t port;
    size_t size;
    uint32_t backlog;
    uint32_t queue_depth;
    uint32_t nsge;              // maximum number of sge's supported the queue pair
} params_t;

params_t get_params(int argc, char* argv[]);
