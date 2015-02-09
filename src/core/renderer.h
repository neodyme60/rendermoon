#ifndef __RENDERMOON_CORE_RENDERER__
#define __RENDERMOON_CORE_RENDERER__

class Ray;
class Spectrum;
class Scene;
struct Intersection;

class Renderer
{
public:
    Renderer() {}
    virtual void Render(const Scene *scene) = 0;
    virtual ~Renderer() {}
	virtual Spectrum Li(const Scene *scene, Ray&, Intersection &i) = 0;
};

#endif
