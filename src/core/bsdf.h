#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_BSDF__
#define __RENDERMOON_CORE_BSDF__

#include <vector>
class BxDF;

class BSDF
{
public:
    BSDF(const Normal &n);
    void Add(BxDF* bxdf);

    Vec3 WorldToLocal(const Vec3 &v) const;
    Vec3 LocalToWorld(const Vec3 &v) const;

    Spectrum Sample_f(const Vec3& wo, Vec3& wi, float* pdf) const;
    float Pdf(const Vec3& wo, const Vec3& wi) const;
    Spectrum f(const Vec3& woW, const Vec3& wiW) const;
private:
    std::vector<BxDF*> m_bxdfs;

    Normal  m_normal;
    Vec3    m_sn, m_tn;
};

#endif
