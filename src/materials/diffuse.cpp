#include <rendermoon.h>


DiffuseMaterial::DiffuseMaterial(const Spectrum& kd) : m_kd(kd)
{
}

DiffuseMaterial::~DiffuseMaterial()
{

}

BSDF * DiffuseMaterial::GetBSDF(const DifferentialGeometry &dg) const
{
	BSDF * bsdf = new BSDF(dg.m_Normal);
	bsdf->Add(new LambertianBxDF(m_kd));
	return bsdf;
}


