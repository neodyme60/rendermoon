#include <rendermoon.h>

LambertianBxDF::LambertianBxDF(const Spectrum& reflectance) : m_Reflectance(reflectance)
{

}

LambertianBxDF::~LambertianBxDF()
{

}

float LambertianBxDF::Pdf(const Vec3& wi, const Vec3& wo) const
{
    return AbsCosTheta(wi) * INV_PI; //importance sampling
}

Spectrum LambertianBxDF::f(const Vec3& wo, const Vec3& wi) const
{
    return m_Reflectance * INV_PI;
}

Spectrum LambertianBxDF::Sample_f(const Vec3& wo, Vec3& wi, float u1, float u2, float *pdf) const
{
    wi = CosineSampleHemisphere(u1, u2);
    *pdf = Pdf(wo, wi);
    return f(wo, wi);
}
