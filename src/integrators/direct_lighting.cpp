#include <rendermoon.h>

class Ray;
class Spectrum;
struct Intersection;

Spectrum DirectLighting::Li(const Scene& scene, Ray& r, Intersection &i)
{
	Spectrum color = Spectrum(0.0f);

	if (i.primitive->isemiter)
		return Spectrum(i.primitive->m_material->m_color);

	std::list<Light*>::const_iterator iterator;
	for (iterator = scene.m_lights.begin(); iterator != scene.m_lights.end(); ++iterator)
	{
		//get random point/normal on light
		Normal		light_sample_normal;
		Point		light_sample_point;
        Light*	    light = *iterator;

		//get random point on light
		light->GetRandomSample(light_sample_normal, light_sample_point);

		//shadow ray test
/*
		Ray rt;
		rt.SetOrigin(i.p);
		rt.SetDirection(Normalize(light_sample_point-i.p));
		rt.mint = 0.01f;
		rt.maxt = (light_sample_point-i.p).Length();
		if (scene.ShadowRayTest(rt, light, i.primitive))
			continue;
*/
		//light contribution
		Vec3 brdf = i.primitive->m_material->m_color * INV_PI;
		Spectrum l = light->L(i, light_sample_point, light_sample_normal);
		color+=Spectrum(brdf) * l;
	}

    return color;
}
