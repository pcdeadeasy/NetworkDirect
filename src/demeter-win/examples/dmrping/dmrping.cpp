#define INITGUID
#include "pch.h"
#include <iostream>
#include "../../libraries/logger/Logger.h"
#include "../../libraries/Winshim/Winshim.h"
#include "../../libraries/ndutil/ndutil.h"
#include "../../libraries/ndutil/ndtestutil.h"
#include "../../libraries/Utils/Utils.h"
#include "Params.h"
#include "Server.h"
#include "Client.h"

struct sockaddr_in GetSocketAddress(LPSTR ip, USHORT Port)
{
    struct sockaddr_in v4Svr = { 0 };
    int AddressLength = (int)sizeof(v4Svr);
#pragma warning( push )
#pragma warning( disable : 4996 ) // suppress deprecation warning
    Win::WSAStringToAddressA(ip, AF_INET, 0, (sockaddr*)&v4Svr, &AddressLength);
#pragma warning( pop )
    v4Svr.sin_port = htons(Port);
    return v4Svr;
}

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

void work1(Params& params)
{
    LOG_ENTER();
    struct sockaddr_in v4Svr = GetSocketAddress(params.Ip, params.Port);
    if (params.Server)
    {
        Server server(params);
        server.RunTest(v4Svr, 0, (DWORD)params.nSge);
    }
    else if (params.Client)
    {
        struct sockaddr_in v4Src = { 0 };
        size_t len = sizeof(v4Src);
        if FAILED(NdResolveAddress((const struct sockaddr*)&v4Svr, sizeof(v4Svr), (struct sockaddr*)&v4Src, &len))
            throw "NdResolveAddress";
        Client client(params);
        client.RunTest(v4Src, v4Svr, 0, (DWORD)params.nSge);
    }
    LOG_VOID_RETURN();
}

void work0(Params& params)
{
    Logger logger;
    LOG_ENTER();
    WsaScope wsaScope;
    NdScope ndScope;
    work1(params);
    LOG_VOID_RETURN();
}

int main(int argc, char **argv)
{
    int rc;
    try
    {
        Params params(argc, argv);
        params.Print();
        params.Save("params.json");
        work0(params);
        rc = 0;
    }
    catch (...)
    {
        Params::ShowUsage();
        rc = 1;
    }
    return rc;
}
