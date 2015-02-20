#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_MATERIAL_DIFFUSE__
#define __RENDERMOON_MATERIAL_DIFFUSE__

#include <core/material.h>

class DiffuseMaterial : public Material
{
public:

	DiffuseMaterial(const Spectrum& kd);
    virtual ~DiffuseMaterial();

    virtual BSDF *GetBSDF(const DifferentialGeometry &dg) const;

    Spectrum m_kd;
};

#endif
