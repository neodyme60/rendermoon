#include <rendermoon.h>

BSDF *Aggregate::GetBSDF(const DifferentialGeometry& dg, const Transform &ObjectToWorld) const
{
	return NULL;
}

const AreaLight *Aggregate::GetAreaLight() const
{
//    Severe("Aggregate::GetAreaLight() method called; should have gone to GeometricPrimitive");
    return NULL;
}
