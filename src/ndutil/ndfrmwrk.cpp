//
// Copyright(c) Microsoft Corporation.All rights reserved.
// Licensed under the MIT License.
//


#include "precomp.h"
#include "ndsupport.h"
#include "ndaddr.h"
#include "ndprov.h"
#include "ndfrmwrk.h"

namespace NetworkDirect
{

    //
    // PFL_NETWORKDIRECT_PROVIDER should come from WinSock2.h, but may not be
    // defined depending on which SDK is being used.  We define it here in case
    // it isn't defined yet.
    //
#ifndef PFL_NETWORKDIRECT_PROVIDER
#define PFL_NETWORKDIRECT_PROVIDER 0x00000010
#endif

//
// Flags for checking that a WSAPROTOCOL_INFO structure is a ND provider.
//
    static const int ND_SERVICE_FLAGS1 = (XP1_GUARANTEED_DELIVERY | XP1_GUARANTEED_ORDER |
        XP1_MESSAGE_ORIENTED | XP1_CONNECT_DATA);
    static const int ND_PROVIDER_FLAGS = (PFL_HIDDEN | PFL_NETWORKDIRECT_PROVIDER);


    volatile LONG gInitializing = 0;
    HANDLE ghHeap = nullptr;
    NetworkDirect::Framework* gpFramework = nullptr;


    Framework::Framework() :
        m_hIocp(nullptr),
        m_hProviderChange(nullptr),
        m_Socket(INVALID_SOCKET),
        m_nRef(0)
    {
        LOG_ENTER();
        InitializeCriticalSection(&m_lock);
        ::ZeroMemory(m_Ov, sizeof(m_Ov));
        LOG_VOID_RETURN();
    }


    Framework::~Framework()
    {
        LOG_ENTER();
        while (!m_NdAddrList.empty())
        {
            Address* pAddr = &m_NdAddrList.front();
            m_NdAddrList.pop_front();
            delete pAddr;
        }

        while (!m_NdV1AddrList.empty())
        {
            Address* pAddr = &m_NdV1AddrList.front();
            m_NdV1AddrList.pop_front();
            delete pAddr;
        }

        FlushProviders();

        while (!m_ProviderList.empty())
        {
            Provider* pProvider = &m_ProviderList.front();
            m_ProviderList.pop_front();
            delete pProvider;
        }

        if (m_hProviderChange != nullptr)
        {
            ::CloseHandle(m_hProviderChange);
        }

        if (m_Socket != INVALID_SOCKET)
        {
            ::closesocket(m_Socket);
        }

        if (m_hIocp != nullptr)
        {
            ::CloseHandle(m_hIocp);
        }

        DeleteCriticalSection(&m_lock);
        LOG_VOID_RETURN();
    }


    HRESULT
        Framework::Init()
    {
        LOG_ENTER();
        int ret;
        WSADATA data;

        ASSERT(m_nRef == 0);

        ret = ::WSAStartup(MAKEWORD(2, 2), &data);
        if (ret != 0)
        {
            HRESULT hr = HRESULT_FROM_WIN32(ret);
            LOG_HRESULT_RETURN(hr);
            return hr;
        }

        // Create an IOCP to get all the different notifications:
        // - provider change
        // - address change
        m_hIocp = ::CreateIoCompletionPort(INVALID_HANDLE_VALUE, nullptr, 0, 0);
        if (m_hIocp == nullptr)
        {
            HRESULT hr = HRESULT_FROM_WIN32(::GetLastError());
            LOG_HRESULT_RETURN(hr);
            return hr;
        }

        // Create a socket for address changes.
        m_Socket = ::WSASocketW(AF_INET, SOCK_STREAM, 0, nullptr, 0, WSA_FLAG_OVERLAPPED);
        if (m_Socket == INVALID_SOCKET)
        {
            HRESULT hr = HRESULT_FROM_WIN32(::WSAGetLastError());
            LOG_HRESULT_RETURN(hr);
            return hr;
        }

        // Bind the socket change handle to the IOCP.
        HANDLE hIocp = ::CreateIoCompletionPort(
            reinterpret_cast<HANDLE>(m_Socket), m_hIocp, ND_NOTIFY_ADDR_CHANGE, 0);
        if (hIocp != m_hIocp)
        {
            HRESULT hr = HRESULT_FROM_WIN32(::GetLastError());
            LOG_HRESULT_RETURN(hr);
            return hr;
        }

        // Get provider change notification handle.
        ret = ::WSAProviderConfigChange(&m_hProviderChange, nullptr, nullptr);
        if (ret != 0)
        {
            HRESULT hr = HRESULT_FROM_WIN32(::WSAGetLastError());
            LOG_HRESULT_RETURN(hr);
            return hr;
        }

        // Bind the provider change handle to the IOCP.
        __analysis_assume(m_hProviderChange != nullptr);
        hIocp = ::CreateIoCompletionPort(
            m_hProviderChange, m_hIocp, ND_NOTIFY_PROVIDER_CHANGE, 0);
        if (hIocp != m_hIocp)
        {
            HRESULT hr = HRESULT_FROM_WIN32(::GetLastError());
            LOG_HRESULT_RETURN(hr);
            return hr;
        }

        // Request address change notification.
        DWORD BytesRet;
        ret = ::WSAIoctl(m_Socket, SIO_ADDRESS_LIST_CHANGE, nullptr, 0, nullptr,
            0, &BytesRet, &m_Ov[ND_NOTIFY_ADDR_CHANGE], nullptr);
        if (ret != 0 && WSAGetLastError() != WSA_IO_PENDING)
        {
            HRESULT hr = HRESULT_FROM_WIN32(::WSAGetLastError());
            LOG_HRESULT_RETURN(hr);
            return hr;
        }

        // Generate a provider change notification, so that the next call that
        // looks at the provider catalog will update it first.
        ret = ::PostQueuedCompletionStatus(m_hIocp, 0, ND_NOTIFY_PROVIDER_CHANGE,
            &m_Ov[ND_NOTIFY_PROVIDER_CHANGE]);
        if (ret == FALSE)
        {
            HRESULT hr = HRESULT_FROM_WIN32(::GetLastError());
            LOG_HRESULT_RETURN(hr);
            return hr;
        }

        LOG_HRESULT_RETURN(S_OK);
        return S_OK;
    }


    ULONG
        Framework::AddRef()
    {
        LOG_ENTER();
        ULONG ans = ::InterlockedIncrement(&m_nRef);
        LOG_ULONG_RETURN(ans);
        return ans;
    }


    ULONG
        Framework::Release()
    {
        LOG_ENTER();
        ASSERT(m_nRef > 0);

        ULONG nRef = ::InterlockedDecrement(&m_nRef);

        if (nRef == 0)
        {
            delete this;
        }
        LOG_ULONG_RETURN(nRef);
        return nRef;
    }


    HRESULT
        Framework::QueryAddressList(
            _In_ DWORD flags,
            _Out_opt_bytecap_post_bytecount_(*pcbAddressList, *pcbAddressList) SOCKET_ADDRESS_LIST* pAddressList,
            _Inout_ SIZE_T* pcbAddressList
        )
    {
        LOG_ENTER();
        // Sync our provider and address lists
        ProcessUpdates();

        Lock lock(&m_lock);

        // Calculate the size of the buffer we need.  We count the number of v4 and
        // v6 addresses.
        SIZE_T nV4 = 0;
        SIZE_T nV6 = 0;

        if ((flags & ND_QUERY_EXCLUDE_NDv2_ADDRESSES) == 0)
        {
            CountAddresses(m_NdAddrList, &nV4, &nV6);
        }

        if ((flags & ND_QUERY_EXCLUDE_NDv1_ADDRESSES) == 0)
        {
            CountAddresses(m_NdV1AddrList, &nV4, &nV6);
        }

        if (nV4 == 0 && nV6 == 0)
        {
            *pcbAddressList = 0;
            LOG_HRESULT_RETURN(ND_SUCCESS);
            return ND_SUCCESS;
        }

        SIZE_T cbRequired = sizeof(SOCKET_ADDRESS_LIST) - sizeof(SOCKET_ADDRESS) +
            (sizeof(SOCKET_ADDRESS) * (nV4 + nV6)) +
            (sizeof(sockaddr_in) * nV4) + (sizeof(sockaddr_in6) * nV6);

        if (pAddressList == nullptr || cbRequired > *pcbAddressList)
        {
            *pcbAddressList = cbRequired;
            LOG_HRESULT_RETURN(ND_BUFFER_OVERFLOW);
            return ND_BUFFER_OVERFLOW;
        }

        BYTE* pBuf = reinterpret_cast<BYTE*>(
            &pAddressList->Address[(nV4 + nV6)]);
        SIZE_T cbRemaining = *pcbAddressList -
            FIELD_OFFSET(SOCKET_ADDRESS_LIST, Address[(nV4 + nV6)]);

        pAddressList->iAddressCount = 0;

        if ((flags & ND_QUERY_EXCLUDE_NDv2_ADDRESSES) == 0)
        {
            CopyAddressList(m_NdAddrList, pAddressList, &pBuf, &cbRemaining);
        }

        if ((flags & ND_QUERY_EXCLUDE_NDv1_ADDRESSES) == 0)
        {
            CopyAddressList(m_NdV1AddrList, pAddressList, &pBuf, &cbRemaining);
        }

        LOG_HRESULT_RETURN(S_OK);
        return S_OK;
    }


    HRESULT
        Framework::ResolveAddress(
            _In_bytecount_(cbRemoteAddress) const struct sockaddr* pRemoteAddress,
            _In_ SIZE_T cbRemoteAddress,
            _Out_bytecap_(*pcbLocalAddress) struct sockaddr* pLocalAddress,
            _Inout_ SIZE_T* pcbLocalAddress
        )
    {
        LOG_ENTER();
        //
        // Sync our provider and address lists
        //
        ProcessUpdates();

        Lock lock(&m_lock);

        //
        // Cap to max DWORD value.  This has the added benefit of zeroing the upper
        // bits on 64-bit platforms, so that the returned value is correct.
        //
        if (*pcbLocalAddress > UINT_MAX)
        {
            *pcbLocalAddress = UINT_MAX;
        }

        //
        // We store the original length so we can distinguish from different
        // errors that return WSAEFAULT.
        //
        SIZE_T len = *pcbLocalAddress;
        int ret = ::WSAIoctl(
            m_Socket,
            SIO_ROUTING_INTERFACE_QUERY,
            const_cast<sockaddr*>(pRemoteAddress),
            static_cast<DWORD>(cbRemoteAddress),
            pLocalAddress,
            static_cast<DWORD>(len),
            reinterpret_cast<DWORD*>(pcbLocalAddress),
            nullptr,
            nullptr
        );

        if (ret == SOCKET_ERROR)
        {
            switch (::GetLastError())
            {
            case WSAEFAULT:
                if (len < *pcbLocalAddress)
                {
                    LOG_HRESULT_RETURN(ND_BUFFER_OVERFLOW);
                    return ND_BUFFER_OVERFLOW;
                }
                __fallthrough;
            default:
                LOG_HRESULT_RETURN(ND_UNSUCCESSFUL);
                return ND_UNSUCCESSFUL;
            case WSAEINVAL:
                LOG_HRESULT_RETURN(ND_INVALID_ADDRESS);
                return ND_INVALID_ADDRESS;
            case WSAENETUNREACH:
            case WSAENETDOWN:
                LOG_HRESULT_RETURN(ND_NETWORK_UNREACHABLE);
                return ND_NETWORK_UNREACHABLE;
            }
        }

        //
        // We found a local address.  Now make sure that the we have a provider
        // that supports it.
        //
        for (List<Address>::iterator pAddr = m_NdAddrList.begin();
            pAddr != m_NdAddrList.end();
            ++pAddr)
        {
            if (pAddr->Matches(pLocalAddress))
            {
                LOG_HRESULT_RETURN(S_OK);
                return S_OK;
            }
        }

        for (List<Address>::iterator pAddr = m_NdV1AddrList.begin();
            pAddr != m_NdV1AddrList.end();
            ++pAddr)
        {
            if (pAddr->Matches(pLocalAddress))
            {
                LOG_HRESULT_RETURN(S_OK);
                return S_OK;
            }
        }

        LOG_HRESULT_RETURN(ND_INVALID_ADDRESS);
        return ND_INVALID_ADDRESS;
    }


    HRESULT
        Framework::CheckAddress(
            _In_bytecount_(cbAddress) const struct sockaddr* pAddress,
            _In_ SIZE_T cbAddress
        )
    {
        LOG_ENTER();
        ASSERT(pAddress);

        HRESULT hr = ValidateAddress(pAddress, cbAddress);
        if (FAILED(hr))
        {
            LOG_HRESULT_RETURN(hr);
            return hr;
        }

        //
        // Sync our provider and address lists.
        //
        ProcessUpdates();

        Lock lock(&m_lock);
        for (List<Address>::iterator pAddr = m_NdAddrList.begin();
            pAddr != m_NdAddrList.end();
            ++pAddr)
        {
            if (pAddr->Matches(pAddress))
            {
                LOG_HRESULT_RETURN(ND_SUCCESS);
                return ND_SUCCESS;
            }
        }

        for (List<Address>::iterator pAddr = m_NdV1AddrList.begin();
            pAddr != m_NdV1AddrList.end();
            ++pAddr)
        {
            if (pAddr->Matches(pAddress))
            {
                LOG_HRESULT_RETURN(ND_SUCCESS);
                return ND_SUCCESS;
            }
        }

        LOG_HRESULT_RETURN(ND_INVALID_ADDRESS);
        return ND_INVALID_ADDRESS;
    }


    HRESULT
        Framework::OpenAdapter(
            _In_ REFIID iid,
            _In_bytecount_(cbAddress) const struct sockaddr* pAddress,
            _In_ SIZE_T cbAddress,
            _Deref_out_ VOID** ppIAdapter
        )
    {
        LOG_ENTER();
        ASSERT(pAddress);
        ASSERT(ppIAdapter);
        HRESULT hr = ValidateAddress(pAddress, cbAddress);
        if (FAILED(hr))
        {
            LOG_HRESULT_RETURN(hr);
            return hr;
        }

        //
        // Sync our provider and address lists
        //
        ProcessUpdates();

        Lock lock(&m_lock);
        const List<Address>* pList;
        if (InlineIsEqualGUID(iid, IID_INDAdapter))
        {
            pList = &m_NdV1AddrList;
        }
        else
        {
            pList = &m_NdAddrList;
        }

        //
        // Find the provider for the given address.
        //
        hr = ND_INVALID_ADDRESS;
        for (List<Address>::iterator pAddr = pList->begin();
            pAddr != pList->end();
            ++pAddr)
        {
            if (!pAddr->Matches(pAddress))
            {
                continue;
            }

            ASSERT(pAddr->GetProvider() != nullptr);
            hr = pAddr->GetProvider()->OpenAdapter(
                iid,
                pAddress,
                static_cast<ULONG>(cbAddress),
                ppIAdapter
            );
            if (FAILED(hr))
            {
                continue;   // In case another provider handles the same address.
            }

            break;
        }
        LOG_HRESULT_RETURN(hr);
        return hr;
    }


    void
        Framework::FlushProvidersForUser()
    {
        LOG_ENTER();
        Lock lock(&m_lock);
        FlushProviders();
        LOG_VOID_RETURN();
    }


    HRESULT
        Framework::ValidateAddress(
            _In_bytecount_(cbAddress) const struct sockaddr* pAddress,
            _In_ SIZE_T cbAddress
        )
    {
        LOG_ENTER();
        if (cbAddress < sizeof(struct sockaddr))
        {
            LOG_HRESULT_RETURN(ND_INVALID_PARAMETER_2);
            return ND_INVALID_PARAMETER_2;
        }

        if (cbAddress > ULONG_MAX)
        {
            LOG_HRESULT_RETURN(ND_INVALID_PARAMETER_2);
            return ND_INVALID_PARAMETER_2;
        }

        switch (pAddress->sa_family)
        {
        case AF_INET:
            if (cbAddress < sizeof(struct sockaddr_in))
            {
                LOG_HRESULT_RETURN(ND_INVALID_PARAMETER_2);
                return ND_INVALID_PARAMETER_2;
            }
            break;

        case AF_INET6:
            if (cbAddress < sizeof(struct sockaddr_in6))
            {
                LOG_HRESULT_RETURN(ND_INVALID_PARAMETER_2);
                return ND_INVALID_PARAMETER_2;
            }
            break;

        default:
            LOG_HRESULT_RETURN(ND_INVALID_ADDRESS);
            return ND_INVALID_ADDRESS;
        }

        LOG_HRESULT_RETURN(ND_SUCCESS);
        return ND_SUCCESS;
    }


    void
        Framework::CountAddresses(
            _In_ const List<Address>& list,
            _Inout_ SIZE_T* pnV4,
            _Inout_ SIZE_T* pnV6
        )
    {
        LOG_ENTER();
        for (List<Address>::iterator pAddr = list.begin();
            pAddr != list.end() && (*pnV4 + *pnV6) < INT_MAX;
            ++pAddr)
        {
            switch (pAddr->AF())
            {
            case AF_INET:
                (*pnV4)++;
                break;
            case AF_INET6:
                (*pnV6)++;
                break;
            default:
                continue;
            }
        }
        LOG_VOID_RETURN();
    }


    void
        Framework::BuildAddressList(
            _In_ Provider& prov,
            _In_ const SOCKET_ADDRESS_LIST& addrList,
            _Inout_ List<Address>* pList
        )
    {
        LOG_ENTER();
        for (int i = 0; i < addrList.iAddressCount; i++)
        {
            // We only handle IPv4 and IPv6 addresses.
            if (addrList.Address[i].iSockaddrLength < sizeof(struct sockaddr))
            {
                continue;
            }

            switch (addrList.Address[i].lpSockaddr->sa_family)
            {
            case AF_INET:
                if (addrList.Address[i].iSockaddrLength <
                    sizeof(struct sockaddr_in))
                {
                    continue;
                }
                break;

            case AF_INET6:
                if (addrList.Address[i].iSockaddrLength <
                    sizeof(struct sockaddr_in6))
                {
                    continue;
                }
                break;

            default:
                continue;
            }

            Address* pAddr =
                new Address(*addrList.Address[i].lpSockaddr, prov);
            if (pAddr != nullptr)
            {
                pList->push_back(pAddr);
            }
        }
        LOG_VOID_RETURN();;
    }


    void
        Framework::CopyAddressList(
            _In_ const List<Address>& list,
            _Inout_ SOCKET_ADDRESS_LIST* pAddressList,
            _Inout_ BYTE** ppBuf,
            _Inout_ SIZE_T* pcbBuf
        )
    {
        LOG_ENTER();
        INT nAddress = pAddressList->iAddressCount;

        for (List<Address>::iterator pAddr = list.begin();
            pAddr != list.end() && nAddress < INT_MAX;
            ++pAddr)
        {
            SIZE_T len = pAddr->CopySockaddr(*ppBuf, *pcbBuf);
            if (len == 0)
            {
                continue;
            }

            ASSERT(len < INT_MAX);
            pAddressList->Address[nAddress].iSockaddrLength =
                static_cast<INT>(len);
            pAddressList->Address[nAddress].lpSockaddr =
                reinterpret_cast<LPSOCKADDR>(*ppBuf);
            (*ppBuf) += len;
            (*pcbBuf) -= len;

            ++nAddress;
        }

        pAddressList->iAddressCount = nAddress;
        LOG_VOID_RETURN();
    }


    void
        Framework::ProcessUpdates()
    {
        LOG_ENTER();
        BOOL ret;

        // Check the IOCP for completion of any of our requests.
        do
        {
            DWORD len;
            ULONG_PTR key;
            OVERLAPPED* pOv;
            INT status;
            DWORD bytesRet;

            ret = ::GetQueuedCompletionStatus(m_hIocp, &len, &key, &pOv, 0);

            if (ret == TRUE)
            {
                Lock lock(&m_lock);

                switch (key)
                {
                case ND_NOTIFY_PROVIDER_CHANGE:
                    // Issue the next request for protocol catalog changes,
                    // in case things change while we are processing this event.
                    status = ::WSAProviderConfigChange(
                        &m_hProviderChange, &m_Ov[ND_NOTIFY_PROVIDER_CHANGE], nullptr);
                    ASSERT(status == 0 || ::WSAGetLastError() == WSA_IO_PENDING);

                    ProcessProviderChange();
                    break;

                case ND_NOTIFY_ADDR_CHANGE:
                    // Issue the next request for address changes, in case
                    // things change while we are processing this event.
                    status = ::WSAIoctl(m_Socket, SIO_ADDRESS_LIST_CHANGE, nullptr, 0, nullptr,
                        0, &bytesRet, &m_Ov[ND_NOTIFY_ADDR_CHANGE], nullptr);
                    ASSERT(status == 0);

                    ProcessAddressChange();
                    break;

                default:
                    ASSERT(key == ND_NOTIFY_PROVIDER_CHANGE ||
                        key == ND_NOTIFY_ADDR_CHANGE);
                    break;
                }

                FlushProviders();
            }
            // TODO: Should we re-issue requests if they have failed?
            // What if (can?) they immediately fail again to the IOCP?
            // We'd end up stuck in this loop.

        } while (ret == TRUE ||
            (::GetLastError() != WAIT_TIMEOUT /*&&
            ::GetLastError() != ERROR_ABANDONED_WAIT*/));
        LOG_VOID_RETURN();
    }


    void
        Framework::ProcessProviderChange()
    {
        // Enumerate the provider catalog, and rebuild our list of providers.
        LOG_ENTER();
        DWORD len = 0;
        INT err;
        INT ret = ::WSCEnumProtocols(nullptr, nullptr, &len, &err);
        ASSERT(ret == SOCKET_ERROR);
        ASSERT(err == WSAENOBUFS);
        if (ret != SOCKET_ERROR || err != WSAENOBUFS)
        {
            LOG_VOID_RETURN();
            return;
        }

        // We try only once - if the required buffer size changes then our
        // request for provider changes will get completed and we'll come back
        ASSERT((len % sizeof(WSAPROTOCOL_INFOW)) == 0);
        WSAPROTOCOL_INFOW* pProtocols = static_cast<WSAPROTOCOL_INFOW*>(::HeapAlloc(
            ghHeap,
            0,
            len
        ));
        if (pProtocols == nullptr)
        {
            LOG_VOID_RETURN();
            return;
        }

        ret = ::WSCEnumProtocols(nullptr, pProtocols, &len, &err);
        if (ret == SOCKET_ERROR)
        {
            ::HeapFree(ghHeap, 0, pProtocols);
            LOG_VOID_RETURN();
            return;
        }

        // Mark all existing providers inactive.
        for (List<Provider>::iterator pProv = m_ProviderList.begin();
            pProv != m_ProviderList.end();
            ++pProv)
        {
            pProv->MarkInactive();
        }

        for (DWORD i = 0; i < len / sizeof(WSAPROTOCOL_INFOW); i++)
        {
            if ((pProtocols[i].dwServiceFlags1 & ND_SERVICE_FLAGS1) !=
                ND_SERVICE_FLAGS1)
            {
                continue;
            }

            switch (pProtocols[i].iVersion)
            {
            case ND_VERSION_1:
                // NDv1 providers don't always set the PFL_NETWORKDIRECT flag.
                if ((pProtocols[i].dwProviderFlags & PFL_HIDDEN) != PFL_HIDDEN)
                {
                    continue;
                }
                break;

            case ND_VERSION_2:
                if ((pProtocols[i].dwProviderFlags & ND_PROVIDER_FLAGS) !=
                    ND_PROVIDER_FLAGS)
                {
                    continue;
                }
                break;

            default:
                continue;
            }

            if (pProtocols[i].iAddressFamily != AF_INET &&
                pProtocols[i].iAddressFamily != AF_INET6)
            {
                continue;
            }

            if (pProtocols[i].iSocketType != -1)
            {
                continue;
            }

            if (pProtocols[i].iProtocol != 0)
            {
                continue;
            }

            if (pProtocols[i].iProtocolMaxOffset != 0)
            {
                continue;
            }

            // We found a network direct provider.  See if it's already in the list.
            List<Provider>::iterator pProv = m_ProviderList.begin();
            while (pProv != m_ProviderList.end())
            {
                if (*pProv == pProtocols[i].ProviderId)
                {
                    pProv->MarkActive();
                    break;
                }
                ++pProv;
            }
            if (pProv != m_ProviderList.end())
            {
                //
                // We found a match in our existing provider list,
                // no need to create a new provider.
                //
                continue;
            }

            // New provider, add it to the list.
            Provider* pProvider;
            if (pProtocols[i].iVersion == ND_VERSION_1)
            {
                pProvider = new NdV1Provider();
            }
            else
            {
                pProvider = new NdProvider();
            }

            if (pProvider == nullptr)
            {
                continue;
            }

            HRESULT hr = pProvider->Init(pProtocols[i].ProviderId);
            if (FAILED(hr))
            {
                delete pProvider;
                continue;
            }

            m_ProviderList.push_back(pProvider);
        }
        ::HeapFree(ghHeap, 0, pProtocols);

        // We now have an up-to-date provider list.  Populate the address table.
        ProcessAddressChange();
        LOG_VOID_RETURN();
    }


    void
        Framework::ProcessAddressChange()
    {
        LOG_ENTER();
        // Remove all existing addresses.
        while (!m_NdAddrList.empty())
        {
            Address* pAddr = &m_NdAddrList.front();
            m_NdAddrList.pop_front();
            delete pAddr;
        }

        while (!m_NdV1AddrList.empty())
        {
            Address* pAddr = &m_NdV1AddrList.front();
            m_NdV1AddrList.pop_front();
            delete pAddr;
        }

        SOCKET_ADDRESS_LIST* pAddrList = nullptr;
        ULONG len = 0;

        for (List<Provider>::iterator pProv = m_ProviderList.begin();
            pProv != m_ProviderList.end();
            ++pProv)
        {
            if (!pProv->IsActive())
            {
                continue;
            }

            HRESULT hr = pProv->QueryAddressList(pAddrList, &len);
            if (hr == ND_BUFFER_OVERFLOW)
            {
                if (pAddrList != nullptr)
                {
                    ::HeapFree(ghHeap, 0, pAddrList);
                }

                // If the allocated buffer is not large enough, our request for
                // address change notifcation will pick up the change.
                pAddrList =
                    static_cast<SOCKET_ADDRESS_LIST*>(::HeapAlloc(ghHeap, 0, len));
                if (pAddrList == nullptr)
                {
                    continue;
                }

                hr = pProv->QueryAddressList(pAddrList, &len);
            }

            if (FAILED(hr))
            {
                continue;
            }

            __analysis_assume(pAddrList);

            if (pProv->GetVersion() == ND_VERSION_1)
            {
                BuildAddressList(*pProv, *pAddrList, &m_NdV1AddrList);
            }
            else
            {
                BuildAddressList(*pProv, *pAddrList, &m_NdAddrList);
            }
        }

        if (pAddrList != nullptr)
        {
            ::HeapFree(ghHeap, 0, pAddrList);
        }
        LOG_VOID_RETURN();
    }


    void
        Framework::FlushProviders()
    {
        LOG_ENTER();
        List<Provider>::iterator iter = m_ProviderList.begin();
        while (iter != m_ProviderList.end())
        {
            Provider* pProv = &*iter;
            //
            // Move to the next item now as we might remove the provider.
            //
            ++iter;

            if (pProv->TryUnload() == true && pProv->IsActive() == false)
            {
                m_ProviderList.remove(*pProv);
                delete pProv;
            }
        }
        LOG_VOID_RETURN();
    }

} // namespace NetworkDirect


//
// Initialization
//
using namespace NetworkDirect;

EXTERN_C HRESULT ND_HELPER_API
NdStartup(
    VOID
)
{
    LOG_ENTER();
    LONG init;
    do
    {
        init = ::InterlockedCompareExchange(&gInitializing, 1, 0);
    } while (init == 1);

    if (gpFramework == nullptr)
    {
        ghHeap = ::HeapCreate(0, 0, 0);
        if (ghHeap == nullptr)
        {
            ::InterlockedDecrement(&gInitializing);
            
            HRESULT hr = HRESULT_FROM_WIN32(::GetLastError());
            LOG_HRESULT_RETURN(hr);
            return hr;
        }

        gpFramework = new NetworkDirect::Framework();
        if (gpFramework == nullptr)
        {
            ::HeapDestroy(ghHeap);
            ghHeap = nullptr;
            ::InterlockedDecrement(&gInitializing);
            LOG_HRESULT_RETURN(ND_NO_MEMORY);
            return ND_NO_MEMORY;
        }
        HRESULT hr = gpFramework->Init();
        if (FAILED(hr))
        {
            delete(gpFramework);
            gpFramework = nullptr;
            ::HeapDestroy(ghHeap);
            ghHeap = nullptr;
            ::InterlockedDecrement(&gInitializing);
            LOG_HRESULT_RETURN(hr);;
            return hr;
        }
    }

    gpFramework->AddRef();
    ::InterlockedDecrement(&gInitializing);
    LOG_HRESULT_RETURN(S_OK);
    return S_OK;
}


EXTERN_C HRESULT ND_HELPER_API
NdCleanup(
    VOID
)
{
    LOG_ENTER();
    LONG init;
    do
    {
        init = ::InterlockedCompareExchange(&gInitializing, 1, 0);
    } while (init == 1);

    if (gpFramework == nullptr)
    {
        ::InterlockedDecrement(&gInitializing);
        LOG_HRESULT_RETURN(ND_DEVICE_NOT_READY);
        return ND_DEVICE_NOT_READY;
    }

    if (gpFramework->Release() == 0)
    {
        gpFramework = nullptr;
        ::HeapDestroy(ghHeap);
        ghHeap = nullptr;
    }

    ::InterlockedDecrement(&gInitializing);
    LOG_HRESULT_RETURN(S_OK);
    return S_OK;
}


EXTERN_C VOID ND_HELPER_API
NdFlushProviders(
    VOID
)
{
    LOG_ENTER();
    if (gpFramework == nullptr)
    {
        LOG_VOID_RETURN();
        return;
    }

    gpFramework->FlushProvidersForUser();
    LOG_VOID_RETURN();
}


//
// Network capabilities
//
EXTERN_C HRESULT ND_HELPER_API
NdQueryAddressList(
    _In_ DWORD flags,
    _Out_opt_bytecap_post_bytecount_(*pcbAddressList, *pcbAddressList) SOCKET_ADDRESS_LIST* pAddressList,
    _Inout_ SIZE_T* pcbAddressList
)
{
    LOG_ENTER();
    if (gpFramework == nullptr)
    {
        LOG_HRESULT_RETURN(ND_DEVICE_NOT_READY);
        return ND_DEVICE_NOT_READY;
    }

    HRESULT hr = gpFramework->QueryAddressList(flags, pAddressList, pcbAddressList);
    LOG_HRESULT_RETURN(hr);
    return hr;
}


EXTERN_C HRESULT ND_HELPER_API
NdResolveAddress(
    _In_bytecount_(cbRemoteAddress) const struct sockaddr* pRemoteAddress,
    _In_ SIZE_T cbRemoteAddress,
    _Out_bytecap_(*pcbLocalAddress) struct sockaddr* pLocalAddress,
    _Inout_ SIZE_T* pcbLocalAddress
)
{
    LOG_ENTER();
    if (gpFramework == nullptr)
    {
        LOG_HRESULT_RETURN(ND_DEVICE_NOT_READY);
        return ND_DEVICE_NOT_READY;
    }

    HRESULT hr = gpFramework->ResolveAddress(
        pRemoteAddress,
        cbRemoteAddress,
        pLocalAddress,
        pcbLocalAddress
    );
    LOG_HRESULT_RETURN(hr);
    return hr;
}


EXTERN_C HRESULT ND_HELPER_API
NdCheckAddress(
    _In_bytecount_(cbAddress) const struct sockaddr* pAddress,
    _In_ SIZE_T cbAddress
)
{
    LOG_ENTER();;
    if (gpFramework == nullptr)
    {
        LOG_HRESULT_RETURN(ND_DEVICE_NOT_READY);
        return ND_DEVICE_NOT_READY;
    }

    HRESULT hr = gpFramework->CheckAddress(pAddress, cbAddress);
    LOG_HRESULT_RETURN(hr);
    return hr;
}


EXTERN_C HRESULT ND_HELPER_API
NdOpenAdapter(
    _In_ REFIID iid,
    _In_bytecount_(cbAddress) const struct sockaddr* pAddress,
    _In_ SIZE_T cbAddress,
    _Deref_out_ VOID** ppIAdapter
)
{
    LOG_ENTER();
    if (gpFramework == nullptr)
    {
        LOG_HRESULT_RETURN(ND_DEVICE_NOT_READY);
        return ND_DEVICE_NOT_READY;
    }

    HRESULT hr = gpFramework->OpenAdapter(iid, pAddress, cbAddress, ppIAdapter);
    LOG_HRESULT_RETURN(hr);
    return hr;
}


EXTERN_C HRESULT ND_HELPER_API
NdOpenV1Adapter(
    _In_bytecount_(cbAddress) const struct sockaddr* pAddress,
    _In_ SIZE_T cbAddress,
    _Deref_out_ INDAdapter** ppIAdapter
)
{
    LOG_ENTER();
    HRESULT hr = gpFramework->OpenAdapter(
        IID_INDAdapter,
        pAddress,
        cbAddress,
        reinterpret_cast<VOID**>(ppIAdapter)
    );
    LOG_HRESULT_RETURN(hr);
    return hr;
}
