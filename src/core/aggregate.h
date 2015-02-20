#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_AGGREAGATE__
#define __RENDERMOON_CORE_AGGREAGATE__

#include <core/primitive.h>

class BSDF;

class Aggregate : public Primitive 
{
public:
/*
    const AreaLight *GetAreaLight() const;
*/
    BSDF *GetBSDF(const DifferentialGeometry& dg, const Transform &ObjectToWorld) const;
};

#endif
