#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_LAMBERTIAN_BXDF__
#define __RENDERMOON_CORE_LAMBERTIAN_BXDF__

#include <core/spectrum.h>

class LambertianBxDF : public BxDF
{
public:
    LambertianBxDF(const Spectrum& reflectance);
    virtual ~LambertianBxDF();

	float Pdf(const Vec3& wo, const Vec3& wi) const;
    Spectrum f(const Vec3& wo, const Vec3& wi) const;
    Spectrum Sample_f(const Vec3& wo, Vec3& wi, float u1, float u2, float *pdf) const;


protected:
    Spectrum m_Reflectance;
};

#endif
