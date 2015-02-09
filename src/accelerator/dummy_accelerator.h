#ifndef __RENDERMOON_ACCELERATOR_DUMMY__
#define __RENDERMOON_ACCELERATOR_DUMMY__

#include <core/accelerator.h>

class DummyAccelerator : public Accelerator
{
protected:
    std::list<Primitive*>   m_data;

public:
    DummyAccelerator(std::list<Primitive*> data) : Accelerator()
    {
        m_data = data;
    }
    virtual ~DummyAccelerator() {}

    bool CanIntersect() const { return true; }
    bool GetIntersection(const Ray &r, Intersection&) const;
    bool IsIntersected(const Ray &r) const;
};

#endif
