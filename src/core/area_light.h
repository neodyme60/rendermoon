#if defined(_MSC_VER)
#pragma once
#endif


#ifndef __RENDERMOON_CORE_AREA_LIGHT__
#define __RENDERMOON_CORE_AREA_LIGHT__

#include "light.h"
#include "shape.h"

class Shape;

class AreaLight : public Light
{
public:
    AreaLight(const Transform& l2w, const Reference<Shape> &shape);
    virtual ~AreaLight();

    virtual Spectrum L(const Point &p, const Normal &n, const Vec3 &w) const = 0;

protected:
    Reference<Shape> m_Shape;
};

#endif
