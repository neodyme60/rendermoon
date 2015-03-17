#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_TEXTURE__
#define __RENDERMOON_CORE_TEXTURE__

/*
#include "pbrt.h"
#include "spectrum.h"
#include "geometry.h"
#include "transform.h"
#include "memory.h"
*/

// MIPMap Declarations
typedef enum {
    TEXTURE_REPEAT,
    TEXTURE_BLACK,
    TEXTURE_CLAMP
} ImageWrap;

class TextureMapping2D
{
public:
    // TextureMapping2D Interface
    virtual ~TextureMapping2D() { }
    virtual void Map(const DifferentialGeometry &dg, float *s, float *t, float *dsdx, float *dtdx, float *dsdy, float *dtdy) const = 0;
};

class SphericalMapping2D : public TextureMapping2D
{
public:
    SphericalMapping2D(const Transform &toSph) : m_WorldToTexture(toSph)
    {
    }
    void Map(const DifferentialGeometry &dg, float *s, float *t, float *dsdx, float *dtdx, float *dsdy, float *dtdy) const;
private:
    void sphere(const Point &P, float *s, float *t) const;
    Transform m_WorldToTexture;
};


class PlanarMapping2D : public TextureMapping2D
{
public:
    void Map(const DifferentialGeometry &dg, float *s, float *t, float *dsdx, float *dtdx, float *dsdy, float *dtdy) const;
    PlanarMapping2D(const Vec3 &vv1, const Vec3 &vv2, float dds = 0, float ddt = 0) : vs(vv1), vt(vv2), ds(dds), dt(ddt)
    {
    }
private:
    const Vec3 vs, vt;
    const float ds, dt;
};


class TextureMapping3D
{
public:
    // TextureMapping3D Interface
    virtual ~TextureMapping3D() { }
    virtual Point Map(const DifferentialGeometry &dg, Vec3 *dpdx, Vec3 *dpdy) const = 0;
};


template <typename T>
class Texture : public ReferenceCounted
{
public:
    virtual T Evaluate(const DifferentialGeometry &) const = 0;
    virtual ~Texture() { }
};

#endif
