#ifndef __RENDERMOON_CORE_SCENE__
#define __RENDERMOON_CORE_SCENE__

#include "renderer.h"

class Accelerator;
class Camera;
class Light;
struct Intersection;
class Primitive;

class Scene
{
public:
    Accelerator*			m_accelerator;
    Camera*					m_camera;
    std::list<Light*>       m_lights;

	Scene(Accelerator*, std::list<Light*>, Camera*);
    virtual ~Scene(){}

    Camera* GetCamera() const;

	bool ShadowRayTest(const Ray&, Primitive* light, Primitive* geom) const;

    bool IsIntersected(const Ray &r) const;
	bool GetIntersection(Ray &r, Intersection&) const;
};

#endif
