#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_GEOMETRIC_PRIMITIVE__
#define __RENDERMOON_CORE_GEOMETRIC_PRIMITIVE__

class Shape;
#include <core/primitive.h>

class GeometricPrimitive : public Primitive 
{
public:
    GeometricPrimitive(Reference<Shape> s, Reference<Material> m, AreaLight *a);
    bool CanIntersect() const;
    virtual BBox WorldBound() const;
	virtual bool GetIntersection(const Ray &r, Intersection& isect) const;
	virtual bool IsIntersected(const Ray &r) const;
    const AreaLight *GetAreaLight() const;
    const Reference<Shape> GetShape() const;

    void Refine(list<Reference<Primitive> > &refined) const;

    BSDF *GetBSDF(const DifferentialGeometry& dg, const Transform &ObjectToWorld) const;

private:
    Reference<Shape>    m_Shape;
    Reference<Material>	m_Material;
    AreaLight*	m_AreaLight;
};


#endif