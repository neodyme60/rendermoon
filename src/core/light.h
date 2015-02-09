#ifndef __RENDERMOON_CORE_LIGHT__
#define __RENDERMOON_CORE_LIGHT__

#include <core/transform.h>
class Spectrum;
struct Intersection;
class Ray;

class Light
{

public:
	Light(Transform& t) { m_lightToWorld = t; m_worldToLight = m_lightToWorld.GetInverse(); }
    virtual ~Light() {}

    virtual bool GetIntersection(const Ray &ray, Intersection&) const =0;
    virtual bool IsIntersected(const Ray &ray) const  =0;
	virtual  void GetRandomSample(Normal& n, Point& p) const  =0;

	Transform m_lightToWorld, m_worldToLight;
};
#endif
