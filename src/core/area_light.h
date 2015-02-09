#ifndef __RENDERMOON_CORE_AREA_LIGHT__
#define __RENDERMOON_CORE_AREA_LIGHT__


#include "light.h"

class AreaLight : public Light
{
public:
	AreaLight(Transform& l2w) : Light(l2w) {}
    bool IsIntersected(const Ray&) const {}
    bool GetIntersection(const Ray &ray, Intersection&) const  {}

    void GetRandomSample(Normal& n, Point& p) const  {};
};

#endif
