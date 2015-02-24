#include <rendermoon.h>

DirectionalLight::DirectionalLight(const Transform& l2w, const Spectrum& radiance, const Vec3& direction) : Light(l2w), m_L(radiance)
{
    m_Direction = Normalize(l2w.TransformVec3(direction));
}

float DirectionalLight::Pdf(const Point &p, const Vec3 &wi) const
{
    return 0.0f;
}

Spectrum DirectionalLight::Sample_L(const Point &p, float pEpsilon, float time, Vec3 *wi, float *pdf, VisibilityTester &visibility) const
{
    *wi = m_Direction;
    *pdf = 1.0f;
    visibility.SetRay(p, pEpsilon, *wi, time);
    return m_L;
}

Spectrum DirectionalLight::Sample_L(const Scene *scene, float u1, float u2, float time, Ray *ray, Normal *Ns, float *pdf) const
{
    //todo
    return Spectrum(0.0);
}
