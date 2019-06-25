#pragma once
#include "../../libraries/ndutil/ndutil.h"
#include "../../libraries/ndutil/ndtestutil.h"
#include "../../libraries/ndutil/ndsupport.h"
#include "../../libraries/ndutil/include/ndcommon.h"
#include "../../libraries/Winshim/WinHeap.h"
#include "Params.h"

class Client : public NdTestClientBase
{
public:
    Client(Params &params);
    ~Client();
    void RunTest(const struct sockaddr_in& v4Src, const struct sockaddr_in &v4Dst, DWORD queueDepth, DWORD nSge);

private:

    void Work(const struct sockaddr_in& v4Src, const struct sockaddr_in &v4Dst, DWORD queueDepth, DWORD nSge);
    void register_data_buffer(BUFFER<char> &buf);
    Params &m_params;
    ULONG m_availCredits;
    ND2_ADAPTER_INFO const get_adapter_info();
    void post_receive(BUFFER<char> &buf);
    void send_terminate_message();
};

