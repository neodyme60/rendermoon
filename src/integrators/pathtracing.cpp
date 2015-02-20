#include <rendermoon.h>

class Ray;
class Spectrum;
struct Intersection;

Spectrum PathTracing::Li(const Scene& scene, const Renderer& renderer, const Ray& ray, const Intersection &intersection)
{
    Spectrum L = Spectrum(0.0f);

    BSDF * bsdf = intersection.GetBSDF(ray);
    Vec3 wo = -ray.m_direction;
    Vec3 wi;
    float pdf;
    Point p;

    L += DirectLightingEstimate(scene, 0, intersection.m_DifferentialGeometry.m_Point, intersection.m_DifferentialGeometry.m_Normal, wo, ray.m_time, bsdf);

    L = Spectrum(0.0f);

    Intersection isec = intersection;
    Ray r = ray;

    for(int i=0; i < 2; i++ )
    {
        L = Spectrum(1.0f);

		r.maxt = INFINITY;
        if (!scene.GetIntersection(r, isec))
            return Spectrum(0.0f);

        bsdf = isec.GetBSDF(r);

        Spectrum s = bsdf->Sample_f(wo, wi, &pdf);

        r.m_direction = wi;
        r.m_origin = isec.m_DifferentialGeometry.m_Point;

        if (isec.m_Primitive->GetAreaLight()!=0)
        {
            L = L * isec.m_Primitive->GetAreaLight()->Le(r);
            return L;
        }

        L = L * bsdf->f(wo, wi) * s * (1.0  / pdf);

    }

    return L;
}
