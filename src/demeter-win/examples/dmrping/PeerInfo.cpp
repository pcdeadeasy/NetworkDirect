#include "pch.h"
#include "PeerInfo.h"

void print_peerinfo(const PeerInfo &info, FILE* file)
{
    fprintf(file, "{\n");
    fprintf(file, "    \"RemoteToken\":\"%08X\",\n", info.RemoteToken);
    fprintf(file, "    \"IncommingReadLimit\":\"%08X\",\n", info.IncommingReadLimit);
    fprintf(file, "    \"RemoteAddress\":\"%zX\"\n", info.RemoteAddress);
    fprintf(file, "}\n");
}
