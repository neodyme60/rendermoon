#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_REFERENCE__
#define __RENDERMOON_CORE_REFERENCE__

#include "parallel.h"

class ReferenceCounted
{
public:
    ReferenceCounted() { m_refCount = 0; }
    AtomicInt32 m_refCount;
private:
//    ReferenceCounted(const ReferenceCounted &);
//    ReferenceCounted &operator=(const ReferenceCounted &);

    int getRefCount() const
    {
        return m_refCount;
    }
};

template <typename T>
class Reference
{
public:
    // Reference Public Methods
    Reference(T *p = NULL)
    {
        ptr = p;
        if (ptr)
            AtomicAdd(&ptr->m_refCount, 1);
    }

    Reference(const Reference<T> &r)
    {
        ptr = r.ptr;
        if (ptr)
            AtomicAdd(&ptr->m_refCount, 1);
    }

    Reference &operator=(const Reference<T> &r)
    {
        if (r.ptr) AtomicAdd(&r.ptr->m_refCount, 1);
        if (ptr && AtomicAdd(&ptr->m_refCount, -1) == 0) delete ptr;
        ptr = r.ptr;
        return *this;
    }

    Reference &operator=(T *p)
    {
        if (p) AtomicAdd(&p->m_refCount, 1);
        if (ptr && AtomicAdd(&ptr->m_refCount, -1) == 0) delete ptr;
        ptr = p;
        return *this;
    }

    ~Reference()
    {
        if (ptr && AtomicAdd(&ptr->m_refCount, -1) == 0)
            delete ptr;
    }

    T *operator->() { return ptr; }
    const T *operator->() const { return ptr; }
    operator bool() const { return ptr != NULL; }
    const T *GetPtr() const { return ptr; }
private:
    T *ptr;
};


#endif
