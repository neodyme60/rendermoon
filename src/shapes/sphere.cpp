#include <rendermoon.h>

Sphere::Sphere(Transform* o2w, Transform* w2o, float rad) : Shape(o2w, w2o) 
{
    radius = rad;
}

float Sphere::Area() const
{
    return 4.0f*M_PI*radius*radius;
}

bool Sphere::CanIntersect() const
{
	return true;
}

BBox Sphere::ObjectBound() const
{
	return BBox();
}
/*
void Sphere::GetRandomSample(Normal& n, Point& p) const
{
	float u1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float u2 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		
	p = m_objectToWorld.TransformPoint(_UniformSampleHemisphere(u1, u2));
	n = Normalize(m_objectToWorld.TransformNormal(Normal(p-m_objectToWorld.TransformPoint(Point(0.0f, 0.0f, 0.0f)))));
}

Point Sphere::_UniformSampleHemisphere(float u1, float u2) const
{
	float z = u1;
	float r = sqrtf(std::max(0.f, 1.f - z*z));
	float phi = 2 * M_PI * u2;
	float x = r * cosf(phi);
	float y = r * sinf(phi);
	return Point(x, y, z);
}
*/
bool Sphere::GetIntersection(const Ray &ray, float *tHit, float *rayEpsilon, Intersection& i) const 
{
    Point phit;

	// Transform _Ray_ to object space
    Ray r;
	m_worldToObject->TransformRay(ray, &r);

    // Compute quadratic sphere coefficients
    float A = Dot(r.m_direction, r.m_direction);
    float B = 2.0f * Dot(r.m_direction, Vec3(r.m_origin));
    float C = Dot(Vec3(r.m_origin), Vec3(r.m_origin)) - radius*radius;

    // Solve quadratic equation for _t_ values
    float t0, t1;
    if (!Quadratic(A, B, C, &t0, &t1))
        return false;

    // Compute intersection distance along ray
    if (t0 > r.maxt || t1 < r.mint)
        return false;
    float thit = t0;
    if (t0 < r.mint) 
	{
        thit = t1;
        if (thit > r.maxt) return false;
    }

    // Update _tHit_ for quadric intersection
    i.t = thit;
	i.p = m_objectToWorld->TransformPoint(r.GetAt(thit));
	i.n = Normalize(Normal(i.p-m_objectToWorld->TransformPoint(Point(0.0f, 0.0f, 0.0f))));
    return true;
}

bool Sphere::IsIntersected(const Ray &ray) const 
{
    Point phit;

    // Transform _Ray_ to object space
    Ray r;
	m_worldToObject->TransformRay(ray, &r);

    // Compute quadratic sphere coefficients
    float A = Dot(r.m_direction, r.m_direction);
    float B = 2.0f * Dot(r.m_direction, Vec3(r.m_origin));
    float C = Dot(Vec3(r.m_origin), Vec3(r.m_origin)) - radius*radius;

    // Solve quadratic equation for _t_ values
    float t0, t1;
    if (!Quadratic(A, B, C, &t0, &t1))
        return false;

    // Compute intersection distance along ray
    if (t0 > r.maxt || t1 < r.mint)
        return false;
    float thit = t0;
    if (t0 < r.mint) 
	{
        thit = t1;
        if (thit > r.maxt) return false;
    }

    return true;
}
