#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_INTEGRATORS_AMBIENT_OCCLUSION__
#define __RENDERMOON_INTEGRATORS_AMBIENT_OCCLUSION__


#include <core/surface_integrator.h>

class AmbientOcclusion : public SurfaceIntegrator
{
public:
    AmbientOcclusion(int samples_count, float max_distance);
    virtual ~AmbientOcclusion() {}

    Spectrum Li(const Scene&, const Renderer&, const Ray&, const Intersection &i);

protected:
    int     m_samples_count;
    float   m_max_distance;
};

#endif
