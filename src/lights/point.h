#ifndef __RENDERMOON_POINT_LIGHT__
#define __RENDERMOON_POINT_LIGHT__

#include <core/light.h>

class PointLight : public Light
{
public:

    PointLight(Transform& l2w, Spectrum & intensity);
    virtual ~PointLight() {}

	Spectrum L(Intersection& i, Point& light_point, Normal& light_nornal)
	{
		return Spectrum();
	}

	bool GetIntersection(const Ray &r, Intersection&)   { return false; }
	bool IsIntersected(const Ray &r) { return false; } 

	void GetRandomSample(Normal& n, Point& p) const {}

};

#endif
