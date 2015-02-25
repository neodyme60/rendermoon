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
    Shape(const Transform *o2w, const Transform *w2o, bool ro);
    virtual ~Shape();

    virtual BBox ObjectBound() const = 0;
    virtual BBox WorldBound() const;

    virtual void Refine(vector<Reference<Shape> > &refined) const;

    virtual bool CanIntersect() const;
    virtual bool GetIntersection(const Ray &ray, float *tHit, DifferentialGeometry&) const;
    virtual bool IsIntersected(const Ray &ray) const;

    virtual float Area() const;

    //sampling uniformy by repect to area
    virtual Point SamplingUniformlyByRespectToArea(float u1, float u2, Normal *) const;
    virtual float Pdf(const Point &Pshape) const;

    //sampling by respect to solid angle
    virtual Point SamplingByRespectToSolidAngle(const Point &P, float u1, float u2, Normal *) const;
    virtual float Pdf(const Point &p, const Vec3 &wi) const;

    // Shape Public Data
    const Transform *m_ObjectToWorld, *m_WorldToObject;
    const bool m_ReverseOrientation;
};

#endif
