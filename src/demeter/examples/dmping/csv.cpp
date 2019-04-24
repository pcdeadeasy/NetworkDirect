#include "pch.h"
#include <ctype.h>
#include "csv.h"
#include <Winshim.h>
#include <Logger.h>

//class FILE_IMAGE
//{
//public:
//    FILE_IMAGE(HEAP *pHeap, const char *file_path);
//    ~FILE_IMAGE();
//
//    void* get_address()
//    {
//        return m_src;
//    }
//
//    size_t get_size()
//    {
//        return m_size;
//    }
//
//    operator void*()
//    {
//        return m_src;
//    }
//
//private:
//    void *m_src;
//    size_t m_size;
//    HEAP *m_pHeap;
//    FILE_IMAGE() = delete;
//};
//
//FILE_IMAGE::FILE_IMAGE(HEAP *pHeap, const char *file_path) : m_pHeap(pHeap), m_src(0), m_size(0)
//{
//    HANDLE const hFile = Win::CreateFileA(file_path, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
//    try
//    {
//        m_size = Win::GetFileSize(hFile);
//        m_src = m_pHeap->Alloc(0, m_size + 1);  // allocate one more than the requested size so that we can add a terminator
//        DWORD NumberOfBytesRead = 0;
//        Win::ReadFile(hFile, m_src, (DWORD)m_size, &NumberOfBytesRead, 0);
//        ((char*)m_src)[m_size] = 0;             // add the zero terminator just in case
//    }
//    catch (...)
//    {
//        Win::CloseHandle(hFile);
//        throw;
//    }
//    Win::CloseHandle(hFile);
//}
//
//FILE_IMAGE::~FILE_IMAGE()
//{
//    if (m_src)
//    {
//        m_pHeap->Free(0, m_src);
//    }
//}

static bool isnewline(const char ch)
{
    return (ch == '\r') || (ch == '\n');
}

/**
* @brief Finds the first occurance of the character in a string

    The string need not be null terminated.
*/
static const char* findchar(const char* buffer, size_t len, char ch)
{
    const char *pch = buffer;
    for (const char *pch = buffer; pch < buffer + len; pch++)
    {
        if (*pch == ch)
            return pch;
    }
    return 0;
}

static void read_char_file(HEAP &heap, BUFFER<char> &csv, const char *csv_path)
{
    LOG_ENTER();
    HANDLE const hFile = Win::CreateFileA(csv_path, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    try
    {
        size_t size = Win::GetFileSize(hFile);
        csv.Init(&heap, 0, size + 1);
        DWORD NumberOfBytesRead = 0;
        Win::ReadFile(hFile, csv, (DWORD)size, &NumberOfBytesRead, 0);
        if (NumberOfBytesRead != (DWORD)size)
        {
            LOG("NumberOfBytesRead = %u != size = %zu", NumberOfBytesRead, size);
            throw Win::Error();
        }
        csv[size] = 0;             // append zero terminator
    }
    catch (...)
    {
        Win::CloseHandle(hFile);
        throw;
    }
    Win::CloseHandle(hFile);
    LOG_VOID_RETURN();
}

static size_t add(BUFFER<KVP> &kvps, char *line, size_t len, size_t index, size_t increment)
{
    LOG_ENTER();
    size_t ans = index;
    char *pch = (char*)findchar(line, len, ',');    // find the first comma
    if (pch != 0)
    {
        if (kvps.count() <= index)
            kvps.ReAlloc(HEAP_ZERO_MEMORY, kvps.count() + increment);
        *pch = 0;
        line[len] = 0;
        kvps[index] = { line, pch + 1 };
        ans = index + 1;
    }
    LOG_SIZET_RETURN(ans);
    return ans;
}


static size_t fill_kvp_buffer(BUFFER<KVP> &kvps, BUFFER<char> &csvs, size_t increment)
{
    LOG_ENTER();
    size_t ans = 0;
    char *start = 0;
    int len = 0;
    int state = 0;
    size_t const limit = csvs.count() - 1;
    char* buffer = csvs;
    for (size_t index = 0; index < limit; index++)
    {
        const char ch = buffer[index];
        switch (state)
        {
        case 0:
            if (!isnewline(ch))
            {
                start = &buffer[index];
                len = 1;
                state = 1;
            }
            else
            {
                state = 2;
            }
            break;
        case 1:
            if (!isnewline(ch))
            {
                len += 1;
            }
            else
            {
                ans = add(kvps, start, len, ans, increment);
                state = 2;
            }
            break;
        case 2:
            if (!isnewline(ch))
            {
                start = &buffer[index];
                len = 1;
                state = 1;
            }
            break;
        default:
            LOG("state: %d", state);
            throw Win::Error();
        }
    }
    if (state == 1)
    {
        ans = add(kvps, start, len, ans, increment);
    }
    LOG_SIZET_RETURN(ans);
    return ans;
}

CSV_DICT::CSV_DICT(HEAP& heap, const char *csv_path, size_t increment) : m_heap(heap), m_count(0), m_csvs(BUFFER<char>()), m_kvps(BUFFER<KVP>())
{
    LOG_ENTER();
    read_char_file(m_heap, m_csvs, csv_path);
    m_kvps.Init(&heap, 0, increment);
    m_count = fill_kvp_buffer(m_kvps, m_csvs, increment);
    LOG_VOID_RETURN();
}

CSV_DICT::~CSV_DICT()
{
    LOG_ENTER();
    LOG_VOID_RETURN();
}

const char* CSV_DICT::lookup(const char *key)
{
    for (size_t i = 0; i < m_count; i++)
    {
        if (strcmp(key, m_kvps[i].key) == 0)
            return  m_kvps[i].val;
    }
    throw KEYERROR();
}
