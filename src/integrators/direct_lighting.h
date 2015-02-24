#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_INTEGRATORS_DIRECTLIGHTING__
#define __RENDERMOON_INTEGRATORS_DIRECTLIGHTING__

#include <core/surface_integrator.h>

class DirectLighting : public SurfaceIntegrator
{
public:
    DirectLighting(DirectLightingStrategy dle = DIRECT_LIGHTING_MIS);
    virtual ~DirectLighting();

    Spectrum Li(const Scene&, const Renderer&, const Ray&, const Intersection &i);

protected:
    DirectLightingStrategy m_dls;
};

#endif
