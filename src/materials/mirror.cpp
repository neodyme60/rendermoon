#include <rendermoon.h>


MirrorMaterial::MirrorMaterial(const Spectrum& kd) : m_kd(kd)
{

}

MirrorMaterial::~MirrorMaterial()
{

}

BSDF * MirrorMaterial::GetBSDF(const DifferentialGeometry &dg) const
{
    BSDF * bsdf = new BSDF(dg.m_Normal);
    bsdf->Add(new SpecularReflection(m_kd));
    return bsdf;
}


