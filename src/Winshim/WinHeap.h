#pragma once

#ifndef WINHEAP_H
#define WINHEAP_H

#include "winshim.h"

/**
  \class HEAP
  \brief A class for creating and managing a memory heap.

  The heap is automatically destroyed by the destructor.
  Memory allocation, re-allocation and freeing is supported.
 */
class HEAP {
    HANDLE const m_h;
    HEAP() = delete;
public:

    /**
     \brief constructor creates a Windows heap
     **/
    HEAP(DWORD flOptions, SIZE_T initialSize, SIZE_T maximumSize) : 
        m_h(Win::HeapCreate(flOptions, initialSize, maximumSize)) 
    {}

    /**
     * \brief destructor -- destroys the heap
     **/
    ~HEAP()
    { 
        Win::HeapDestroy(m_h); 
    }

    /**
     *  @brief allocates memory from the heap
     *
     *  @param flags
     *      Heap allocation options. This parameter can be one or
     *      more of the following values
     *      - HEAP_GENERATE_EXCEPTIONS
     *      - HEAP_NO_SERIALIZE
     *      - HEAP_ZERO_MEMORY
     *  @param size
     *      The number of bytes to be allocated
     **/
    void* Alloc(DWORD flags, size_t size) 
    {
        return Win::HeapAlloc(m_h, flags, size);
    }

    /**
     * \brief frees memory from the heap
     **/
    void Free(DWORD flags, void* pv) 
    {
        Win::HeapFree(m_h, flags, pv);
    }

    /**
     * reallocates memory on the heap
     *
     * The data may be moved to a new location. The value of the
     * reallocated memory is returned to the caller.
     *
     **/
    void* ReAlloc(DWORD flags, void* pv, size_t size) 
    {
        return Win::HeapReAlloc(m_h, flags, pv, size);
    }

    /**
     * \brief returns the handle of the heap
     *
     * This is for experts only
     **/
    HANDLE GetHandle() 
    {
        return m_h;
    }
};

/**
  \class WinBuffer
  \brief A class template for arrays of structures allocaed on the heap

  This takes care of allocation and destruction. If the allocation
  failes an exception will be thrown. The memory is freed when the
  destructor is called. The object itself is automatically cast
  to a pointer to the start of the array. You can also index
  into the buffer object. Reallocation of memory is supported too.
 */
template<typename T> class BUFFER {
    HEAP* const m_heap;
    size_t m_count; // count of objects in buffer
    size_t m_size;  // in bytes
    void* m_pv;     // pointer to object
    BUFFER() = delete;

public:

    ~BUFFER() 
    {
        m_heap->Free(0, m_pv);
    }

    /**
     * \brief constructor
     **/
    BUFFER(HEAP* heap, DWORD flags, SIZE_T count): 
        m_heap(heap), 
        m_count(count), 
        m_size(count * sizeof(T)), 
        m_pv(heap->Alloc(flags, m_size)) 
    { }

    /**
     * \brief Returns the address of the start of the array of objects of type T
     */
    operator T* () 
    {
        return (T*)m_pv;
    }

    /**
    Returns a reference to the i'th member of the allocated array.
    */
    T& operator[](SIZE_T index) 
    {
        if (index >= m_count)
            Win::Error();
        return ((T*)m_pv)[index];
    }

    /**
    Changes the size of the buffer while keeping the data.

    The underlying pointer may change but if you use the
    T* operator you won't care.
    */
    void ReAlloc(DWORD flags, SIZE_T count) 
    {
        SIZE_T new_size = count * sizeof(T);
        void *new_pv = m_heap->ReAlloc(flags, m_pv, new_size);
        m_pv = new_pv;
        m_count = count;
        m_size = new_size;
    }

    /**
    Returns the size of the allocated memory in bytes
    */
    size_t size() 
    {
        return m_size;
    }

    /**
    Returns the number of structures of type T allocated.
    */
    size_t count() 
    {
        return m_count;
    }

    /**
    Returns the handle of the underlying heap.

    For experts only.
    */
    HANDLE GetHeapHandle() 
    {
        return m_heap->GetHandle();
    }
};

#endif