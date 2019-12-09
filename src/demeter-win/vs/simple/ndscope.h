#pragma once

#include <libraries/ndutil/ndutil.h>
#include <libraries/ndutil/ndtestutil.h>

class NdScope
{
public:
    NdScope()
    {
        if (NdStartup() != 0)
            throw "NdStartup";
    }
    ~NdScope()
    {
        NdCleanup();
    }
};
