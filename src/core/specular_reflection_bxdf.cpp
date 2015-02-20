#include <rendermoon.h>

SpecularReflection::SpecularReflection(const Spectrum &r) :  m_Reflectance(r)
{
}

Spectrum SpecularReflection::f(const Vec3&, const Vec3&) const
{
    return Spectrum(0.0f);
}

Spectrum SpecularReflection::Sample_f(const Vec3& wo, Vec3& wi, float u1, float u2, float *pdf) const
{
    wi = Vec3(-wo.x, -wo.y, wo.z);
    *pdf = 1.0f;
	return f(wo, wi);
}

float SpecularReflection::Pdf(const Vec3& wo, const Vec3& wi) const
{
    return 0.0f;
}

SpecularReflection::~SpecularReflection()
{

}
