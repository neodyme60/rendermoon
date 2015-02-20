#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_SPECULAR_REFLECTION_BXDF__
#define __RENDERMOON_CORE_SPECULAR_REFLECTION_BXDF__

#include <core/spectrum.h>

class SpecularReflection : public BxDF
{
public:
    SpecularReflection(const Spectrum &r);
    virtual ~SpecularReflection();
    Spectrum f(const Vec3&, const Vec3&) const;
    Spectrum Sample_f(const Vec3& wo, Vec3& wi, float u1, float u2, float *pdf) const;
    float Pdf(const Vec3& wo, const Vec3& wi) const;

protected:

    Spectrum m_Reflectance;
};

#endif

