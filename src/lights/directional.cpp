#include <rendermoon.h>

DirectionalLight::DirectionalLight(Transform& l2w, Spectrum & intensity) : Light(l2w) 
{
}

Spectrum DirectionalLight::L(Intersection& i, Point& light_sample_point, Normal& light_sample_nornal)
{
	Spectrum s;

//		float angle = Clamp(Dot(Normalize(m_direction), Normalize(light_sample_nornal)), 0.0, 1.0);
//		s = Spectrum( angle * m_material->m_color);
	return s;
}

