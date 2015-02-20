#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_POINT_LIGHT__
#define __RENDERMOON_POINT_LIGHT__

#include <core/light.h>

class PointLight : public Light
{
public:

    PointLight(const Transform& l2w, const Spectrum& intensity);
    virtual ~PointLight() {}

    //implement light
    virtual float Pdf(const Point &p, const Vec3 &wi) const;
    Spectrum Sample_L(const Point &p, float pEpsilon, float time, Vec3 *wi, float *pdf) const;
    Spectrum Sample_L(const Scene *scene, float u1, float u2, float time, Ray *ray, Normal *Ns, float *pdf) const;


protected:
    Point m_LightPos;
    Spectrum m_Intensity;
};

#endif
