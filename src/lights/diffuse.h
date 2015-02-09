#ifndef __RENDERMOON_DIFFUSE_LIGHT__
#define __RENDERMOON_DIFFUSE_LIGHT__

#include <core/light.h>

class DiffuseLight : public Light
{
public:

    DiffuseLight(Transform& l2w, Spectrum & intensity);
    virtual ~DiffuseLight() {}

	bool GetIntersection(const Ray &r, Intersection&)   { return false; }
	bool IsIntersected(const Ray &r) { return false; } 

	void GetRandomSample(Normal& n, Point& p) const {}

    Spectrum L(Intersection& i, Point& light_sample_point, Normal& light_sample_nornal);
};

#endif
