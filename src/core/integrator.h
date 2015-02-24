#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_INTEGRATOR__
#define __RENDERMOON_CORE_INTEGRATOR__

enum DirectLightingStrategy { DIRECT_LIGHTING_BRDF_ONLY, DIRECT_LIGHTING_LIGHT_ONLY, DIRECT_LIGHTING_MIS };

class Integrator
{
public:
    Integrator() {}

    virtual void PreProcess() {}
    virtual void PostProcess() {}

    virtual ~Integrator() {}
};

Spectrum DirectLightingEstimateOneLight(const Scene& scene, const Renderer &renderer, const Point &p, const Normal &n, const Vec3 &wo, float time, BSDF *bsdf, Light*, DirectLightingStrategy sls = DIRECT_LIGHTING_MIS);
Spectrum DirectLightingEstimate(const Scene& scene, const Renderer &renderer, const Point &p, const Normal &n, const Vec3 &wo, float time, BSDF *bsdf, DirectLightingStrategy sls = DIRECT_LIGHTING_MIS);

#endif
