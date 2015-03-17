#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_RENDERER_SAMPLER__
#define __RENDERMOON_RENDERER_SAMPLER__

#include <core/renderer.h>

class Spectrum;
class SurfaceIntegrator;
class VolumeIntegrator;

struct thread_data{
	int  thread_id;
	Scene* scene;
	int width;
	int ystart;
	int yend;
	char *message;
};

class Sampler : public Renderer
{
public:
	int m_samples;

    Sampler();
    virtual ~Sampler() {}

    Sampler(SurfaceIntegrator * surfaceIntegrator, VolumeIntegrator* volumeIntegrator, int samples);
    void Render(const Scene*);
	void Task(void*);
	Spectrum Li(const Scene *scene, const Ray&, Intersection &i);

protected:
    VolumeIntegrator* m_volumeIntegrator;
    SurfaceIntegrator * m_surfaceIntegrator;
};

#endif


