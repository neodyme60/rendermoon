#include <rendermoon.h>

Shape::Shape(Transform *o2w, Transform *w2o) : m_objectToWorld(o2w), m_worldToObject(w2o)
{
}

Shape::~Shape() 
{
}

BBox Shape::WorldBound() const 
{
	return m_objectToWorld->TransformBBox(ObjectBound());
}

bool Shape::CanIntersect() const 
{
    return true;
}

bool Shape::GetIntersection(const Ray &ray, float *tHit, float *rayEpsilon, Intersection&) const 
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
