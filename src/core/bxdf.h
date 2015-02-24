#if defined(_MSC_VER)
#pragma once
#endif


#ifndef __RENDERMOON_CORE_BXDF__
#define __RENDERMOON_CORE_BXDF__

class BxDF
{
public:
    virtual~BxDF() {}
    virtual float Pdf(const Vec3& wo, const Vec3& wi) const = 0;
    virtual Spectrum f(const Vec3& wo, const Vec3& wi) const = 0;
    virtual Spectrum Sample_f(const Vec3& wo, Vec3& wi, float u1, float u2, float *pdf) const=0;
};

#endif
