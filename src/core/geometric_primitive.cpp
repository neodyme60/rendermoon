#include <rendermoon.h>

class BBox;

GeometricPrimitive::GeometricPrimitive(Reference<Shape> s, Reference<Material> m, AreaLight *a) : m_Shape(s), m_Material(m), m_AreaLight(a)
{
}

void GeometricPrimitive::Refine(list<Reference<Primitive> > &refined) const
{
    vector<Reference<Shape> > r;
    m_Shape->Refine(r);
    for (uint32_t i = 0; i < r.size(); ++i)
    {
        GeometricPrimitive *gp = new GeometricPrimitive(r[i], m_Material, m_AreaLight);
        refined.push_back(gp);
    }
}


BBox GeometricPrimitive::WorldBound() const 
{
    return m_Shape->WorldBound();
}

bool GeometricPrimitive::IsIntersected(const Ray &r) const 
{
    return m_Shape->IsIntersected(r);
}

bool GeometricPrimitive::CanIntersect() const 
{
    return m_Shape->CanIntersect();
}

bool GeometricPrimitive::GetIntersection(const Ray &r, Intersection& isect) const
{
    float thit;
    if (!m_Shape->GetIntersection(r, &thit, isect.m_DifferentialGeometry))
        return false;

    isect.m_Primitive =  const_cast<GeometricPrimitive*>(this);
    isect.m_WorldToObject = *m_Shape->m_WorldToObject;
    isect.m_ObjectToWorld = *m_Shape->m_ObjectToWorld;
/*
    isect.shapeId = shape->shapeId;
    isect.primitiveId = primitiveId;
*/
    const_cast<Ray &>(r).maxt = thit;  //todo very bad

    return true;
}

const AreaLight *GeometricPrimitive::GetAreaLight() const
{
    return m_AreaLight;
}

const Reference<Shape> GeometricPrimitive::GetShape() const
{
    return m_Shape;
}

BSDF *GeometricPrimitive::GetBSDF(const DifferentialGeometry& dg, const Transform &ObjectToWorld) const
{
	return m_Material->GetBSDF(dg);
}


/*
BSSRDF *GeometricPrimitive::GetBSSRDF(const DifferentialGeometry &dg,
                                  const Transform &ObjectToWorld,
                                  MemoryArena &arena) const {
    DifferentialGeometry dgs;
    shape->GetShadingGeometry(ObjectToWorld, dg, &dgs);
    return material->GetBSSRDF(dg, dgs, arena);
}

*/