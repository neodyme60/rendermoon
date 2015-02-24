#include <rendermoon.h>

Light::Light(const Transform& t, int samples_count) : m_lightToWorld(t), m_worldToLight(m_lightToWorld.GetInverse()), nSamples(samples_count)
{
}

Light::~Light()
{

}

Spectrum Light::Le(const Ray &r) const
{
    return Spectrum(0.0);
}

