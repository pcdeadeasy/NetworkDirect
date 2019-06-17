#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include <objbase.h>

#pragma comment(lib, "Ws2_32.lib")
#pragma warning( disable : 4996)

static const wchar_t* last_error()
{
  return get_win_error_symbol(GetLastError());
}

#define LOG_LAST_ERROR() LOG("GetLastError -> %S", last_error())

static LPWSTR GetSystemHresultStrW(HRESULT hr) 
{
  static WCHAR pErrorBuf[1024];         // !!! do not delete this
  static DWORD const nErrorBufSz = 1024;
  DWORD const dwError = (DWORD)HRESULT_CODE(hr);

  int const char_count = wsprintfW(pErrorBuf, L"    %s\n", get_win_error_symbol(hr));

  DWORD const ret = FormatMessage(
    FORMAT_MESSAGE_FROM_SYSTEM |
    FORMAT_MESSAGE_IGNORE_INSERTS,
    NULL,
    dwError,
    MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
    (LPTSTR)&pErrorBuf[char_count],
    nErrorBufSz - char_count,
    NULL
  );
  if (!ret)
  {
    //_tcscpy_s(pErrorBuf, nErrorBufSz,
    //  TEXT("Unknown runtime error\n"));
      
    wcsncpy(pErrorBuf, L"Unknown runtime error\n", nErrorBufSz);
  }
  return pErrorBuf;
}

static LPWSTR GetLastErrorStrW() 
{
  return GetSystemHresultStrW(HRESULT_FROM_WIN32(GetLastError()));
}

int Win::WSAStartup(WORD wVersionRequested, LPWSADATA lpWSAData) 
{
  int const ans = ::WSAStartup(wVersionRequested, lpWSAData);
  LOG("WSAStartup %x %p -> %d", wVersionRequested, lpWSAData, ans);
  if (ans != 0) 
  {
    LOG_LAST_ERROR();
    throw Win::Error();
  }
  return ans;
}

int Win::WSACleanup() 
{
  int const ans = ::WSACleanup();
  LOG("WSACleanup () -> %d", ans);
  if (ans != 0) 
  {
    LOG_LAST_ERROR();
    throw Win::Error();
  }
  return ans;
}

int Win::WSAStringToAddressA(
    LPSTR AddressString,
    INT AddressFamily,
    LPWSAPROTOCOL_INFOA lpProtocolInfo,
    LPSOCKADDR lpAddress,
    LPINT lpAddressLength
)
{
//#pragma warning(disable : 4996) // WSAStringToAddressA has been deprecated for the unicode version; disable the warning
    int const ans = ::WSAStringToAddressA(AddressString, AddressFamily, lpProtocolInfo, lpAddress, lpAddressLength);
//#pragma warning(enable : 4996)
    LOG("WSAStringToAddressA \"%s\" %d %p %p %p -> %d", AddressString, AddressFamily, lpProtocolInfo, lpAddress, lpAddressLength, ans);
    if (ans != 0)
    {
        LOG_LAST_ERROR();
        throw Win::Error();
    }
    return ans;
}

int Win::WSAAddressToStringA(
    LPSOCKADDR lpsaAddress,
    DWORD dwAddressLength,
    LPWSAPROTOCOL_INFOA lpProtocolInfo,
    LPSTR lpszAddressString,
    LPDWORD lpdwAddressStringLength)
{
    int const ans = ::WSAAddressToStringA(lpsaAddress, dwAddressLength, lpProtocolInfo, lpszAddressString, lpdwAddressStringLength);
    LOG("WSAAddressToStringA %p %08X %p %p %p -> %d", lpsaAddress, dwAddressLength, lpProtocolInfo, lpszAddressString, lpdwAddressStringLength, ans);
    if (ans != 0)
    {
        LOG_LAST_ERROR();
        throw Win::Error();
    }
    return ans;
}

int Win::WSCEnumProtocols(LPINT lpiProtocols, LPWSAPROTOCOL_INFOW lpProtocolBuffer, LPDWORD lpdwBufferLength, LPINT lpErrno) 
{
  int const ans = ::WSCEnumProtocols(lpiProtocols, lpProtocolBuffer, lpdwBufferLength, lpErrno);
  LOG(
    "WSCEnumProtocols %p %p %p %p -> %d\n"
    "BufferLength <- %u\n"
    "Errno <- %d", 
    lpiProtocols, lpProtocolBuffer, lpdwBufferLength, lpErrno, ans, *lpdwBufferLength, *lpErrno);
  if (ans == SOCKET_ERROR) 
  {
    LOG_LAST_ERROR();
    throw Win::Error();
  }
  return ans;
}

int Win::WSCGetProiderPath(LPGUID lpProviderId, WCHAR *lpszProviderDllPath, LPINT lpProviderDllPathLen, LPINT lpErrno) 
{
  int const ans = ::WSCGetProviderPath(lpProviderId, lpszProviderDllPath, lpProviderDllPathLen, lpErrno);
  LOG(
    "WSCGetProviderPath %p %p %p %p -> %d\n"
    "ProviderDllPathLen <- %d\n"
    "Errno <- %d", 
    lpProviderId, lpszProviderDllPath, lpProviderDllPathLen, lpErrno, ans, *lpProviderDllPathLen, *lpErrno);
  if (ans == SOCKET_ERROR) 
  {
    LOG_LAST_ERROR();
    throw Win::Error();
  }
  return ans;
}

void Win::CoInitialize(void* lpReserved) 
{
  if (lpReserved != NULL) 
  {
    LOG("lpReserved: %p", lpReserved);
    throw Win::Error();
  }
  HRESULT const hr = ::CoInitialize(NULL);
  LOG("Conitialize %p -> %08X", (void*)0, hr);
  if (FAILED(hr)) 
  {
    LOG_LAST_ERROR();
    throw Win::Error();
  }
}

void Win::CoUninitialize() 
{
  ::CoUninitialize();
  LOG("CoUninitialize () -> ()");
}

void Win::HeapWalk(HANDLE hHeap, LPPROCESS_HEAP_ENTRY lpEntry) 
{
  BOOL const ans = ::HeapWalk(hHeap, lpEntry);
  LOG("HeapWalk %p %p -> %s", hHeap, lpEntry, ans ? "TRUE" : "FALSE");
  if (ans == FALSE) 
  {
    if (GetLastError() == ERROR_NO_MORE_ITEMS)
    {
      throw Win::EnumerationEnded();
    }
    LOG_LAST_ERROR();
    throw Win::Error();
  }
}

HANDLE Win::HeapCreate(DWORD flOptions, SIZE_T dwInitialSize, SIZE_T dwMaximumSize) 
{
  HANDLE const ans = ::HeapCreate(flOptions, dwInitialSize, dwMaximumSize);
  LOG("HeapCreate %08X %llu %llu -> %p", flOptions, dwInitialSize, dwMaximumSize, ans);
  if (ans == NULL) 
  {
    LOG_LAST_ERROR();
    throw Win::Error();
  }
  return ans;
}

void Win::HeapDestroy(HANDLE hHeap) 
{
  BOOL const ans = ::HeapDestroy(hHeap);
  LOG("HeapDestroy %p -> %s", hHeap, ans ? "TRUE" : "FALSE");
  if (ans == FALSE) 
  {
    // Don't throw
    LOG_LAST_ERROR();
  }
}

void Win::HeapLock(HANDLE hHeap) 
{
  BOOL const ans = ::HeapLock(hHeap);
  LOG("HeapLock %p -> %s", hHeap, ans ? "TRUE" : "FALSE");
  if (ans == FALSE) 
  {
    LOG_LAST_ERROR();
    throw Win::Error();
  }
}

void Win::HeapUnlock(HANDLE hHeap) 
{
  BOOL const ans = ::HeapUnlock(hHeap);
  LOG("HeapUnlock %p -> %s", hHeap, ans ? "TRUE" : "FALSE");
  if (ans == FALSE) 
  {
    LOG_LAST_ERROR();
  }
}

void* Win::HeapAlloc(HANDLE hHeap, DWORD dwFlags, SIZE_T size) 
{
  void* const ans = ::HeapAlloc(hHeap, dwFlags, size);
  LOG("HeapAlloc %p %08X %llu -> %p", hHeap, dwFlags, size, ans);
  if (ans == NULL) 
  {
    LOG_LAST_ERROR();
    throw Win::Error();
  }
  return ans;
}

void Win::HeapFree(HANDLE hHeap, DWORD dwFlags, void* lpMem) 
{
  BOOL const ans = ::HeapFree(hHeap, dwFlags, lpMem);
  LOG("HeapFree %p %08X %p -> %s", hHeap, dwFlags, lpMem, ans ? "TRUE" : "FALSE");
  if (ans == NULL) 
  {
    LOG_LAST_ERROR();
  }
}

void* Win::HeapReAlloc(HANDLE hHeap, DWORD dwFlags, void* lpMem, SIZE_T size) 
{
  void* const ans = ::HeapReAlloc(hHeap, dwFlags, lpMem, size);
  LOG("HeapReAlloc %p %08X %p %llu -> %p", hHeap, dwFlags, lpMem, size, ans);
  if (ans == FALSE) 
  {
    LOG_LAST_ERROR();
    throw Win::Error();
  }
  return ans;
}

HMODULE Win::LoadLibraryW(LPCWSTR lpLibFileName) 
{
  if (lpLibFileName == NULL) 
  {
    LOG("lpLibFileName is NULL");
    throw Win::Error();
  }
  HMODULE const ans = ::LoadLibraryW(lpLibFileName);
  LOG("LoadLibraryW \"%S\" -> %p", lpLibFileName, ans);
  if (ans == NULL) 
  {
    LOG_LAST_ERROR();
    throw Win::Error();
  }
  return ans;
}

void Win::FreeLibrary(HMODULE hModule) 
{
  if (hModule == NULL) 
  {
    LOG("hModule is NULL");
  }
  else 
  {
    BOOL const ans = ::FreeLibrary(hModule);
    LOG("FreeLibrary %p -> %d", hModule, ans);
    if (ans == FALSE) 
    {
      LOG_LAST_ERROR();
    }
  }
}


DWORD Win::ExpandEnvironmentStringsW(LPCWSTR src, LPWSTR dst, DWORD dstCount) 
{
  if (src == NULL) 
  {
    LOG("src is NULL");
    throw Win::Error();
  }
  DWORD const ans = ::ExpandEnvironmentStringsW(src, dst, dstCount);
  LOG("ExpandEnvironmentStringsW \"%S\" %p %u -> %u", src, dst, dstCount, ans);
  if (ans == 0) 
  {
    LOG_LAST_ERROR();
    throw Win::Error();
  }
  return ans;
}

FARPROC Win::GetProcAddress(HMODULE hModule, LPCSTR  lpProcName) 
{
  if (hModule == NULL) 
  {
    LOG("hModule is NULL");
    throw Win::Error();
  }
  if (lpProcName == NULL) 
  {
    LOG("lpProcName is NULL");
    throw Win::Error();
  }
  FARPROC const ans = ::GetProcAddress(hModule, lpProcName);
  LOG("GetProcAddress %p \"%s\" -> %p", hModule, lpProcName, ans);
  if (ans == NULL) 
  {

    LOG_LAST_ERROR();
    throw Win::Error();
  }
  return ans;
}

HANDLE Win::CreateFileA(
    LPCSTR                lpFileName,
    DWORD                 dwDesiredAccess,
    DWORD                 dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD                 dwCreationDisposition,
    DWORD                 dwFlagsAndAttributes,
    HANDLE                hTemplateFile
)
{
    HANDLE ans = ::CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
    LOG("CreateFileA \"%s\" %08X %08X %p %08X %08X %p -> %p", lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile, ans);
    if (ans == INVALID_HANDLE_VALUE)
    {
        LOG_LAST_ERROR();
        throw Win::Error();
    }
    return ans;
}

BOOL Win::CloseHandle(HANDLE hObject)
{
    BOOL ans = ::CloseHandle(hObject);
    LOG("CloseHandle %p -> %d", hObject, ans);
    return ans;
}

void Win::ReadFileEx(
    HANDLE                          hFile,
    LPVOID                          lpBuffer,
    DWORD                           nNumberOfBytesToRead,
    LPOVERLAPPED                    lpOverlapped,
    LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
)
{
    BOOL rc = ::ReadFileEx(hFile, lpBuffer, nNumberOfBytesToRead, lpOverlapped, lpCompletionRoutine);
    LOG("ReadFileEx %p %p %08X %p %p -> %d", hFile, lpBuffer, nNumberOfBytesToRead, lpOverlapped, lpCompletionRoutine, rc);
    if (rc == FALSE)
    {
        LOG_LAST_ERROR();
        throw Win::Error();
    }
}

void Win::ReadFile(
    HANDLE       hFile,
    LPVOID       lpBuffer,
    DWORD        nNumberOfBytesToRead,
    LPDWORD      lpNumberOfBytesRead,
    LPOVERLAPPED lpOverlapped
)
{
    BOOL rc = ::ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped);
    LOG("ReadFile %p %p %08X %p %p -> %d", hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped, rc);
    if (rc == FALSE)
    {
        LOG_LAST_ERROR();
        throw Win::Error();
    }
}


size_t Win::GetFileSize(HANDLE hFile)
{
    size_t ans = 0;
    LARGE_INTEGER FileSize = { 0 };
    BOOL b = ::GetFileSizeEx(hFile, &FileSize);
    ans = (size_t)FileSize.QuadPart;
    LOG("GetFileSize %p -> %d", hFile, b);
    if (b == FALSE)
    {
        LOG_LAST_ERROR();
        throw Win::Error();
    }
    return ans;
}