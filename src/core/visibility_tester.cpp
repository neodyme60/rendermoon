#include <rendermoon.h>


void VisibilityTester::SetSegment(const Point &p1, float eps1, const Point &p2, float eps2, float time)
{
    float dist = Distance(p1, p2);
    r = Ray(p1, (p2-p1) / dist, eps1, dist * (1.f - eps2), time);
//    Assert(!r.HasNaNs());
}

void VisibilityTester::SetRay(const Point &p, float eps, const Vec3 &w, float time)
{
    r = Ray(p, w, eps, INFINITY, time);
//    Assert(!r.HasNaNs());
}

bool VisibilityTester::Unoccluded(const Scene &scene) const
{
    return !scene.IsIntersected(r);
}


