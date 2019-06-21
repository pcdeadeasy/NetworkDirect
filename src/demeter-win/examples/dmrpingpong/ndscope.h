#pragma once

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
