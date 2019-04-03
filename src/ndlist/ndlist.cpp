// This program lists all the available Network Direct IP Addresses

#include "pch.h"

#define INITGUID

#include <stdio.h>
#include <WS2tcpip.h>
#include <Logger.h>
#include <Winshim.h>
#include <ndspi.h>

#define N_PROTOCOLS 25

void process_info(WSAPROTOCOL_INFOW *pInfo);
bool is_nd_provider(const WSAPROTOCOL_INFOW *pInfo);
const wchar_t* get_provider_path(WSAPROTOCOL_INFOW *pInfo);
void print_socket_address(SOCKET_ADDRESS *pSocketAddress);
void process_provider(IND2Provider *pProvider);
void process_socket_address_list(IND2Provider *pProvider, SOCKET_ADDRESS_LIST *pAddressList, ULONG AddressListSize);
void print_provider_id(const WSAPROTOCOL_INFOW *pInfo);

int main()
{
  Logger logger("log.json");
  CWsa wsa;
  WSAPROTOCOL_INFOW infos[N_PROTOCOLS] = { 0 };

  int ErrorNo = 0;
  DWORD BufferLength = (DWORD)sizeof(infos);
  const int nInfos = Win::WSCEnumProtocols(0, infos, &BufferLength, &ErrorNo);
  for (int i = 0; i < nInfos; i++)
  {
    if (!is_nd_provider(infos + i))
      continue;
    printf("\n");
    process_info(infos + i);
  }
}

void process_info(WSAPROTOCOL_INFOW *pInfo)
{
  HRESULT hr;
  ULONG rc;
  void *pv;
  const wchar_t *provider_path;

  print_provider_id(pInfo);
  provider_path = get_provider_path(pInfo);
  CModule mod(provider_path);
  INTERFACE_GETTER DllGetClassObject = (INTERFACE_GETTER)Win::GetProcAddress(mod, "DllGetClassObject");
  pv = 0;
  hr = (*DllGetClassObject)(pInfo->ProviderId, IID_IClassFactory, &pv);
  LOG("DllGetClassObject -> %08X\npClassFactory <- %p", hr, pv);
  if (SUCCEEDED(hr))
  {
    IClassFactory* pClassFactory = (IClassFactory*)pv;
    pv = 0;
    hr = pClassFactory->CreateInstance(0, IID_IND2Provider, &pv);
    LOG("IClassFactory::CreateInstance %p 0 %p %p -> %08X\npProvider <- %p", pClassFactory, &IID_IND2Provider, &pv, hr, pv);
    if (SUCCEEDED(hr))
    {
      IND2Provider* pProvider = (IND2Provider*)pv;
      process_provider(pProvider);
      rc = pProvider->Release();
      LOG("IND2Provider::Release %p -> %u", pProvider, rc);
      pProvider = 0;
    }
    rc = pClassFactory->Release();
    LOG("IClassFactory::Release %p -> %u", pClassFactory, rc);
    pClassFactory = 0;
  }
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

const wchar_t* get_provider_path(WSAPROTOCOL_INFOW *pInfo)
{
  static wchar_t provider_path[MAX_PATH];
  static wchar_t raw_provider_path[MAX_PATH];
  int ErrorNo = 0;
  int path_len = _countof(raw_provider_path);
  Win::WSCGetProiderPath(&pInfo->ProviderId, raw_provider_path, &path_len, &ErrorNo);
  Win::ExpandEnvironmentStringsW(raw_provider_path, provider_path, _countof(provider_path));
  return provider_path;
}

void print_socket_address(SOCKET_ADDRESS *pSocketAddress)
{
  wchar_t buffer[100];
  union
  {
    char* data;
    sockaddr_in  *sa_in;
    sockaddr_in6 *sa_in6;
  };
  void *pv = 0;
  if (pSocketAddress->lpSockaddr->sa_family == AF_INET)
  {
    pv = &(((sockaddr_in*)pSocketAddress->lpSockaddr)->sin_addr);
  }
  else if (pSocketAddress->lpSockaddr->sa_family == AF_INET6)
  {
    pv = &(((sockaddr_in6*)pSocketAddress->lpSockaddr)->sin6_addr);
  }
  else
  {
    return;
  }
  PCWSTR pAddressString = InetNtopW(pSocketAddress->lpSockaddr->sa_family, pv, buffer, _countof(buffer));
  printf("%S\n", pAddressString);
}

void process_provider(IND2Provider *pProvider)
{
  HRESULT hr;
  ULONG AddressListSize = 0;
  hr = pProvider->QueryAddressList(0, &AddressListSize);
  LOG("IND2Provider::QueryAddressList %p 0 %p -> %08X\nAddressListSize <- %zx", pProvider, &AddressListSize, AddressListSize);
  if (hr == ND_BUFFER_OVERFLOW)
  {
    SOCKET_ADDRESS_LIST *pAddressList = (SOCKET_ADDRESS_LIST*)malloc(AddressListSize);
    if (pAddressList)
    {
      process_socket_address_list(pProvider, pAddressList, AddressListSize);
      free(pAddressList);
      pAddressList = 0;
    }
  }
}

void process_socket_address_list(IND2Provider *pProvider, SOCKET_ADDRESS_LIST *pAddressList, ULONG AddressListSize)
{
  HRESULT hr = pProvider->QueryAddressList(pAddressList, &AddressListSize);
  LOG("IND2Provider::QueryAddressList %p %p %p -> %08X\nAddressListSize <- %u", pProvider, pAddressList, &AddressListSize, hr, AddressListSize);
  if (SUCCEEDED(hr))
  {
    for (int i = 0; i < pAddressList->iAddressCount; i++)
    {
      SOCKET_ADDRESS* pAddress = pAddressList->Address + i;
      ADDRESS_FAMILY family = pAddress->lpSockaddr->sa_family;
      if (family == AF_INET || family == AF_INET6)
      {
        print_socket_address(pAddress);
      }
    }
  }
}

void print_provider_id(const WSAPROTOCOL_INFOW *pInfo)
{
  wchar_t buffer[64];
  LPOLESTR lpsz = buffer;
  int nChars = StringFromGUID2(pInfo->ProviderId, lpsz, _countof(buffer));
  LOG("StringFromGUID2 %p %p %u -> %d", &pInfo->ProviderId, lpsz, _countof(buffer), nChars);
  if (nChars > 0)
  {
    printf("%S\n", lpsz);
  }
}
