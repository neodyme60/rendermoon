#ifndef __RENDERMOON_DIRECTIONAL_LIGHT__
#define __RENDERMOON_DIRECTIONAL_LIGHT__

#include <core/light.h>

class DirectionalLight : public Light
{
public:
	Vec3 m_direction;;

	DirectionalLight(Transform& l2w, Spectrum & intensity);
    DirectionalLight(const Vec3 direction);
    virtual ~DirectionalLight() {}

	bool GetIntersection(const Ray &r, Intersection&) const  { return false; }
	bool IsIntersected(const Ray &r) const { return false; } 

	void GetRandomSample(Normal& n, Point& p) const {}

    Spectrum L(Intersection& i, Point& light_sample_point, Normal& light_sample_nornal);
};

#endif
