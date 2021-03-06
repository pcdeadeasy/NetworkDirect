//
// Copyright(c) Microsoft Corporation.All rights reserved.
// Licensed under the MIT License.
//
#pragma once

#include "precomp.h"
#include "ndaddr.h"
#include "ndprov.h"

namespace NetworkDirect
{

    Provider::Provider(int version) :
        m_Guid(GUID_NULL),
        m_hProvider(nullptr),
        m_pfnDllGetClassObject(nullptr),
        m_pfnDllCanUnloadNow(nullptr),
        m_Path(nullptr),
        m_Version(version),
        m_Active(true)
    {
        LOG_ENTER();
        m_link.Flink = &m_link;
        m_link.Blink = &m_link;
        LOG_VOID_RETURN();
    }


    Provider::~Provider()
    {
        LOG_ENTER();
        if (m_hProvider != nullptr)
        {
            ::FreeLibrary(m_hProvider);
        }

        if (m_Path)
        {
            ::HeapFree(ghHeap, 0, m_Path);
        }
        LOG_VOID_RETURN();
    }


    HRESULT Provider::Init(GUID& ProviderGuid)
    {
        LOG_ENTER();
        INT pathLen;
        INT ret, err;
        WCHAR* pPath;

        // Get the path length for the provider DLL.
        pPath = static_cast<WCHAR*>(
            ::HeapAlloc(ghHeap, 0, sizeof(WCHAR) * MAX_PATH)
            );
        if (pPath == nullptr)
        {
            HRESULT hr = ND_NO_MEMORY;
            LOG_HRESULT_RETURN(hr);
            return hr;
        }

        pathLen = MAX_PATH;
        ret = ::WSCGetProviderPath(&ProviderGuid, pPath, &pathLen, &err);
        if (ret != 0)
        {
            ::HeapFree(ghHeap, 0, pPath);
            HRESULT hr = HRESULT_FROM_WIN32(err);
            LOG_HRESULT_RETURN(hr);
            return hr;
        }

        pathLen = ::ExpandEnvironmentStringsW(pPath, nullptr, 0);
        if (pathLen == 0)
        {
            ::HeapFree(ghHeap, 0, pPath);
            HRESULT hr = HRESULT_FROM_WIN32(::GetLastError());
            LOG_HRESULT_RETURN(hr);
            return hr;
        }

        m_Path = static_cast<WCHAR*>(
            ::HeapAlloc(ghHeap, 0, sizeof(WCHAR) * pathLen)
            );
        if (m_Path == nullptr)
        {
            ::HeapFree(ghHeap, 0, pPath);
            HRESULT hr = ND_NO_MEMORY;
            LOG_HRESULT_RETURN(hr);
            return hr;
        }

        ret = ::ExpandEnvironmentStringsW(pPath, m_Path, pathLen);

        // We don't need the un-expanded path anymore.
        ::HeapFree(ghHeap, 0, pPath);

        if (ret != pathLen)
        {
            HRESULT hr = ND_UNSUCCESSFUL;
            LOG_HRESULT_RETURN(hr);
            return hr;
        }

        m_Guid = ProviderGuid;
        HRESULT hr = S_OK;
        LOG_HRESULT_RETURN(hr);
        return hr;
    }


    //
    // Serialization with TryUnload must be provided by the caller.  Multiple
    // callers may call this function concurrently.
    //
    HRESULT Provider::GetClassObject(
        _In_ const IID& iid,
        _Out_ void** ppInterface
    )
    {
        LOG_ENTER();
        if (m_hProvider == nullptr)
        {
            HMODULE hProvider;
            hProvider = ::LoadLibraryExW(m_Path, nullptr, 0);
            if (hProvider == nullptr)
            {
                HRESULT hr = HRESULT_FROM_WIN32(::GetLastError());
                LOG_HRESULT_RETURN(hr);
                return hr;
            }

            m_pfnDllGetClassObject = reinterpret_cast<DLLGETCLASSOBJECT>(
                ::GetProcAddress(hProvider, "DllGetClassObject")
                );
            if (!m_pfnDllGetClassObject)
            {
                ::FreeLibrary(hProvider);
                HRESULT hr = HRESULT_FROM_WIN32(::GetLastError());
                LOG_HRESULT_RETURN(hr);
                return hr;
            }

            m_pfnDllCanUnloadNow = reinterpret_cast<DLLCANUNLOADNOW>(
                ::GetProcAddress(hProvider, "DllCanUnloadNow")
                );
            if (!m_pfnDllCanUnloadNow)
            {
                ::FreeLibrary(hProvider);
                HRESULT hr =HRESULT_FROM_WIN32(::GetLastError());
                LOG_HRESULT_RETURN(hr);
                return hr;
            }

            HMODULE hCurrentProvider = static_cast<HMODULE>(
                ::InterlockedCompareExchangePointer(
                    reinterpret_cast<void**>(&m_hProvider), hProvider, nullptr)
                );
            if (hCurrentProvider)
            {
                ASSERT(hCurrentProvider == hProvider);
                ::FreeLibrary(hProvider);
            }
        }

        HRESULT hr = m_pfnDllGetClassObject(
            m_Guid,
            iid,
            ppInterface
        );

        LOG_HRESULT_RETURN(hr);
        return hr;
    }


    //
    // Strict serialization must be provided by the caller.
    //
    bool Provider::TryUnload(void)
    {
        LOG_ENTER();
        if (m_hProvider == nullptr)
        {
            LOG_BOOLEAN_RETURN(true);
            return true;
        }

        ASSERT(m_pfnDllCanUnloadNow != nullptr);

        HRESULT hr = m_pfnDllCanUnloadNow();
        if (hr != S_OK)
        {
            LOG_BOOLEAN_RETURN(false);
            return false;
        }

        ::FreeLibrary(m_hProvider);
        m_hProvider = nullptr;

        LOG_BOOLEAN_RETURN(true);
        return true;
    }


    NdV1Provider::NdV1Provider() :
        Provider(ND_VERSION_1)
    {
        LOG_ENTER();
        LOG_VOID_RETURN();
    }


    //
    // Serialization with TryUnload must be provided by the caller.  Multiple
    // callers may call this function concurrently.
    //
    HRESULT NdV1Provider::GetProvider(INDProvider** ppIProvider)
    {
        LOG_ENTER();
        IClassFactory* pClassFactory;
        HRESULT hr = GetClassObject(
            IID_IClassFactory,
            reinterpret_cast<void**>(&pClassFactory)
        );
        if (FAILED(hr))
        {
            LOG_HRESULT_RETURN(hr);
            return hr;
        }

        hr = pClassFactory->CreateInstance(
            nullptr,
            IID_INDProvider,
            reinterpret_cast<void**>(ppIProvider)
        );

        // Now that we asked for the provider, we don't need the class factory.
        pClassFactory->Release();
        LOG_HRESULT_RETURN(hr);
        return hr;
    }


    HRESULT
        NdV1Provider::OpenAdapter(
            _In_ REFIID iid,
            _In_bytecount_(cbAddress) const struct sockaddr* pAddress,
            _In_ ULONG cbAddress,
            _Deref_out_ VOID** ppIAdapter
        )
    {
        LOG_ENTER();
        if (iid != IID_INDAdapter)
        {
            HRESULT hr = E_NOINTERFACE;
            LOG_HRESULT_RETURN(hr);
            return hr;
        }

        INDProvider* pIProvider;
        HRESULT hr = GetProvider(&pIProvider);
        if (FAILED(hr))
        {
            TryUnload();
            hr = ND_INVALID_ADDRESS;
            LOG_HRESULT_RETURN(hr);
            return hr;
        }

        hr = pIProvider->OpenAdapter(
            pAddress,
            cbAddress,
            reinterpret_cast<INDAdapter**>(ppIAdapter)
        );
        LOG("INDProvider::OpenAdapter -> %08X", hr);

        pIProvider->Release();
        TryUnload();

        LOG_HRESULT_RETURN(hr);
        return hr;
    }


    HRESULT
        NdV1Provider::QueryAddressList(
            _Out_opt_bytecap_post_bytecount_(*pcbAddressList, *pcbAddressList) SOCKET_ADDRESS_LIST* pAddressList,
            _Inout_ ULONG* pcbAddressList
        )
    {
        LOG_ENTER();
        INDProvider *pIProvider;
        HRESULT hr = GetProvider(&pIProvider);
        if (FAILED(hr))
        {
            TryUnload();
            LOG_HRESULT_RETURN(ND_DEVICE_NOT_READY);
            return ND_DEVICE_NOT_READY;
        }

        SIZE_T cbAddressList = *pcbAddressList;
        hr = pIProvider->QueryAddressList(pAddressList, &cbAddressList);
        *pcbAddressList = static_cast<ULONG>(cbAddressList);

        pIProvider->Release();
        TryUnload();

        LOG_HRESULT_RETURN(hr);
        return hr;
    }


    NdProvider::NdProvider() :
        Provider(ND_VERSION_2)
    {
        LOG_ENTER();
        LOG_VOID_RETURN();
    }


    //
    // Serialization with TryUnload must be provided by the caller.  Multiple
    // callers may call this function concurrently.
    //
    HRESULT NdProvider::OpenAdapter(
        _In_ REFIID iid,
        _In_bytecount_(cbAddress) const struct sockaddr* pAddress,
        _In_ ULONG cbAddress,
        _Deref_out_ VOID** ppIAdapter
    )
    {
        LOG_ENTER();
        IND2Provider* pIProvider;
        HRESULT hr = GetClassObject(
            IID_IND2Provider,
            reinterpret_cast<void**>(&pIProvider)
        );
        if (FAILED(hr))
        {
            TryUnload();
            LOG_HRESULT_RETURN(ND_INVALID_ADDRESS);
            return ND_INVALID_ADDRESS;
        }

        UINT64 id;
        hr = pIProvider->ResolveAddress(pAddress, cbAddress, &id);
        LOG("IND2Provider::ResolveAddress -> %08X", hr);
        if (FAILED(hr))
        {
            pIProvider->Release();
            TryUnload();
            LOG_HRESULT_RETURN(ND_INVALID_ADDRESS);
            return ND_INVALID_ADDRESS;
        }

        hr = pIProvider->OpenAdapter(iid, id, ppIAdapter);
        LOG("IND2Provider::OpenAdapter -> %08X", hr);

        pIProvider->Release();
        TryUnload();

        LOG_HRESULT_RETURN(hr);
        return hr;
    }


    HRESULT
        NdProvider::QueryAddressList(
            _Out_opt_bytecap_post_bytecount_(*pcbAddressList, *pcbAddressList) SOCKET_ADDRESS_LIST* pAddressList,
            _Inout_ ULONG* pcbAddressList
        )
    {
        LOG_ENTER();
        IND2Provider *pIProvider;
        HRESULT hr = GetClassObject(
            IID_IND2Provider,
            reinterpret_cast<void**>(&pIProvider)
        );
        if (FAILED(hr))
        {
            TryUnload();
            LOG_HRESULT_RETURN(ND_DEVICE_NOT_READY);
            return ND_DEVICE_NOT_READY;
        }

        hr = pIProvider->QueryAddressList(pAddressList, pcbAddressList);

        pIProvider->Release();
        TryUnload();

        LOG_HRESULT_RETURN(hr);
        return hr;
    }


} // namespace NetworkDirect
