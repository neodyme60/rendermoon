#include <rendermoon.h>

DiffuseLight::DiffuseLight(Transform& l2w, Spectrum & intensity) : Light(l2w) 
{
}

Spectrum DiffuseLight::L(Intersection& i, Point& light_sample_point, Normal& light_sample_nornal)
{
	Spectrum color;
	Vec3 incidence = (light_sample_point-i.p);

	float cos_a = std::max(Dot(Normalize(light_sample_nornal), Normalize(incidence)), 0.0f);
	float cos_b = std::max(Dot(Normalize(i.n), Normalize(-incidence)), 0.0f);
	return cos_a * cos_b * i.primitive->area()/incidence.LengthSquared();
}

