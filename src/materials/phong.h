#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_MATERIAL_PHONG__
#define __RENDERMOON_MATERIAL_PHONG__

#include <core/material.h>

class PhongMaterial : public Material
{
public:

    PhongMaterial(const Spectrum& kd, int exponent);
    virtual ~PhongMaterial();

    virtual BSDF *GetBSDF(const DifferentialGeometry &dg) const;

    Spectrum m_kd;
    int m_exponent;
};

#endif
