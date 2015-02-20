#include <rendermoon.h>

class Ray;

Scene::Scene(Primitive* accelerator, std::list<Light*> lights, Camera* camera)
{
    m_accelerator = accelerator;
    m_camera = camera;
	m_lights = lights;
}

Camera* Scene::GetCamera() const
{
    return m_camera;
}


bool Scene::IsIntersected(const Ray &r) const
{
	return m_accelerator->IsIntersected(r);
}

bool Scene::GetIntersection(const Ray &r, Intersection& i) const
{
    if (m_accelerator->IsIntersected(r))
        return m_accelerator->GetIntersection(r, i);
    return false;
}

bool Scene::ShadowRayTest(const Ray& r) const
{
	Intersection i;
	if (m_accelerator->GetIntersection(r, i))
		return true;
	else
		return false;
}

