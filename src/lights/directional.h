#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_DIRECTIONAL_LIGHT__
#define __RENDERMOON_DIRECTIONAL_LIGHT__

#include <core/light.h>

class DirectionalLight : public Light
{
public:
	DirectionalLight(const Transform& l2w, const Spectrum& radiance, const Vec3& direction);
    virtual ~DirectionalLight() {}

    //implement light
    virtual float Pdf(const Point &p, const Vec3 &wi) const;
    Spectrum Sample_L(const Point &p, float pEpsilon, float time, Vec3 *wi, float *pdf) const;
    Spectrum Sample_L(const Scene *scene, float u1, float u2, float time, Ray *ray, Normal *Ns, float *pdf) const;

protected:
    Vec3        m_Direction;
    Spectrum    m_L;
};

#endif
