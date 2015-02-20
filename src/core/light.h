#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_LIGHT__
#define __RENDERMOON_CORE_LIGHT__

#include <core/transform.h>
class Spectrum;
struct Intersection;
class Ray;
class Scene;

class Light
{

public:
	Light(const Transform& t);
    virtual ~Light();

    virtual float Pdf(const Point &p, const Vec3 &wi) const = 0;

    virtual Spectrum Sample_L(const Point &p, float pEpsilon, float time, Vec3 *wi, float *pdf) const = 0;
    virtual Spectrum Sample_L(const Scene *scene, float u1, float u2, float time, Ray *ray, Normal *Ns, float *pdf) const = 0;

    virtual Spectrum Le(const Ray &r) const;

protected:
	Transform m_lightToWorld, m_worldToLight;
};
#endif
