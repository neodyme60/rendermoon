#ifndef __RENDERMOON_INTEGRATORS_DIRECTLIGHTING__
#define __RENDERMOON_INTEGRATORS_DIRECTLIGHTING__

#include <core/surface_integrator.h>

class DirectLighting : public SurfaceIntegrator
{
public:
    DirectLighting() {}
    virtual ~DirectLighting() {}

    Spectrum Li(const Scene&, Ray&, Intersection &i);
};

#endif
