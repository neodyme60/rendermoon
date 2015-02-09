#ifndef __RENDERMOON_CORE_INTERSECTION__
#define __RENDERMOON_CORE_INTERSECTION__

class GeometricPrimitive;

struct Intersection
{
    Point p;
    Normal n;
	float t;
	Primitive* primitive;
};

#endif
