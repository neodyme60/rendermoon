#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_RENDERER_SAMPLER__
#define __RENDERMOON_RENDERER_SAMPLER__

#include <core/renderer.h>

class Spectrum;
class SurfaceIntegrator;
class VolumeIntegrator;

class Sampler : public Renderer
{
public:
	int m_samples;

    Sampler();
    virtual ~Sampler() {}

    Sampler(SurfaceIntegrator * surfaceIntegrator, VolumeIntegrator* volumeIntegrator, int samples);
    void Render(const Scene*);

	Spectrum Li(const Scene *scene, const Ray&, Intersection &i);

protected:
    VolumeIntegrator* m_volumeIntegrator;
    SurfaceIntegrator * m_surfaceIntegrator;
};

#endif


