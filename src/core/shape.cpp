#include <rendermoon.h>

Shape::Shape(const Transform *o2w, const Transform *w2o) : m_ObjectToWorld(o2w), m_WorldToObject(w2o)
{
}

Shape::~Shape() 
{
}

void Shape::Refine(vector<Reference<Shape> > &refined) const
{
}

BBox Shape::WorldBound() const 
{
	return m_ObjectToWorld->TransformBBox(ObjectBound());
}

bool Shape::CanIntersect() const 
{
    return true;
}

bool Shape::GetIntersection(const Ray &ray, float *tHit, DifferentialGeometry&) const
{
    return false;
}

bool Shape::IsIntersected(const Ray &ray) const 
{
    return false;
}

float Shape::Area() const 
{
    return 0.0f;
}

float Shape::Pdf(const Point &Pshape) const
{
    return 1.0f / Area();
}

Point Shape::SampleUniform(float u1, float u2, Normal *Ns) const
{
    return Point();
}

Point Shape::SampleBySolidAngle(const Point &P, float u1, float u2, Normal *Ns) const
{
    return SampleUniform(u1, u2, Ns);
}

float Shape::Pdf(const Point &p, const Vec3 &wi) const
{
    // Intersect sample ray with area light geometry
    DifferentialGeometry dgLight;
    Ray ray(p, wi, 1e-3f);
    float thit, rayEpsilon;
    if (!GetIntersection(ray, &thit, dgLight))
        return 0.0f;

    // Convert light sample weight to solid angle measure
    float pdf = DistanceSquared(p, ray.GetAt(thit)) / (AbsDot(dgLight.m_Normal, -wi) * Area());
    if (isinf(pdf))
        pdf = 0.0f;
    return pdf;
}