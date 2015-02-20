#include <rendermoon.h>


BSDF::BSDF(const Normal &n)
{
    m_normal = n;
    CoordinateSystem(Vec3(m_normal), &m_tn, &m_sn);
}

void BSDF::Add(BxDF *bxdf)
{
    m_bxdfs.push_back(bxdf);
}

Vec3 BSDF::WorldToLocal(const Vec3& v) const
{
    return Vec3(Dot(v, m_sn), Dot(v, m_tn), Dot(v, m_normal));
}

Vec3 BSDF::LocalToWorld(const Vec3& v) const
{
    return Vec3(
            m_sn.x * v.x + m_tn.x * v.y + m_normal.x * v.z,
            m_sn.y * v.x + m_tn.y * v.y + m_normal.y * v.z,
            m_sn.z * v.x + m_tn.z * v.y + m_normal.z * v.z);
}

float BSDF::Pdf(const Vec3& woW, const Vec3& wiW) const
{
    if (m_bxdfs.size() == 0.0)
        return 0.0;

//    PBRT_STARTED_BSDF_PDF();
    Vec3 wo = WorldToLocal(woW), wi = WorldToLocal(wiW);
    float pdf = 0.0f;
    for (std::vector<BxDF*>::const_iterator it = m_bxdfs.begin() ; it != m_bxdfs.end(); ++it)
    {
        pdf += (*it)->Pdf(wo, wi);
    }
//    PBRT_FINISHED_BSDF_PDF();
    return pdf;
}

Spectrum BSDF::f(const Vec3& woW, const Vec3& wiW) const
{
//    PBRT_STARTED_BSDF_EVAL();
    Vec3 wi = WorldToLocal(wiW), wo = WorldToLocal(woW);
    Spectrum f = 0.0;
    for (std::vector<BxDF*>::const_iterator it = m_bxdfs.begin() ; it != m_bxdfs.end(); ++it)
    {
        f += (*it)->f(wo, wi);
    }
//    PBRT_FINISHED_BSDF_EVAL();
    return f;
}

Spectrum BSDF::Sample_f(const Vec3& woW, Vec3& wiW, float *pdf) const
{
    //todo multi bxdf
    BxDF * bxdf = m_bxdfs[0];

    Vec3 wo = WorldToLocal(woW);
    Vec3 wi;
    *pdf = 0.f;
    Spectrum f = bxdf->Sample_f(wo, wi, GetRandom(), GetRandom(), pdf);
    wiW = LocalToWorld(wi);

    return f;
}