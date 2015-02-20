#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_INTERSECTION__
#define __RENDERMOON_CORE_INTERSECTION__

class GeometricPrimitive;
class Shape;

struct Intersection
{
    Intersection();

	Primitive*              m_Primitive;
	Transform               m_WorldToObject, m_ObjectToWorld;
    DifferentialGeometry    m_DifferentialGeometry;

	BSDF *      GetBSDF(const Ray &ray) const;
    Spectrum Le(const Vec3& wo) const;
};

#endif
