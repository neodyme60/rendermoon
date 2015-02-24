#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_PRIMITIVE__
#define __RENDERMOON_CORE_PRIMITIVE__

#include "differential_geometry.h"
#include <core/memory.h>

class Transform;
struct Intersection;
class Ray;
class Normal;
class Spectrum;
class Material;
class Point;
class BSDF;

class Primitive : public ReferenceCounted
{
public:
	Primitive();
    virtual ~Primitive(){}

    virtual BBox WorldBound() const = 0;
    virtual bool GetIntersection(const Ray &r, Intersection&)  const = 0;
    virtual bool IsIntersected(const Ray &r) const = 0;
    virtual bool CanIntersect() const;
    virtual void Refine(vector<Reference<Primitive> > &refined) const;
    void FullyRefine(vector<Reference<Primitive> > &refined) const;
    virtual const AreaLight *GetAreaLight() const = 0;

	virtual Spectrum L(Intersection& i, Point& light_point, Normal& light_nornal);

	virtual BSDF *GetBSDF(const DifferentialGeometry& dg, const Transform &ObjectToWorld) const = 0;

};

#endif

