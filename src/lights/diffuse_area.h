#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_DIFFUSE_LIGHT__
#define __RENDERMOON_DIFFUSE_LIGHT__

#include <core/area_light.h>

class DiffuseAreaLight : public AreaLight
{
public:
    DiffuseAreaLight(const Transform& l2w, const Spectrum & intensity, const Reference<Shape> &shape);
    virtual ~DiffuseAreaLight();

    //implement arealight
    virtual Spectrum L(const Point &p, const Normal &n, Vec3 const &w) const;

    //implement light
    virtual float Pdf(const Point &p, const Vec3 &wi) const;
    Spectrum Sample_L(const Point &p, float pEpsilon, float time, Vec3 *wi, float *pdf) const;
    Spectrum Sample_L(const Scene *scene, float u1, float u2, float time, Ray *ray, Normal *Ns, float *pdf) const;

protected:
    Spectrum m_Lemit;
    float area;
};

#endif
