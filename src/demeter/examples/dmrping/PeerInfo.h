#pragma once
#include <stdio.h>

typedef struct _PeerInfo {
    unsigned int RemoteToken;           // 32 bits
    unsigned int IncommingReadLimit;    // 32 bits
    unsigned __int64 RemoteAddress;     // 64 bits
} PeerInfo;

void print_peerinfo(const PeerInfo &info, FILE* file);