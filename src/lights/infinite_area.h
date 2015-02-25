#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_INFINIT_AREA_LIGHT__
#define __RENDERMOON_INFINIT_AREA_LIGHT__

#include <core/light.h>

class InfiniteAreaLight : public Light
{
public:

    InfiniteAreaLight(const Transform& l2w, const Spectrum& intensity);
    virtual ~InfiniteAreaLight() {}

    virtual float Pdf(const Point &p, const Vec3 &wi) const;
    Spectrum Sample_L(const Point &p, float pEpsilon, float time, Vec3 *wi, float *pdf, VisibilityTester &visibility) const;
    Spectrum Sample_L(const Scene *scene, float u1, float u2, float time, Ray *ray, Normal *Ns, float *pdf) const;


protected:
    // InfiniteAreaLight Private Data
//    MIPMap<RGBSpectrum> *radianceMap;
    Distribution2D *distribution;
};

#endif
