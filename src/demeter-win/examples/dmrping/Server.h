#pragma once
#include "../../libraries/ndutil/ndutil.h"
#include "../../libraries/ndutil/ndtestutil.h"
#include "../../libraries/ndutil/ndsupport.h"
#include "../../libraries/ndutil/include/ndcommon.h"
#include "../../libraries/Winshim/WinHeap.h"
#include "Params.h"


class Server : public NdTestServerBase
{
public:
    Server(Params &params);
    ~Server();
    void RunTest(const struct sockaddr_in& v4Src, DWORD queueDepth, DWORD nSge);

private:
    Params &m_params;
    void work(const struct sockaddr_in& v4Src);
    ND2_ADAPTER_INFO initialize(BUFFER<char> &Buf);
    void post_receive_for_terminate_message(BUFFER<char> &buf);
    ND2_SGE get_sge(BUFFER<char> &buf);
    void send_remote_token_and_address(ND2_ADAPTER_INFO &info, BUFFER<char> &buf);
};

