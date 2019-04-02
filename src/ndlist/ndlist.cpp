// This program lists all the available Network Direct IP Addresses

#include "pch.h"
#include <stdio.h>
#include <Logger.h>
#include <Winshim.h>

#define N_PROTOCOLS 25

void process_info(WSAPROTOCOL_INFOW *pInfo);
bool is_nd_provider(const WSAPROTOCOL_INFOW *pInfo);

int main()
{
  Logger logger(0);
  CWsa wsa;
  WSAPROTOCOL_INFOW infos[N_PROTOCOLS] = { 0 };

  int ErrorNo = 0;
  DWORD BufferLength = (DWORD)sizeof(infos);
  const int nInfos = Win::WSCEnumProtocols(0, infos, &BufferLength, &ErrorNo);
  for (int i = 0; i < nInfos; i++)
  {
    if (is_nd_provider(infos + i))
    {
      try
      {
        process_info(infos + i);
      }
      catch (Win::Error)
      {
      }
    }
  }
}

void process_info(WSAPROTOCOL_INFOW *pInfo)
{
  wchar_t provider_path[MAX_PATH] = { 0 };
  wchar_t raw_provider_path[MAX_PATH] = { 0 };
  int ErrorNo = 0;
  int path_len = _countof(raw_provider_path);
  Win::WSCGetProiderPath(&pInfo->ProviderId, raw_provider_path, &path_len, &ErrorNo);
  Win::ExpandEnvironmentStringsW(raw_provider_path, provider_path, _countof(provider_path));
  CModule mod(provider_path);
  INTERFACE_GETTER DllGetClassObject = (INTERFACE_GETTER)Win::GetProcAddress(mod, "DllGetClassObject");
  
}

bool is_nd_provider(const WSAPROTOCOL_INFOW *pInfo)
{
  const DWORD service_flags = XP1_GUARANTEED_DELIVERY |
    XP1_GUARANTEED_ORDER |
    XP1_MESSAGE_ORIENTED |
    XP1_CONNECT_DATA;
  const DWORD provider_flags = PFL_HIDDEN |
    PFL_NETWORKDIRECT_PROVIDER;

  if ((pInfo->dwServiceFlags1 & service_flags) != service_flags)
    return false;
  if ((pInfo->dwProviderFlags & provider_flags) != provider_flags)
    return false;
  if (!(pInfo->iAddressFamily == AF_INET || pInfo->iAddressFamily == AF_INET6))
    return false;
  if (pInfo->iSocketType != -1)
    return false;
  if (pInfo->iProtocol != 0)
    return false;
  if (pInfo->iProtocolMaxOffset != 0)
    return false;
  return true;
}
