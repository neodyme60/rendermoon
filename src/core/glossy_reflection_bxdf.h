#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_GLOSSY_REFLECTION_BXDF__
#define __RENDERMOON_CORE_GLOSSY_REFLECTION_BXDF__

#include <core/spectrum.h>

class GlossyReflection : public BxDF
{
public:
    GlossyReflection(const Spectrum &r, float n);
    virtual ~GlossyReflection();
    Spectrum f(const Vec3&, const Vec3&) const;
    Spectrum Sample_f(const Vec3& wo, Vec3& wi, float u1, float u2, float *pdf) const;
    float Pdf(const Vec3 &wo, const Vec3 &wi) const;

protected:
    float m_exponent;
    Spectrum m_Reflectance;
};

#endif
