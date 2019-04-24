#pragma once

#ifndef WINSHIM_H
#define WINSHIM_H

#include <stdio.h>
#include <WS2spi.h>

typedef HRESULT(*INTERFACE_GETTER)(REFCLSID, REFIID, void**);

/**
 * A wrapper for Windows system calls.
 *
 * All calls are logged and exceptions are thrown when the call is not successful.
 *
 */
class Win {
public:
  /**
  *  Thrown when a function is not successful.
  */
  struct Error {};

  /**
  * Thrown when an enumeration has been completed
  *
  * Example:
  *
  * \code{.cpp}
  *    try {
  *      PROCESS_HEAP_ENTRY Entry;
  *      while (true) {
  *        Win::HeapWalk(hHeap, &Entry);
  *        do_something(Entry);
  *      }
  *    }
  *    catch (Win::EnumerationEnded) {}
  * \endcode
  **/
  struct EnumerationEnded {};

  /**
  * \brief Enumerates the memory blocks in the specified heap
  **/
  static void HeapWalk(
    HANDLE hHeap,
    LPPROCESS_HEAP_ENTRY lpEntry
  );

  /**
  * \brief Creates a private heap object that can be used by the calling process.
  *
  * The function reserves space in the virtual address space of the process
  * and allocates physical storage for a specified initial portion of this block.
  **/
  static HANDLE HeapCreate(
    DWORD flOptions,
    SIZE_T dwInitialSize,
    SIZE_T dwMaximumSize
  );

  /**
  * \brief Destroys the specified heap object.
  *
  * It decommits and releases all the pages of a private heap object,
  * and it invalidates the handle to the heap
  **/
  static void HeapDestroy(
    HANDLE hHeap
  );

  /**
  * \brief Attempts to acquire the critical section object, or lock, that is associated with a specified heap.
  **/
  static void HeapLock(
    HANDLE hHeap
  );

  /**
  * \brief Releases ownership of the critical section object, or lock, that is associated with a specified heap.
  *
  * It reverses the action of the HeapLock function.
  **/
  static void HeapUnlock(
    HANDLE hHeap
  );

  /**
  * \brief Allocates a block of memory from a heap. The allocated memory is not movable.
  **/
  static void* HeapAlloc(
    HANDLE hHeap,
    DWORD dwFlags,
    SIZE_T size
  );

  /**
  * \brief Frees a memory block allocated from a heap by the HeapAlloc or HeapReAlloc function.
  **/
  static void HeapFree(
    HANDLE hHeap,
    DWORD dwFlags,
    void* lpMem
  );

  /**
  * \brief Reallocates a block of memory from a heap.
  *
  * This function enables you to resize a memory
  * block and change other memory block properties. The allocated memory is not movable.
  **/
  static void* HeapReAlloc(
    HANDLE hHeap,
    DWORD dwFlags,
    void* lpMem,
    SIZE_T size
  );

  /**
  * \brief Initializes the COM library on the current thread and identifies
  *       the concurrency model as single-thread apartment (STA).
  *
  * New applications should call CoInitializeEx instead of CoInitialize.
  **/
  static void CoInitialize(
    void* lpReserved
  );

  /**
  * \brief Closes the COM library on the current thread,
  *        unloads all DLLs loaded by the thread,
  *        frees any other resources that the thread maintains,
  *        and forces all RPC connections on the thread to close.
  **/
  static void CoUninitialize();

  /**
  * \brief The WSCEnumProtocols function retrieves information'
  *        about available transport protocols
  **/
  static int WSCEnumProtocols(
    LPINT lpiProtocols,
    LPWSAPROTOCOL_INFOW lpProtocolBuffer,
    LPDWORD lpdwBufferLength,
    LPINT lpErrno
  );

  /**
  * \brief The WSCGetProviderPath function retrieves the DLL path for the specified provider
  **/
  static int WSCGetProiderPath(
    LPGUID lpProviderId,
    WCHAR *lpszProviderDllPath,
    LPINT lpProviderDllPathLen,
    LPINT lpErrno
  );

  /**
  * \brief The WSAStartup function initiates use of the Winsock DLL by a process
  **/
  static int WSAStartup(
    WORD wVersionRequested,
    LPWSADATA lpWSAData
  );

  /**
  * \brief The WSACleanup function terminates use of the Winsock 2 DLL (Ws2_32.dll)
  **/
  static int WSACleanup();

  /**
    @brief Converts a network address in its standard text representation
        into its binary form in a sockaddr structure.

    @param AddressString
        A pointer to a zero terminated string that contains the network address
        in standard text form (to be converted)

    @param AddressFamily
        The address family of the network address pointed to by the AddressString parameter.

    @param lpProtocolInfo
        The WSAPROTOCOL_INFO structure associated with the provider to be used.
        If this is NULL, the call is routed to the provider of the first
        protocol supporting the indicated AddressFamily.

    @param lpAddress
        A pointer to a buffer that is filled with a sockaddr structure for the
        address string if the function succeeds.

    @param lpAddressLength
        A pointer to the length, in bytes, of the buffer pointed to
        by the lpAddress parameter.
        If the function call is successful, this parameter returns a pointer
        to the size of the sockaddr structure returned in the lpAddress parameter.
        If the specified buffer is not large enough, the function fails with a specific error
        of WSAEFAULT and this parameter is updated with the required size in bytes.
  **/
  static int WSAStringToAddressA(
      LPSTR AddressString,
      INT AddressFamily,
      LPWSAPROTOCOL_INFOA lpProtocolInfo,
      LPSOCKADDR lpAddress,
      LPINT lpAddressLength
  );

  /**
  * \brief Loads the specified module into the address space of the calling process
  *
  * The specified module may cause other modules to be loaded
  **/
  static HMODULE LoadLibraryW(
    LPCWSTR lpLibFileName
  );

  /**
  * \brief Frees the DLL module.
  *
  * If necessary decrements its reference count.
  * When the reference count reaches zero, the module is unloaded from
  * the address space of the calling proces and the handle is no
  * longer valid.
  **/
  static void FreeLibrary(
    HMODULE hModule
  );

  /**
  * \brief Expands environment variable strings and replaces them
  *        with the values defined for the current user.
  **/
  static DWORD ExpandEnvironmentStringsW(
    LPCWSTR src,
    LPWSTR dst,
    DWORD dstCount
  );

  /**
  * \brief Retrieves the address of an exported function or variable from the specified dynamic - link library(DLL).
  **/
  static FARPROC GetProcAddress(
    HMODULE hModule,
    LPCSTR  lpProcName
  );

    /**
    @fn CreateFileA
    @brief Creates or opens a file
    */
    static HANDLE CreateFileA(
      LPCSTR                lpFileName,
      DWORD                 dwDesiredAccess,
      DWORD                 dwShareMode,
      LPSECURITY_ATTRIBUTES lpSecurityAttributes,
      DWORD                 dwCreationDisposition,
      DWORD                 dwFlagsAndAttributes,
      HANDLE                hTemplateFile
    );

    /**
    @fn CloseHandle
    @brief Closes an open object handle
    */
    static BOOL CloseHandle(
        HANDLE hObject
    );

    static void ReadFileEx(
        HANDLE                          hFile,
        LPVOID                          lpBuffer,
        DWORD                           nNumberOfBytesToRead,
        LPOVERLAPPED                    lpOverlapped,
        LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    );

    static void ReadFile(
        HANDLE       hFile,
        LPVOID       lpBuffer,
        DWORD        nNumberOfBytesToRead,
        LPDWORD      lpNumberOfBytesRead,
        LPOVERLAPPED lpOverlapped
    );
    static size_t GetFileSize(HANDLE hFile);
};

/**
* @brief Makes sure COM support is enabled and destroyed
**/
class CCom 
{
public:
  CCom() 
  {
    Win::CoInitialize(NULL);
  }
  ~CCom() 
  {
    Win::CoUninitialize();
  }
};

/**
* @brief Makes sure Windows socket support is enabled and destroyed
**/
class WSA 
{
public:
  WSA() 
  {
    WSADATA data;
    Win::WSAStartup(MAKEWORD(2, 2), &data);
  }
  ~WSA() 
  {
    Win::WSACleanup();
  }
};

/**
* @brief Loads a DLL into memory and then unloads when you are done
**/
class CModule 
{
  HMODULE const m_hModule;
public:
  CModule(const wchar_t* dll_path) : m_hModule(Win::LoadLibraryW(dll_path)) 
  {
  }
  ~CModule() 
  {
    Win::FreeLibrary(m_hModule);
  }
  operator HMODULE () 
  {
    return m_hModule;
  }

};


#endif
