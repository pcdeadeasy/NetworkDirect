#pragma once
#include <libraries/ndutil/ndutil.h>
#include <libraries/ndutil/ndtestutil.h>

class State
{
public:
    State();
    ~State();

    void InitClient(
        const char* server_ip_address,
        uint16_t server_port,
        uint32_t queue_depth,
        size_t memory_block_size,
        uint32_t nsge
    );

    void InitServer(
        const char* server_ip_address,
        uint16_t server_port,
        uint32_t queue_depth,
        size_t memory_block_size,
        uint32_t nsge
    );

public:
    struct sockaddr_in LocalAddress;
    struct sockaddr_in RemoteAddress;
    IND2Adapter* pAdapter;
    HANDLE hOverlappedFile;
    IND2MemoryRegion* pMemoryRegion;
    ND2_ADAPTER_INFO Info;
    IND2CompletionQueue* pCompletionQueue;
    IND2QueuePair* pQueuePair;
    IND2Connector* pConnector;
    IND2Listener* pListener;
    void* buffer;
    size_t buffer_size;
    OVERLAPPED ov;
};

