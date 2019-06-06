#pragma once
#include <ndcommon.h>

class NdScope
{
public:
    NdScope()
    {
        if (FAILED(NdStartup()))
            throw "NdStartup";
    }
    ~NdScope()
    {
        NdCleanup();
    }
};
