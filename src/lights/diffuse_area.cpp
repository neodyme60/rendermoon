#include <rendermoon.h>

DiffuseAreaLight::DiffuseAreaLight(const Transform& l2w, const Spectrum & intensity, int samples_count, const Reference<Shape> &shape) :
        AreaLight(l2w, shape, samples_count), m_Lemit(intensity)
{
    m_ShapeSet = new ShapeSet(shape);
    m_area = m_ShapeSet->Area();
}

DiffuseAreaLight::~DiffuseAreaLight()
{
    delete m_ShapeSet;
}

float DiffuseAreaLight::Pdf(const Point &p, const Vec3 &wi) const
{
    return m_ShapeSet->Pdf(p, wi);
}

Spectrum DiffuseAreaLight::L(const Point &p, const Normal &n, Vec3 const &w) const
{
    float d = Dot(n, w);
    return d > 0.0f ? m_Lemit : 0.0f;
}

Spectrum DiffuseAreaLight::Sample_L(const Point &p, float pEpsilon, float time, Vec3 *wi, float *pdf, VisibilityTester &visibility) const
{
    Normal n;
	float u1 = GetRandom();
	float u2 = GetRandom();

    Point ps = m_ShapeSet->Sample(p, u1, u2, &n);
    *wi = Normalize(ps - p);
    *pdf = this->Pdf(p, *wi);

	visibility.SetSegment(p, pEpsilon, ps, 1e-3f, time);
	return 	L(ps, n, -*wi);
}

Spectrum DiffuseAreaLight::Sample_L(const Scene *scene, float u1, float u2, float time, Ray *ray, Normal *n, float *pdf) const
{
    Point org = m_ShapeSet->Sample(n, GetRandom(), GetRandom());
    Vec3 dir = UniformSampleSphere(u1, u2);
    if (Dot(dir, *n) < 0.0)
        dir *= -1.0f;
    *ray = Ray(org, dir, 1e-3f, INFINITY, time);
    *pdf = m_ShapeSet->Pdf(org) * INV_TWOPI;
    Spectrum Ls = L(org, *n, dir);
	return Ls;
}
