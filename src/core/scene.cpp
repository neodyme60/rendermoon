#include <rendermoon.h>

class Ray;

Scene::Scene(Accelerator* accelerator, std::list<Light*> lights, Camera* camera)
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

bool Scene::GetIntersection(Ray &r, Intersection& i) const
{
    if (m_accelerator->IsIntersected(r))
        return m_accelerator->GetIntersection(r, i);
    return false;
}

bool Scene::ShadowRayTest(const Ray& r, Primitive* light, Primitive* geom) const
{
	Intersection i;
	i.t = r.maxt;
	if (m_accelerator->GetIntersection(r, i) && i.primitive!=light && i.primitive!=geom)
		return true;
	else
		return false;
}

