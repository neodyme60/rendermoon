#ifndef __RENDERMOON_CORE_SURFACE_INTEGRATOR__
#define __RENDERMOON_CORE_SURFACE_INTEGRATOR__

#include <core/integrator.h>

class SurfaceIntegrator : public Integrator
{
protected:

public:
    SurfaceIntegrator() : Integrator() {}
    virtual ~SurfaceIntegrator() {}

    virtual Spectrum Li(const Scene&, Ray&, Intersection&)=0;
};

#endif
