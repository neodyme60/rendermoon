#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_INTEGRATORS_PATHTRACING__
#define __RENDERMOON_INTEGRATORS_PATHTRACING__

#include <core/surface_integrator.h>

class PathTracing : public SurfaceIntegrator
{
public:
    PathTracing();
    virtual ~PathTracing();

    Spectrum Li(const Scene&, const Renderer&, const Ray&, const Intersection &i);

protected:
    DirectLightingStrategy m_dls;
};

#endif
