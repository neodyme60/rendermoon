#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_SHAPE_SPHERE__
#define __RENDERMOON_SHAPE_SPHERE__

#include <core/shape.h>

struct Intersection;

class Sphere : public Shape
{
public:

    Sphere(Transform* o2w, Transform* w2o, bool ro, float rad);

	BBox ObjectBound() const;

    virtual bool GetIntersection(const Ray &ray, float *tHit, DifferentialGeometry&) const;
    virtual bool IsIntersected(const Ray &ray) const;
    virtual bool CanIntersect() const;

    virtual float Area() const;

    virtual Point SampleUniform(float u1, float u2, Normal *Ns) const;
    virtual Point SampleBySolidAngle(const Point &P, float u1, float u2, Normal *Ns) const;

    virtual float Pdf(const Point &p, const Vec3 &wi) const;

protected:
    float	m_radius;
};

#endif
