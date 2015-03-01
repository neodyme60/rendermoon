#include <rendermoon.h>

Sphere::Sphere(Transform* o2w, Transform* w2o, bool ro, float radius) : Shape(o2w, w2o, ro)
{
	m_radius = radius;
}

float Sphere::Area() const
{
	return 4.0f*M_PI*m_radius*m_radius;
}

bool Sphere::CanIntersect() const
{
	return true;
}

Point Sphere::SamplingUniformlyByRespectToArea(float u1, float u2, Normal *n) const
{
    Point p = Point(0,0,0) + m_radius * UniformSampleSphere(u1, u2);
    *n = Normalize(m_ObjectToWorld->TransformNormal(Normal(p.x, p.y, p.z)));
    if (m_ReverseOrientation)
        *n *= -1.f;
    return m_ObjectToWorld->TransformPoint(p);
}

Point Sphere::SamplingByRespectToSolidAngle(const Point &p, float u1, float u2, Normal *n) const
{
    // Compute coordinate system for sphere sampling
    Point Pcenter = m_ObjectToWorld->TransformPoint(Point(0,0,0));
    Vec3 wc = Normalize(Pcenter - p);
    Vec3 wcX, wcY;
    CoordinateSystem(wc, &wcX, &wcY);

    // Sample sphere uniformly inside subtended cone
    float sinThetaMax2 = m_radius*m_radius / DistanceSquared(p, Pcenter);
    float cosThetaMax = sqrtf(max(0.0f, 1.0f - sinThetaMax2));
    DifferentialGeometry dgSphere;
    float thit;
    Point ps;
    Ray r(p, UniformSampleCone(u1, u2, cosThetaMax, wcX, wcY, wc), 1e-3f);
    if (!GetIntersection(r, &thit, dgSphere))
        thit = Dot(Pcenter - p, Normalize(r.m_direction));
    ps = r.GetAt(thit);
    *n = Normal(Normalize(ps - Pcenter));
    if (m_ReverseOrientation)
        *n *= -1.f;
    return ps;
}

BBox Sphere::ObjectBound() const
{
    return BBox(Point(-m_radius, -m_radius, -m_radius), Point(m_radius, m_radius, m_radius));
}


bool Sphere::GetIntersection(const Ray &ray, float *tHit, DifferentialGeometry& dg) const
{
    Point phit;

	// Transform _Ray_ to object space
    Ray r;
	m_WorldToObject->TransformRay(ray, &r);

    // Compute quadratic sphere coefficients
    float A = Dot(r.m_direction, r.m_direction);
    float B = 2.0f * Dot(r.m_direction, Vec3(r.m_origin));
	float C = Dot(Vec3(r.m_origin), Vec3(r.m_origin)) - m_radius*m_radius;

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

    *tHit = thit;
    dg.m_Point = m_ObjectToWorld->TransformPoint(r.GetAt(thit));
    dg.m_Normal = Normalize(Normal(dg.m_Point - m_ObjectToWorld->TransformPoint(Point(0.0f, 0.0f, 0.0f))));
    return true;
}

bool Sphere::IsIntersected(const Ray &ray) const 
{
    Point phit;

    // Transform _Ray_ to object space
    Ray r;
	m_WorldToObject->TransformRay(ray, &r);

    // Compute quadratic sphere coefficients
    float A = Dot(r.m_direction, r.m_direction);
    float B = 2.0f * Dot(r.m_direction, Vec3(r.m_origin));
	float C = Dot(Vec3(r.m_origin), Vec3(r.m_origin)) - m_radius*m_radius;

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

float Sphere::Pdf(const Point &p, const Vec3 &wi) const
{
    Point Pcenter = m_ObjectToWorld->TransformPoint(Point(0,0,0));
    // Return uniform weight if point inside sphere
//    if (DistanceSquared(p, Pcenter) - m_radius*m_radius < 1e-4f)
//        return Shape::Pdf(p, wi);

    // Compute general sphere weight
    float cosThetaMax = sqrtf(max(0.0f, 1.0f - (m_radius*m_radius / DistanceSquared(p, Pcenter))));
    return UniformConePdf(cosThetaMax);
}