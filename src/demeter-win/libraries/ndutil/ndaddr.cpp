//
// Copyright(c) Microsoft Corporation.All rights reserved.
// Licensed under the MIT License.
//

#pragma once

#include "precomp.h"
#include "ndaddr.h"

namespace NetworkDirect
{

    Address::Address(
        _In_ const struct sockaddr& addr,
        _In_ Provider& provider
    ) :
        m_pProvider(&provider)
    {
        LOG_ENTER();
        m_link.Flink = &m_link;
        m_link.Blink = &m_link;

        ASSERT(addr.sa_family == AF_INET || addr.sa_family == AF_INET6);

        switch (addr.sa_family)
        {
        case AF_INET:
            ::CopyMemory(&m_Addr.Ipv4, &addr, sizeof(m_Addr.Ipv4));
            break;
        case AF_INET6:
            ::CopyMemory(&m_Addr.Ipv6, &addr, sizeof(m_Addr.Ipv6));
            break;
        default:
            ASSERT(addr.sa_family == AF_INET ||
                addr.sa_family == AF_INET6);
            m_Addr.si_family = AF_UNSPEC;
        }
        LOG_VOID_RETURN();
    }


    bool Address::Matches(const struct sockaddr* pAddr) const
    {
        LOG_ENTER();
        bool ans;
        switch (pAddr->sa_family)
        {
        case AF_INET:
            ans = reinterpret_cast<const struct sockaddr_in*>(pAddr)->sin_addr.S_un.S_addr ==
                m_Addr.Ipv4.sin_addr.S_un.S_addr;
            LOG_BOOLEAN_RETURN(ans);
            return ans;

        case AF_INET6:
            ans = (::memcmp(reinterpret_cast<const sockaddr_in6*>(pAddr)->sin6_addr.u.Byte,
                m_Addr.Ipv6.sin6_addr.u.Byte, sizeof(m_Addr.Ipv6.sin6_addr)) == 0);
            LOG_BOOLEAN_RETURN(ans);
            return ans;

        default:
            LOG_BOOLEAN_RETURN(false);
            return false;
        }
    }


    SIZE_T Address::CopySockaddr(_Out_writes_(len) BYTE* pBuf, _In_ SIZE_T len) const
    {
        LOG_ENTER();
        SIZE_T ans;
        switch (m_Addr.si_family)
        {
        case AF_INET:
            if (len < sizeof(m_Addr.Ipv4))
            {
                LOG_SIZET_RETURN(0);
                return 0;
            }

            ::CopyMemory(pBuf, &m_Addr.Ipv4, sizeof(m_Addr.Ipv4));
            ans = sizeof(m_Addr.Ipv4);
            LOG_SIZET_RETURN(ans);
            return ans;

        case AF_INET6:
            if (len < sizeof(m_Addr.Ipv6))
            {
                LOG_SIZET_RETURN(0);
                return 0;
            }

            ::CopyMemory(pBuf, &m_Addr.Ipv6, sizeof(m_Addr.Ipv6));
            ans = sizeof(m_Addr.Ipv6);
            LOG_SIZET_RETURN(ans);
            return ans;

        default:
            LOG_SIZET_RETURN(0);
            return 0;
        }
    }

} // namespace NetworkDirect
