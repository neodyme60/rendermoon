#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_VOLUME_INTEGRATOR__
#define __RENDERMOON_CORE_VOLUME_INTEGRATOR__

#include <core/integrator.h>

class VolumeIntegrator : public Integrator
{
protected:

public:
    VolumeIntegrator() : Integrator() {}
    virtual ~VolumeIntegrator() {}

    virtual Spectrum Li(Scene*, Ray*)=0;
};

#endif
