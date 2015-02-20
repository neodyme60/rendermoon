#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_MATERIAL__
#define __RENDERMOON_CORE_MATERIAL__


#include <core/bsdf.h>
#include <core/intersection.h>
#include <core/memory.h>

class Material : public ReferenceCounted
{
public:
	Material();

    virtual BSDF *GetBSDF(const DifferentialGeometry &dg) const = 0;
};

#endif
