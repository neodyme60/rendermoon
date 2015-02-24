#include <rendermoon.h>

PointLight::PointLight(const Transform& l2w, const Spectrum & intensity) : Light(l2w), m_Intensity(intensity)
{
    m_LightPos = l2w.TransformPoint(Point(0.0f, 0.0f, 0.0f));
}

float PointLight::Pdf(const Point &p, const Vec3 &wi) const
{
	return 0.0f;
}

Spectrum PointLight::Sample_L(const Point &p, float pEpsilon, float time, Vec3 *wi, float *pdf, VisibilityTester &visibility) const
{
    *wi = Normalize(m_LightPos-p);
    *pdf = 1.0f;
    visibility.SetSegment(p, pEpsilon, m_LightPos, 0.0f, time);
    return m_Intensity * (1.0f / DistanceSquared(m_LightPos, p));
}

Spectrum PointLight::Sample_L(const Scene *scene, float u1, float u2, float time, Ray *ray, Normal *Ns, float *pdf) const
{
    //todo
    return Spectrum(0.0);
}

