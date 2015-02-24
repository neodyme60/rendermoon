#include <rendermoon.h>

class GeometricPrimitive;
struct Intersection;


BBox DummyAccelerator::WorldBound() const
{
    return m_worldBound;
}

DummyAccelerator::DummyAccelerator(vector<Reference<Primitive>>& data)
{
    m_data = data;

    vector<Reference<Primitive>>::const_iterator iterator;
    for (iterator = m_data.begin(); iterator != m_data.end(); ++iterator)
    {
        m_worldBound = Union(m_worldBound, (*iterator)->WorldBound());
    }
}

BSDF* DummyAccelerator::GetBSDF(const DifferentialGeometry &dg, const Transform &) const
{
    return NULL;
}

const AreaLight* DummyAccelerator::GetAreaLight() const
{
    return NULL;
}

bool DummyAccelerator::GetIntersection(const Ray &r, Intersection& i) const
{
    bool has_intersection = false;
	Intersection intersection_tmp;
	float max_intersection_distance = r.maxt;

    vector<Reference<Primitive>>::const_iterator iterator;
    for (iterator = m_data.begin(); iterator != m_data.end(); ++iterator)
	{
        Reference<Primitive>  p = *iterator;
		if (p->GetIntersection(r, intersection_tmp))
		{
            if (r.maxt < max_intersection_distance)
			{
                i.m_DifferentialGeometry.m_Point = intersection_tmp.m_DifferentialGeometry.m_Point;
                i.m_DifferentialGeometry.m_Normal = intersection_tmp.m_DifferentialGeometry.m_Normal;
				i.m_Primitive = intersection_tmp.m_Primitive;
				max_intersection_distance = r.maxt;
                has_intersection = true;
			}				
		}
	}
    return has_intersection;
}

bool DummyAccelerator::IsIntersected(const Ray &r) const
{
    vector<Reference<Primitive>>::const_iterator iterator;
	for (iterator = m_data.begin(); iterator != m_data.end(); ++iterator)
	{
        Reference<Primitive>  p = *iterator;
		if (p->IsIntersected(r))
			return true;
	}

	return false;
}

