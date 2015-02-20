#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_INTEGRATOR__
#define __RENDERMOON_CORE_INTEGRATOR__

class Integrator
{
public:
    Integrator() {}

    virtual void PreProcess() {}
    virtual void PostProcess() {}

    virtual ~Integrator() {}
};


Spectrum DirectLightingEstimate(const Scene& scene, const Renderer *renderer, const Point &p, const Normal &n, const Vec3 &wo, float time, BSDF *bsdf);

#endif
