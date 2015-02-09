#include <rendermoon.h>

class BBox;

GeometricPrimitive::GeometricPrimitive(Shape* s, Material* m, AreaLight *a) : m_shape(s), m_material(m), m_areaLight(a)
{
}

BBox GeometricPrimitive::WorldBound() const 
{
    return m_shape->WorldBound();
}

bool GeometricPrimitive::IsIntersected(const Ray &r) const 
{
    return m_shape->IsIntersected(r);
}

bool GeometricPrimitive::CanIntersect() const 
{
    return m_shape->CanIntersect();
}

bool GeometricPrimitive::GetIntersection(const Ray &r, Intersection& isect) const 
{
    float thit, rayEpsilon;
    if (!m_shape->GetIntersection(r, &thit, &rayEpsilon, isect))
        return false;
/*
    isect.primitive = this;
    isect.WorldToObject = *shape->WorldToObject;
    isect.ObjectToWorld = *shape->ObjectToWorld;
    isect.shapeId = shape->shapeId;
    isect.primitiveId = primitiveId;
    isect.rayEpsilon = rayEpsilon;
    r.maxt = thit;

*/    return true;
}

/*
const AreaLight *GeometricPrimitive::GetAreaLight() const
{
    return areaLight;
}


BSDF *GeometricPrimitive::GetBSDF(const DifferentialGeometry &dg, const Transform &ObjectToWorld, ) const 
{
    DifferentialGeometry dgs;
    shape->GetShadingGeometry(ObjectToWorld, dg, &dgs);
    return material->GetBSDF(dg, dgs, arena);
}


BSSRDF *GeometricPrimitive::GetBSSRDF(const DifferentialGeometry &dg,
                                  const Transform &ObjectToWorld,
                                  MemoryArena &arena) const {
    DifferentialGeometry dgs;
    shape->GetShadingGeometry(ObjectToWorld, dg, &dgs);
    return material->GetBSSRDF(dg, dgs, arena);
}

*/