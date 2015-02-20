#include <rendermoon.h>


PhongMaterial::PhongMaterial(const Spectrum& kd, int exponent) : m_kd(kd), m_exponent(exponent)
{

}

PhongMaterial::~PhongMaterial()
{

}

BSDF * PhongMaterial::GetBSDF(const DifferentialGeometry &dg) const
{
    BSDF * bsdf = new BSDF(dg.m_Normal);
    bsdf->Add(new GlossyReflection(m_kd, m_exponent));
    return bsdf;
}


