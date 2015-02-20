#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_SHAPE__
#define __RENDERMOON_CORE_SHAPE__

#include <core/memory.h>

class DifferentialGeometry;

class Shape : public ReferenceCounted
{
public:
    Shape(const Transform *o2w, const Transform *w2o);
    virtual ~Shape();

    virtual BBox ObjectBound() const = 0;
    virtual BBox WorldBound() const;

    virtual void Refine(vector<Reference<Shape> > &refined) const;

    virtual bool CanIntersect() const;
    virtual bool GetIntersection(const Ray &ray, float *tHit, DifferentialGeometry&) const;
    virtual bool IsIntersected(const Ray &ray) const;

    virtual float Area() const;

    virtual float Pdf(const Point &p, const Vec3 &wi) const;
    virtual float Pdf(const Point &Pshape) const;

    virtual Point SampleUniform(float u1, float u2, Normal*) const;
    virtual Point SampleBySolidAngle(const Point &P, float u1, float u2, Normal*) const;

    // Shape Public Data
    const Transform *m_ObjectToWorld, *m_WorldToObject;
};

#endif
