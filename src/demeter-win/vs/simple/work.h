#pragma once
#include <libraries/ndutil/ndutil.h>
#include <libraries/ndutil/ndtestutil.h>
#include "params.h"

typedef struct sockaddr (*get_local_address_t)(LPSTR, uint16_t);

typedef void(*work_t)(
    params_t* const params,
    const struct sockaddr* pAddress,
    IND2Adapter* const pAdapter,
    HANDLE const hOverlappedFile,
    IND2MemoryRegion* const pMemoryRegion,
    ND2_ADAPTER_INFO const* const pInfo,
    IND2CompletionQueue* const pSendCompletionQueue,
    IND2CompletionQueue* const pRecvCompletionQueue,
    IND2QueuePair* const pQueuePair
    );

void work(
    params_t* const params,
    work_t work,
    get_local_address_t get_local_address
);

SOCKADDR get_sockaddr(LPSTR AddressString, INT AddressFamily, uint16_t port);
void RegisterMemory(IND2MemoryRegion* pMemoryRegion, void* buffer, size_t size);
void DeregisterMemory(IND2MemoryRegion* pMemoryRegion);
