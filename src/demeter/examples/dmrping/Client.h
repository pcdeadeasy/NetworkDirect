#pragma once
#include <ndcommon.h>
#include <ndtestutil.h>
#include <WinHeap.h>
#include "Params.h"

class Client
{
public:
    Client(Params &params);
    ~Client();
    void RunTest(const struct sockaddr_in& v4Src, const struct sockaddr_in &v4Dst, DWORD queueDepth, DWORD nSge);

private:
    Params &m_params;
    ULONG m_availCredits;
};

