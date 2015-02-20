#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_SCENE__
#define __RENDERMOON_CORE_SCENE__

#include "renderer.h"
#include "geometric_primitive.h"

class Camera;
class Light;
struct Intersection;
class Primitive;

class Scene
{
public:
    Primitive*				        m_accelerator;
    Camera*					        m_camera;
    std::list<Light*>               m_lights;

	Scene(Primitive*, std::list<Light*>, Camera*);
    virtual ~Scene(){}


    Camera* GetCamera() const;

	bool ShadowRayTest(const Ray&) const;

    bool IsIntersected(const Ray &r) const;
	bool GetIntersection(const Ray &r, Intersection&) const;
};

#endif
