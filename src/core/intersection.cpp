#include <rendermoon.h>

BSDF *Intersection::GetBSDF(const Ray &ray) const
{
    BSDF *bsdf = m_Primitive->GetBSDF(m_DifferentialGeometry, m_ObjectToWorld);
	return bsdf;
}

Intersection::Intersection()
{
    m_Primitive = NULL;
}

Spectrum Intersection::Le(const Vec3 &w) const
{
    const AreaLight *area = m_Primitive->GetAreaLight();
    return area ? area->L(m_DifferentialGeometry.m_Point, m_DifferentialGeometry.m_Normal, w) : Spectrum(0.0f);
}
