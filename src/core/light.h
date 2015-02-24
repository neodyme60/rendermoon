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
struct VisibilityTester;

class Light
{

public:
	Light(const Transform& t,  int samples_count = 1);
    virtual ~Light();

    virtual float Pdf(const Point &p, const Vec3 &wi) const = 0;

    virtual Spectrum Sample_L(const Point &p, float pEpsilon, float time, Vec3 *wi, float *pdf, VisibilityTester &vis) const = 0;
    virtual Spectrum Sample_L(const Scene *scene, float u1, float u2, float time, Ray *ray, Normal *Ns, float *pdf) const = 0;

    virtual Spectrum Le(const Ray &r) const;

    inline int GetSamplesCount()
    {
        return nSamples;
    }
protected:
	const Transform m_lightToWorld, m_worldToLight;
    const int nSamples;
};
#endif
