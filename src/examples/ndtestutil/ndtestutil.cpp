//
// Copyright(c) Microsoft Corporation.All rights reserved.
// Licensed under the MIT License.
//

#include "ndtestutil.h"
#include <Logger.h>

//initializer
NdTestBase::NdTestBase() :
    m_pAdapter(nullptr),
    m_pMr(nullptr),
    m_pCq(nullptr),
    m_pQp(nullptr),
    m_pConnector(nullptr),
    m_hAdapterFile(nullptr),
    m_Buf(nullptr),
    m_pMw(nullptr)
{
    LOG("Entering %s", __FUNCTION__);
    RtlZeroMemory(&m_Ov, sizeof(m_Ov));
    LOG("Exiting %s -> void", __FUNCTION__);
}

//tear down
NdTestBase::~NdTestBase()
{
    LOG("Entering %s", __FUNCTION__);
    if (m_pMr != nullptr)
    {
        m_pMr->Release();
    }

    if (m_pMw != nullptr)
    {
        m_pMw->Release();
    }

    if (m_pCq != nullptr)
    {
        m_pCq->Release();
    }

    if (m_pQp != nullptr)
    {
        m_pQp->Release();
    }

    if (m_pConnector != nullptr)
    {
        m_pConnector->Release();
    }

    if (m_hAdapterFile != nullptr)
    {
        CloseHandle(m_hAdapterFile);
    }

    if (m_pAdapter != nullptr)
    {
        m_pAdapter->Release();
    }

    if (m_Ov.hEvent != nullptr)
    {
        CloseHandle(m_Ov.hEvent);
    }

    if (m_Buf != nullptr)
    {
        delete[] m_Buf;
    }
    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestBase::CreateMR(HRESULT expectedResult, const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);
    HRESULT hr = m_pAdapter->CreateMemoryRegion(
        IID_IND2MemoryRegion,
        m_hAdapterFile,
        reinterpret_cast<VOID**>(&m_pMr)
    );
    LOG("IND2Adapter::CreateMemoryRegion -> %08X", hr);

    LogIfErrorExit(hr, expectedResult, errorMessage, __LINE__);
    LOG("Exiting %s -> %08X", __FUNCTION__, hr);
}

void NdTestBase::RegisterDataBuffer(
    DWORD bufferLength,
    ULONG type,
    HRESULT expectedResult,
    const char* errorMessage)
{
    LOG("Entring %s", __FUNCTION__);
    m_Buf_Len = bufferLength;
    m_Buf = new (std::nothrow) char[m_Buf_Len];
    if (m_Buf == nullptr)
    {
        printf("Failed to allocate buffer.\n");
        LOG("Exiting %s -> exit", __FUNCTION__);
        exit(__LINE__);
    }

    RegisterDataBuffer(m_Buf, m_Buf_Len, type, expectedResult, errorMessage);
    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestBase::RegisterDataBuffer(
    void *pBuf,
    DWORD bufferLength,
    ULONG type,
    HRESULT expectedResult,
    const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);
#pragma warning(suppress: 6001)
    HRESULT hr = m_pMr->Register(
        pBuf,
        bufferLength,
        type,
        &m_Ov
    );
    LOG("IND2MemoryRegion::Register -> %08X", hr);
    if (hr == ND_PENDING)
    {
        hr = m_pMr->GetOverlappedResult(&m_Ov, TRUE);
        LOG("IND2MemoryRegion::GetOverlappedResult -> %08X", hr);
    }
    LogIfErrorExit(hr, expectedResult, errorMessage, __LINE__);
    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestBase::CreateMW(HRESULT expectedResult, const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);
    HRESULT hr = m_pAdapter->CreateMemoryWindow(
        IID_IND2MemoryWindow,
        reinterpret_cast<VOID**>(&m_pMw)
    );
    LOG("IND2Adapter::CreateMemoryWindow -> %08X", hr);

    LogIfErrorExit(hr, expectedResult, errorMessage, __LINE__);
    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestBase::InvalidateMW(HRESULT expectedResult, const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);
    HRESULT hr;
    hr = m_pQp->Invalidate(nullptr, m_pMw, 0);
    LOG("IND2QueuePair::Invalidate -> %08X", hr);
    LogIfErrorExit(hr, expectedResult, errorMessage, __LINE__);
    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestBase::Bind(DWORD bufferLength, ULONG flags, void *context, HRESULT expectedResult, const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);
    Bind(m_Buf, bufferLength, flags, context, expectedResult, errorMessage);
    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestBase::Bind(const void *pBuf, DWORD bufferLength, ULONG flags, void *context, HRESULT expectedResult, const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);
#pragma warning(suppress: 6001)
    HRESULT hr = m_pQp->Bind(context, m_pMr, m_pMw, pBuf, bufferLength, flags);
    LOG("IND2QueuePair::Bind -> %08X", hr);
    if (hr != ND_SUCCESS)
    {
        LogErrorExit("Bind failed\n", __LINE__);
    }

    ND2_RESULT ndRes;
    NdTestBase::WaitForCompletion(&ndRes);
    LogIfErrorExit(ndRes.Status, expectedResult, errorMessage, -1);
    if (ndRes.Status == ND_SUCCESS && ndRes.RequestContext != context)
    {
        LogErrorExit("Invalid context", __LINE__);
    }
    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestBase::CreateCQ(DWORD depth, HRESULT expectedResult, const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);
    HRESULT hr = m_pAdapter->CreateCompletionQueue(
        IID_IND2CompletionQueue,
        m_hAdapterFile,
        depth,
        0,
        0,
        reinterpret_cast<VOID**>(&m_pCq)
    );
    LOG("IND2Adapter::CreateCompletionQueue -> %08X", hr);
    LogIfErrorExit(hr, expectedResult, errorMessage, __LINE__);
    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestBase::CreateCQ(IND2CompletionQueue **pCq, DWORD depth, HRESULT expectedResult, const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);
    HRESULT hr = m_pAdapter->CreateCompletionQueue(
        IID_IND2CompletionQueue,
        m_hAdapterFile,
        depth,
        0,
        0,
        reinterpret_cast<VOID**>(pCq)
    );
    LOG("IND2Adapter::CreateCompletionQueue -> %08X", hr);
    LogIfErrorExit(hr, expectedResult, errorMessage, __LINE__);
    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestBase::CreateConnector(HRESULT expectedResult, const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);
    HRESULT hr = m_pAdapter->CreateConnector(
        IID_IND2Connector,
        m_hAdapterFile,
        reinterpret_cast<VOID**>(&m_pConnector)
    );
    LOG("IND2Adapter::CreateConnector -> %08X", hr);
    LogIfErrorExit(hr, expectedResult, errorMessage, __LINE__);
    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestBase::CreateQueuePair(DWORD queueDepth, DWORD nSge, DWORD inlineDataSize,
    HRESULT expectedResult, const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);
    HRESULT hr = m_pAdapter->CreateQueuePair(
        IID_IND2QueuePair,
        m_pCq,
        m_pCq,
        nullptr,
        queueDepth,
        queueDepth,
        nSge,
        nSge,
        inlineDataSize,
        reinterpret_cast<VOID**>(&m_pQp)
    );
    LOG("IND2Adapter::CreateQueuePair -> %08X", hr);
    LogIfErrorExit(hr, expectedResult, errorMessage, __LINE__);
    LOG("Exiting %s -> void", __FUNCTION__);
}


void NdTestBase::CreateQueuePair(
    DWORD receiveQueueDepth,
    DWORD initiatorQueueDepth,
    DWORD maxReceiveRequestSge,
    DWORD maxInitiatorRequestSge,
    HRESULT expectedResult,
    const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);

    HRESULT hr = m_pAdapter->CreateQueuePair(
        IID_IND2QueuePair,
        m_pCq,
        m_pCq,
        nullptr,
        maxReceiveRequestSge,
        initiatorQueueDepth,
        maxReceiveRequestSge,
        maxInitiatorRequestSge,
        0,
        reinterpret_cast<VOID**>(&m_pQp)
    );
    LOG("IND2Adapter::CreateQueuePair -> %08X", hr);
    LogIfErrorExit(hr, expectedResult, errorMessage, __LINE__);
    UNUSED(receiveQueueDepth);
    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestBase::Init(_In_ const struct sockaddr_in& v4Src)
{
    LOG("Entering %s", __FUNCTION__);
    HRESULT hr = NdOpenAdapter(
        IID_IND2Adapter,
        reinterpret_cast<const struct sockaddr*>(&v4Src),
        sizeof(v4Src),
        reinterpret_cast<void**>(&m_pAdapter)
    );
    if (FAILED(hr))
    {
        LogErrorExit("Failed open adapter.\n", __LINE__);
    }

    m_Ov.hEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
    if (m_Ov.hEvent == nullptr)
    {
        LogErrorExit("Failed to allocate event for overlapped operations.\n", __LINE__);
    }

    // Get the file handle for overlapped operations on this adapter.
    hr = m_pAdapter->CreateOverlappedFile(&m_hAdapterFile);
    LOG("IND2Adpater::CreateOverlappedFile -> %08X", hr);
    if (FAILED(hr))
    {
        LogErrorExit(hr, "IND2Adapter::CreateOverlappedFile failed", __LINE__);
    }
    LOG("Exiting %s -> void", __FUNCTION__);
}


void NdTestBase::GetAdapterInfo(ND2_ADAPTER_INFO *pAdapterInfo)
{
    LOG("Entering %s", __FUNCTION__);
    memset(pAdapterInfo, 0, sizeof(*pAdapterInfo));
    pAdapterInfo->InfoVersion = ND_VERSION_2;
    ULONG adapterInfoSize = sizeof(*pAdapterInfo);
    HRESULT hr = m_pAdapter->Query(pAdapterInfo, &adapterInfoSize);
    LOG("IND2Adapter::Query -> %08X", hr);
    if (FAILED(hr))
    {
        LogErrorExit(hr, "IND2Adapter::GetAdapterInfo failed", __LINE__);
    }
    LOG("Exiting %s -> void", __FUNCTION__);
}


DWORD NdTestBase::PrepareSge(
    ND2_SGE *pSge,
    const DWORD nSge,
    char *buff,
    ULONG buffSize,
    ULONG headerSize,
    UINT32 memoryToken)
{
    LOG("Entering %s", __FUNCTION__);
    DWORD currSge = 0;
    ULONG buffIdx = 0;
    ULONG currLen = 0;
    while (buffSize != 0 && currSge < nSge)
    {
        pSge[currSge].Buffer = buff + buffIdx;
        currLen = min(buffSize, headerSize);
        pSge[currSge].BufferLength = currLen;
        pSge[currSge].MemoryRegionToken = memoryToken;
        buffSize -= currLen;
        buffIdx += currLen;
        currSge++;
    }
    // add any remaining buffSize to the last sge
    if (buffSize > 0 && currSge > 0)
    {
        pSge[currSge - 1].BufferLength += buffSize;
    }
    LOG("Exiting %s -> %08X", currSge);
    return currSge;
}

void NdTestBase::DisconnectConnector()
{
    LOG("Entering %s", __FUNCTION__);
    if (m_pConnector != nullptr)
    {
        m_pConnector->Disconnect(&m_Ov);
    }
    LOG("Exiting %s -> void");
}

void NdTestBase::DeregisterMemory()
{
    LOG("Entering %s", __FUNCTION__);
    m_pMr->Deregister(&m_Ov);
    LOG("Exiting %s -> void");
}

void NdTestBase::GetResult(HRESULT expectedResult, const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);
    HRESULT hr = m_pCq->GetOverlappedResult(&m_Ov, TRUE);
    LogIfErrorExit(hr, expectedResult, errorMessage, __LINE__);
    LOG("Exiting %s -> void");
}

void NdTestBase::Shutdown()
{
    LOG("Entering %s", __FUNCTION__);
    NdTestBase::DisconnectConnector();
    NdTestBase::DeregisterMemory();
    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestBase::PostReceive(
    const ND2_SGE* Sge,
    const DWORD nSge,
    void *requestContext,
    HRESULT expectedResult,
    const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);
    HRESULT hr = m_pQp->Receive(requestContext, Sge, nSge);
    LOG("IND2QueuePair::Receive -> %08X", hr);
    LogIfErrorExit(hr, expectedResult, errorMessage, __LINE__);
    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestBase::Write(
    const ND2_SGE* Sge,
    const ULONG nSge,
    UINT64 remoteAddress,
    UINT32 remoteToken,
    DWORD flag,
    void *requestContext,
    HRESULT expectedResult,
    const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);

    HRESULT hr;
    hr = m_pQp->Write(requestContext, Sge, nSge, remoteAddress, remoteToken, flag);
    LOG("IND2QueuePair::Write -> %08X", hr);
    LogIfErrorExit(hr, expectedResult, errorMessage, __LINE__);

    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestBase::Read(
    const ND2_SGE* Sge,
    const ULONG nSge,
    UINT64 remoteAddress,
    UINT32 remoteToken,
    DWORD flag,
    void *requestContext,
    HRESULT expectedResult,
    const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);

    HRESULT hr;
    hr = m_pQp->Read(requestContext, Sge, nSge, remoteAddress, remoteToken, flag);
    LOG("IND2QueuePair::Read -> %08X", hr);
    LogIfErrorExit(hr, expectedResult, errorMessage, __LINE__);

    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestBase::Send(
    const ND2_SGE* Sge,
    const ULONG nSge,
    ULONG flags,
    void* requestContext,
    HRESULT expectedResult,
    const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);
    HRESULT hr = m_pQp->Send(requestContext, Sge, nSge, flags);
    LOG("IND2QueuePair::Send -> %08X", hr);
    LogIfErrorExit(hr, expectedResult, errorMessage, __LINE__);
    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestBase::Send(
    const ND2_SGE* Sge,
    const ULONG nSge,
    ULONG flags,
    bool expectFail,
    void* requestContext,
    const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);

    HRESULT hr = m_pQp->Send(requestContext, Sge, nSge, flags);
    LOG("IND2QueuePair::Send -> %08X", hr);

    if (expectFail && !FAILED(hr))
    {
        LogErrorExit(hr, errorMessage, __LINE__);
    }
    else if (!expectFail && FAILED(hr))
    {
        LogErrorExit(hr, errorMessage, __LINE__);
    }
    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestBase::WaitForEventNotification()
{
    LOG("Entering %s", __FUNCTION__);

    HRESULT hr = m_pCq->Notify(ND_CQ_NOTIFY_ANY, &m_Ov);
    LOG("IND2QueuePaor::Notify -> %08X", hr);
    if (hr == ND_PENDING)
    {
        hr = m_pCq->GetOverlappedResult(&m_Ov, TRUE);
        LOG("IND2QueuePair::GetOverlappedResult -> %08X");
    }
    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestBase::WaitForCompletion(
    const std::function<void(ND2_RESULT *)>& processCompletionFn,
    bool bBlocking)
{
    LOG("Entering %s", __FUNCTION__);

    for (;;)
    {
        ND2_RESULT ndRes;
        ULONG ul = m_pCq->GetResults(&ndRes, 1);
        LOG("IND2QueuePair::GetResults -> %08X", ul);
        if (ul == 1)
        {
            processCompletionFn(&ndRes);
            break;
        }
        if (bBlocking)
        {
            WaitForEventNotification();
        }
    };
    LOG("Exiting %s -> void", __FUNCTION__);
}

// wait for CQ entry and check context
void NdTestBase::WaitForCompletionAndCheckContext(void *expectedContext)
{
    LOG("Entering %s", __FUNCTION__);

    WaitForCompletion([&expectedContext](ND2_RESULT *pComp)
    {
        if (ND_SUCCESS != pComp->Status)
        {
            LogIfErrorExit(pComp->Status, ND_SUCCESS, "Unexpected completion status", __LINE__);
        }
        if (expectedContext != pComp->RequestContext)
        {
            LogErrorExit("Unexpected completion\n", __LINE__);
        }
    }, true);

    LOG("Exiting %s -> void", __FUNCTION__);
}

// wait for CQ entry and get the result
void NdTestBase::WaitForCompletion(ND2_RESULT *pResult, bool bBlocking)
{
    LOG("Entering %s", __FUNCTION__);

    WaitForCompletion([&pResult](ND2_RESULT *pCompRes)
    {
        *pResult = *pCompRes;
    }, bBlocking);

    LOG("Exiting %s -> void", __FUNCTION__);
}

// wait for CQ entry
void NdTestBase::WaitForCompletion(HRESULT expectedResult, const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);

    ND2_RESULT ndRes;
    WaitForCompletion(&ndRes, true);
    LogIfErrorExit(ndRes.Status, expectedResult, errorMessage, __LINE__);

    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestBase::FlushQP(HRESULT expectedResult, const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);

    HRESULT hr = m_pQp->Flush();
    LOG("IND2QueuePair::Flush -> %08X", hr);
    LogIfErrorExit(hr, expectedResult, errorMessage, __LINE__);

    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestBase::Reject(
    const VOID *pPrivateData,
    DWORD cbPrivateData,
    HRESULT expectedResult,
    const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);

    HRESULT hr = m_pConnector->Reject(pPrivateData, cbPrivateData);
    LOG("IND2Connector::Reject -> %08X", hr);
    LogIfErrorExit(hr, expectedResult, errorMessage, __LINE__);
    LOG("Exiting %s -> void", __FUNCTION__);
}
NdTestServerBase::NdTestServerBase() :
    m_pListen(nullptr)
{
    LOG("Entering %s", __FUNCTION__);
    LOG("Exiting %s -> void", __FUNCTION__);
}

NdTestServerBase::~NdTestServerBase()
{
    LOG("Entering %s", __FUNCTION__);

    if (m_pListen != nullptr)
    {
        m_pListen->Release();
    }

    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestServerBase::CreateListener(HRESULT expectedResult, const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);

    HRESULT hr = m_pAdapter->CreateListener(
        IID_IND2Listener,
        m_hAdapterFile,
        reinterpret_cast<VOID**>(&m_pListen)
    );
    LOG("IND2Adapter::CreateListener -> %08X", hr);
    LogIfErrorExit(hr, expectedResult, errorMessage, __LINE__);
    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestServerBase::Listen(
    _In_ const sockaddr_in& v4Src,
    HRESULT expectedResult,
    const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);

    HRESULT hr = m_pListen->Bind(
        reinterpret_cast<const sockaddr*>(&v4Src),
        sizeof(v4Src)
    );
    LOG("IND2Listener::Bind -> %08X", hr);
    LogIfErrorExit(hr, expectedResult, "Bind failed", __LINE__);
    hr = m_pListen->Listen(0);
    LOG("IND2Listner::Listen -> %08X", hr);
    LogIfErrorExit(hr, expectedResult, errorMessage, __LINE__);

    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestServerBase::GetConnectionRequest(HRESULT expectedResult, const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);

    HRESULT hr = m_pListen->GetConnectionRequest(m_pConnector, &m_Ov);
    LOG("IND2Listener::GetConnectionRequest -> %08X", hr);
    if (hr == ND_PENDING)
    {
        hr = m_pListen->GetOverlappedResult(&m_Ov, TRUE);
        LOG("IND2Listener::GetOverlappedResult -> %08X", hr);
    }
    LogIfErrorExit(hr, expectedResult, errorMessage, __LINE__);
    LOG("Exiting %s -> void", __FUNCTION__);
}

void NdTestServerBase::Accept(
    DWORD inboundReadLimit,
    DWORD outboundReadLimit,
    const VOID *pPrivateData,
    DWORD cbPrivateData,
    HRESULT expectedResult,
    const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);

    //
    // Accept the connection.
    //
    HRESULT hr = m_pConnector->Accept(
        m_pQp,
        inboundReadLimit,
        outboundReadLimit,
        pPrivateData,
        cbPrivateData,
        &m_Ov
    );
    LOG("IND2Connector::Accept -> %08X", hr);
    if (hr == ND_PENDING)
    {
        hr = m_pConnector->GetOverlappedResult(&m_Ov, TRUE);
        LOG("IND2Connector::GetOverlappedResult -> %08X", hr);
    }
    LogIfErrorExit(hr, expectedResult, errorMessage, __LINE__);

    LOG("Exiting %s -> void", __FUNCTION__);
}


//
// Connect to the server.
//
void NdTestClientBase::Connect(
    _In_ const sockaddr_in& v4Src,
    _In_ const sockaddr_in& v4Dst,
    DWORD inboundReadLimit,
    DWORD outboundReadLimit,
    const VOID *pPrivateData,
    DWORD cbPrivateData,
    HRESULT expectedResult,
    const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);

    HRESULT hr = m_pConnector->Bind(
        reinterpret_cast<const sockaddr*>(&v4Src),
        sizeof(v4Src)
    );
    LOG("IND2Connector::Bind -> %08X", hr);
    if (hr == ND_PENDING)
    {
        hr = m_pConnector->GetOverlappedResult(&m_Ov, TRUE);
        LOG("IND2Connector::GetOverlappedResult -> %08X", hr);
    }

    hr = m_pConnector->Connect(
        m_pQp,
        reinterpret_cast<const sockaddr*>(&v4Dst),
        sizeof(v4Dst),
        inboundReadLimit,
        outboundReadLimit,
        pPrivateData,
        cbPrivateData,
        &m_Ov
    );
    LOG("IND2Connector::Connect -> %08X", hr);
    if (hr == ND_PENDING)
    {
        hr = m_pConnector->GetOverlappedResult(&m_Ov, TRUE);
        LOG("IND2Connector::GetOverlappedResult -> %08X", hr);
    }
    LogIfErrorExit(hr, expectedResult, errorMessage, __LINE__);
    LOG("Exiting %s -> void", __FUNCTION__);
}

//
// Complete the connection - this transitions the endpoint so it can send.
//
void NdTestClientBase::CompleteConnect(HRESULT expectedResult, const char* errorMessage)
{
    LOG("Entering %s", __FUNCTION__);

    HRESULT hr = m_pConnector->CompleteConnect(&m_Ov);
    LOG("IND2Connector::CompleteConnect -> %08X");
    if (hr == ND_PENDING)
    {
        hr = m_pConnector->GetOverlappedResult(&m_Ov, TRUE);
        LOG("IND2Connector::GetOverlappedResult -> %08X");
    }
    LogIfErrorExit(hr, expectedResult, errorMessage, __LINE__);

    LOG("Exiting %s -> void", __FUNCTION__);
}
