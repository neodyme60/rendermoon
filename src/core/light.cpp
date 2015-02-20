#include <rendermoon.h>

Light::Light(const Transform& t) : m_lightToWorld(t), m_worldToLight(m_lightToWorld.GetInverse())
{
}

Light::~Light()
{

}

Spectrum Light::Le(const Ray &r) const
{
    return Spectrum(0.0);
}