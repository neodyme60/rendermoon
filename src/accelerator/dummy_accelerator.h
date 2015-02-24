#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_ACCELERATOR_DUMMY__
#define __RENDERMOON_ACCELERATOR_DUMMY__

#include <core/aggregate.h>

using namespace std;

class DummyAccelerator : public Aggregate
{
protected:
    vector<Reference<Primitive>>    m_data;
    BBox                            m_worldBound;

public:
	DummyAccelerator(vector<Reference<Primitive>>& data);
    virtual ~DummyAccelerator() {}

    virtual BBox WorldBound() const;

    BSDF *GetBSDF(const DifferentialGeometry &dg, const Transform &) const;
    const AreaLight *GetAreaLight() const;
    bool CanIntersect() const { return true; }
    bool GetIntersection(const Ray &r, Intersection&) const;
    bool IsIntersected(const Ray &r) const;
};

#endif
