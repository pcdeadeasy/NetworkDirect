#include "pch.h"
#include <Logger.h>
#include "Client.h"


Client::Client(Params &params) : m_params(params),
                                 m_availCredits(0)
{
    LOG_ENTER();
    LOG_VOID_RETURN();
}


Client::~Client()
{
    LOG_ENTER();
    LOG_VOID_RETURN();
}


void Client::RunTest(const struct sockaddr_in& v4Src, const struct sockaddr_in &v4Dst, DWORD queueDepth, DWORD nSge)
{
    LOG_ENTER();
    LOG_VOID_RETURN();
}