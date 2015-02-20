#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_MATERIAL_MIRROR__
#define __RENDERMOON_MATERIAL_MIRROR__

#include <core/material.h>

class MirrorMaterial : public Material
{
public:

    MirrorMaterial(const Spectrum& kd);
    virtual ~MirrorMaterial();

    virtual BSDF *GetBSDF(const DifferentialGeometry &dg) const;

    Spectrum m_kd;
};

#endif
