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
bool is_nd2_provider(const WSAPROTOCOL_INFOW *pInfo);
const wchar_t* get_provider_path(WSAPROTOCOL_INFOW *pInfo);
void print_socket_address(SOCKET_ADDRESS *pSocketAddress);
void process_provider(IND2Provider *pProvider);
void process_socket_address_list(IND2Provider *pProvider, SOCKET_ADDRESS_LIST *pAddressList, ULONG AddressListSize);
void print_provider_id(const WSAPROTOCOL_INFOW *pInfo);
void print_wsaprotocol_infow(const WSAPROTOCOL_INFOW *pInfo);

int main()
{
    Logger logger("log.json");
    LOG_ENTER();
    WsaScope wsa;
    WSAPROTOCOL_INFOW infos[N_PROTOCOLS] = { 0 };

    int ErrorNo = 0;
    DWORD BufferLength = (DWORD)sizeof(infos);
    const int nInfos = Win::WSCEnumProtocols(0, infos, &BufferLength, &ErrorNo);
    for (int i = 0; i < nInfos; i++)
    {
        if (!is_nd2_provider(infos + i))
            continue;
        printf("\n");
        process_info(infos + i);
    }
    LOG_VOID_RETURN();
}

void process_info(WSAPROTOCOL_INFOW *pInfo)
{
    LOG_ENTER();
    HRESULT hr;
    ULONG rc;
    void *pv;
    const wchar_t *provider_path;

    print_wsaprotocol_infow(pInfo);
    provider_path = get_provider_path(pInfo);
    CModule mod(provider_path);
    INTERFACE_GETTER DllGetClassObject = (INTERFACE_GETTER)Win::GetProcAddress(mod, "DllGetClassObject");
    pv = 0;
    hr = (*DllGetClassObject)(pInfo->ProviderId, IID_IClassFactory, &pv);
    LOG("DllGetClassObject -> %08X", hr);
    if (SUCCEEDED(hr))
    {
        IClassFactory* pClassFactory = (IClassFactory*)pv;
        pv = 0;
        hr = pClassFactory->CreateInstance(0, IID_IND2Provider, &pv);
        LOG("IClassFactory::CreateInstance %p 0 %p %p -> %08X", pClassFactory, &IID_IND2Provider, &pv, hr);
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
    LOG_VOID_RETURN();
}

bool is_nd2_provider(const WSAPROTOCOL_INFOW *pInfo)
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
    if (pInfo->iVersion != 0x20000)
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
    LOG_ENTER();
    HRESULT hr;
    ULONG AddressListSize = 0;
    hr = pProvider->QueryAddressList(0, &AddressListSize);
    LOG("IND2Provider::QueryAddressList %p 0 %p -> %08X", pProvider, &AddressListSize, hr);
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
    LOG_VOID_RETURN();
}

void process_socket_address_list(IND2Provider *pProvider, SOCKET_ADDRESS_LIST *pAddressList, ULONG AddressListSize)
{
    LOG_ENTER();
    HRESULT hr = pProvider->QueryAddressList(pAddressList, &AddressListSize);
    LOG("IND2Provider::QueryAddressList %p %p %p -> %08X", pProvider, pAddressList, &AddressListSize, hr);
    if (SUCCEEDED(hr))
    {
        for (int i = 0; i < pAddressList->iAddressCount; i++)
        {
            SOCKET_ADDRESS* pAddress = pAddressList->Address + i;
            ADDRESS_FAMILY family = pAddress->lpSockaddr->sa_family;
            if (family == AF_INET || family == AF_INET6)
            {
                print_socket_address(pAddress);
                //UINT64 AdapterId = 0;
                //HRESULT hr1 = pProvider->ResolveAddress((const sockaddr*)pAddress->lpSockaddr, sizeof(sockaddr_in6), &AdapterId);
                //printf("hr1 <- %08X\n", hr1);
                //printf("AdapterId <- %I64X\n", AdapterId);
                //if (!SUCCEEDED(hr1))
                //    break;
                //IND2Adapter *pAdapter = 0;
                //HRESULT hr2 = pProvider->OpenAdapter(IID_IND2Adapter, AdapterId, (void**)&pAdapter);
                //printf("hr2 <- %08X\n", hr2);
                //printf("pAdapter <- %p\n", pAdapter);
                //if (!SUCCEEDED(hr2))
                //    break;
                //ND2_ADAPTER_INFO AdapterInfo = { 0 };
                //AdapterInfo.InfoVersion = 1;
                //ULONG cbInfo = sizeof(AdapterInfo);
                //HRESULT hr3 = pAdapter->Query(&AdapterInfo, &cbInfo);
                //printf("hr3 <- %08X\n", hr3);
                //printf("cbInfo <- %08X\n", cbInfo);
                //if (!SUCCEEDED(hr3))
                //    break;
                //printf("VendorId: %u\n", AdapterInfo.VendorId);
                //break;
            }
        }
    }
    LOG_VOID_RETURN();
}

void print_provider_id(const WSAPROTOCOL_INFOW *pInfo)
{
    LOG_ENTER();
    wchar_t buffer[64];
    LPOLESTR lpsz = buffer;
    int nChars = StringFromGUID2(pInfo->ProviderId, lpsz, _countof(buffer));
    LOG("StringFromGUID2 %p %p %u -> %d", &pInfo->ProviderId, lpsz, _countof(buffer), nChars);
    if (nChars > 0)
    {
        printf("%S\n", lpsz);
    }
    LOG_VOID_RETURN();
}

void print_wsaprotocol_infow(const WSAPROTOCOL_INFOW *pInfo)
{
    wchar_t buffer[64];
    LPOLESTR lpsz = buffer;
    int nChars = StringFromGUID2(pInfo->ProviderId, lpsz, _countof(buffer));
    printf("WSAPROTCOL_INFOW:\n");
    printf("{\n");
    printf("    \"dwServiceFlags1\":\"%08X\",\n", pInfo->dwServiceFlags1);
    printf("    \"dwServiceFlags2\":\"%08X\",\n", pInfo->dwServiceFlags2);
    printf("    \"dwServiceFlags3\":\"%08X\",\n", pInfo->dwServiceFlags3);
    printf("    \"dwServiceFlags4\":\"%08X\",\n", pInfo->dwServiceFlags4);
    printf("    \"ProviderId\":\"%S\",\n", buffer);
    printf("    \"dwCatalogEntryId\":\"%08X\",\n", pInfo->dwCatalogEntryId);
    printf("    \"ProtocolChain\": {\n");
    printf("        \"ChainLen\":%d,\n", pInfo->ProtocolChain.ChainLen);
    printf("        \"ChainEntries\":[\n");
    for (int i = 0; i < MAX_PROTOCOL_CHAIN; i++)
    {
        if (i == 0)
            printf("            \"%08X\"", pInfo->ProtocolChain.ChainEntries[0]);
        else
            printf(",\n            \"%08X\"", pInfo->ProtocolChain.ChainEntries[i]);
    }
    printf("\n        ]\n");
    printf("    },\n");
    printf("    \"iVersion\":\"%08X\",\n", pInfo->iVersion);
    printf("    \"iAddressFamily\":%d,\n", pInfo->iAddressFamily);
    printf("    \"iMaxSockAddr\":%d,\n", pInfo->iMaxSockAddr);
    printf("    \"iMinSockAddr\":%d,\n", pInfo->iMinSockAddr);
    printf("    \"iSocketType\":%d,\n", pInfo->iSocketType);
    printf("    \"iProtocol\":%d,\n", pInfo->iProtocol);
    printf("    \"iProtocolMaxOffset\":%d,\n", pInfo->iProtocolMaxOffset);
    printf("    \"iNetworkByteOrder\":%d,\n", pInfo->iNetworkByteOrder);
    printf("    \"iSecurityScheme\":%d,\n", pInfo->iSecurityScheme);
    printf("    \"dwMessageSize\":\"%08X\",\n", pInfo->dwMessageSize);
    printf("    \"dwProviderReserved\":\"%08X\",\n", pInfo->dwProviderReserved);
    printf("    \"szProtocol\":\"%S\"\n", pInfo->szProtocol);
    printf("}\n");
}
