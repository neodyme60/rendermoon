#include <rendermoon.h>

class GeometricPrimitive;
struct Intersection;

bool DummyAccelerator::GetIntersection(const Ray &r, Intersection& i) const
{
    bool has_intersection = false;
	Intersection intersection_tmp;

	list<::Primitive *>::const_iterator iterator;
    for (iterator = m_data.begin(); iterator != m_data.end(); ++iterator)
	{
        Primitive * p = *iterator;
		if (p->GetIntersection(r, intersection_tmp))
		{
            if (intersection_tmp.t < i.t)
			{
                i.p = intersection_tmp.p;
                i.n = intersection_tmp.n;
				i.t = intersection_tmp.t;
				i.primitive = p;
                has_intersection = true;
			}				
		}
	}
    return has_intersection;
}

bool DummyAccelerator::IsIntersected(const Ray &r) const
{
	return true;
}

