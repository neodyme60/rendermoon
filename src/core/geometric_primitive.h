#ifndef __RENDERMOON_CORE_GEOMETRIC_PRIMITIVE__
#define __RENDERMOON_CORE_GEOMETRIC_PRIMITIVE__

class Shape;
#include <core/primitive.h>

class GeometricPrimitive : public Primitive 
{
public:
    GeometricPrimitive(Shape *s, Material *m, AreaLight *a);
    bool CanIntersect() const;
    virtual BBox WorldBound() const;
	virtual bool GetIntersection(const Ray &r, Intersection& isect) const;
	virtual bool IsIntersected(const Ray &r) const;
    const AreaLight *GetAreaLight() const;

//    BSDF *GetBSDF(const DifferentialGeometry &dg, const Transform &ObjectToWorld, MemoryArena &arena) const;
 //   BSSRDF *GetBSSRDF(const DifferentialGeometry &dg, const Transform &ObjectToWorld, MemoryArena &arena) const;
private:
    Shape*		m_shape;
    Material*	m_material;
    AreaLight*	m_areaLight;
};


#endif