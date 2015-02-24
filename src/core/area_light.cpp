#include <rendermoon.h>

AreaLight::AreaLight(const Transform& l2w, const Reference<Shape> &shape, int samples_count) : Light(l2w, samples_count), m_Shape(shape)
{

}

AreaLight::~AreaLight()
{

}
