#ifndef __RENDERMOON_SPHERE__
#define __RENDERMOON_SPHERE__

#include <core/shape.h>

struct Intersection;

class Sphere : public Shape
{
public:

    Sphere(Transform* o2w, Transform* w2o, float rad);

	BBox ObjectBound() const;

	bool GetIntersection(const Ray &ray, float *tHit, float *rayEpsilon, Intersection& i) const;
    bool IsIntersected(const Ray &ray) const;
    float Area() const;
//    Point Sample(float u1, float u2, Normal *ns) const;
 //   Point Sample(const Point &p, float u1, float u2, Normal *ns) const;
//    float Pdf(const Point &p, const Vector &wi) const;
	bool CanIntersect() const;
/*
	void GetRandomSample(Normal& n, Point& p) const;

	Point _UniformSampleHemisphere(float u1, float u2) const;



	bool IsEmiter() { return true;}

    Spectrum L(Intersection& i, Point& light_sample_point, Normal& light_sample_nornal)
	{
		Spectrum color;
		Vec3 incidence = (light_sample_point-i.p);

		float cos_a = std::max(Dot(Normalize(light_sample_nornal), Normalize(-incidence)), 0.0f);
		float cos_b = std::max(Dot(Normalize(i.n), Normalize(incidence)), 0.0f);
		float geom_factor = cos_a * cos_b /incidence.LengthSquared();
		return geom_factor;// * this->area() * this->m_material->m_color;
	}
*/
    // Sphere Private Data
    float	radius;
	Vec3	pos;
};

#endif
