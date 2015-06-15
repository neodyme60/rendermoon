#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_EMITTER__
#define __RENDERMOON_CORE_EMITTER__

#include "abstract_emitter.h"
#include "properties.h"
#include "spectrum.h"
#include "visibility_tester.h"
#include "scene.h"

class VisibilityTester;
class Scene;
class Spectrum;

class Emitter : public AbstractEmitter
{

public:
    Emitter(const Properties &props);
    Emitter(Stream *stream, InstanceManager *manager);

    virtual ~Emitter();

    virtual float Pdf(const Point &p, const Vec3 &wi) const = 0;

    virtual Spectrum Sample_L(const Point &p, float pEpsilon, float time, Vec3 *wi, float *pdf, VisibilityTester &vis) const = 0;
    virtual Spectrum Sample_L(const Scene *scene, float u1, float u2, float time, Ray *ray, Normal *Ns, float *pdf) const = 0;

    virtual Spectrum Le(const Ray &r) const;

    inline int GetSamplesCount()
    {
        return m_samplesCount;
    }

    MTS_DECLARE_CLASS()
protected:
    Transform m_lightToWorld;
    Transform m_worldToLight;
    int       m_samplesCount;
};


#endif
