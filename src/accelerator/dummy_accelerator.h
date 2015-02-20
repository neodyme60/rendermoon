#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_ACCELERATOR_DUMMY__
#define __RENDERMOON_ACCELERATOR_DUMMY__

#include <core/aggregate.h>

class DummyAccelerator : public Aggregate
{
protected:
    std::list<Reference<Primitive>>   m_data;

public:
	DummyAccelerator(std::list<Reference<Primitive>>& data)
    {
        m_data = data;
    }
    virtual ~DummyAccelerator() {}

    BSDF *GetBSDF(const DifferentialGeometry &dg, const Transform &) const;
    const AreaLight *GetAreaLight() const;
    bool CanIntersect() const { return true; }
    bool GetIntersection(const Ray &r, Intersection&) const;
    bool IsIntersected(const Ray &r) const;
};

#endif
