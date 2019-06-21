#define INITGUID

#include "pch.h"
#include <stdio.h>
#include "ndscope.h"
#include "Params.h"


void main1(Params&);

int main(int argc, char* argv[])
{
    int rc = 0;
    Logger logger("log.json");
    try 
    {
        Params params(argc, argv);
        WsaScope wsa; // Socket Support Environment
        NdScope nd;   // Network Direct Environment
        main1(params);
        rc = 0;
    }
    catch (...)
    {
        Params::ShowUsage();
        rc = -1;
    }
    return rc;
}
