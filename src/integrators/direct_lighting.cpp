#include <rendermoon.h>

class Ray;
class Spectrum;
struct Intersection;

Spectrum DirectLighting::Li(const Scene& scene, const Renderer& renderer, const Ray& ray, const Intersection &intersection)
{
	Spectrum L = Spectrum(0.0f);

    BSDF * bsdf = intersection.GetBSDF(ray);
    Vec3 wo = -ray.m_direction;

    L += intersection.Le(wo);

    const Point &p = intersection.m_DifferentialGeometry.m_Point;
    const Normal &n = intersection.m_DifferentialGeometry.m_Normal;

	L += DirectLightingEstimate(scene, 0, intersection.m_DifferentialGeometry.m_Point, intersection.m_DifferentialGeometry.m_Normal, wo, ray.m_time, bsdf);

    return L;
}
