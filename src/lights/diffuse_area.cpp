#include <rendermoon.h>

DiffuseAreaLight::DiffuseAreaLight(const Transform& l2w, const Spectrum & intensity, const Reference<Shape> &shape) : AreaLight(l2w, shape), m_Lemit(intensity)
{
    area = shape->Area();
}

DiffuseAreaLight::~DiffuseAreaLight()
{

}

float DiffuseAreaLight::Pdf(const Point &p, const Vec3 &wi) const
{
    return 0;
}

Spectrum DiffuseAreaLight::L(const Point &p, const Normal &n, Vec3 const &w) const
{
    return Dot(n, w) > 0.f ? m_Lemit : 0.f;
}

Spectrum DiffuseAreaLight::Sample_L(const Point &p, float pEpsilon, float time, Vec3 *wi, float *pdf) const
{
    Normal n;
    Point ps = m_Shape->SampleUniform(GetRandom(), GetRandom(), &n);
    *wi = Normalize(ps - p);
    *pdf = m_Shape->Pdf(p, *wi);
//    visibility->SetSegment(p, pEpsilon, ps, 1e-3f, time);
    Spectrum Ls = L(ps, n, -*wi);
    return Ls;
}

Spectrum DiffuseAreaLight::Sample_L(const Scene *scene, float u1, float u2, float time, Ray *ray, Normal *n, float *pdf) const
{
    Point org = m_Shape->SampleUniform(GetRandom(), GetRandom(), n);
    Vec3 dir = UniformSampleSphere(u1, u2);
    if (Dot(dir, *n) < 0.0)
        dir *= -1.0f;
    *ray = Ray(org, dir, 1e-3f, INFINITY, time);
    *pdf = m_Shape->Pdf(org) * INV_TWOPI;
    Spectrum Ls = L(org, *n, dir);

	return Ls;
}
