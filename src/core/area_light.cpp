#include <rendermoon.h>

AreaLight::AreaLight(const Transform& l2w, const Reference<Shape> &shape) : Light(l2w), m_Shape(shape)
{

}

AreaLight::~AreaLight()
{

}
