#include <rendermoon.h>

class Ray;
class Spectrum;
struct Intersection;

PathTracing::PathTracing(DirectLightingStrategy dls) : m_dls(dls)
{

}

PathTracing::~PathTracing()
{

}

Spectrum PathTracing::Li(const Scene& scene, const Renderer& renderer, const Ray& r, const Intersection &intersection)
{
    Spectrum L(1.0f);

	Ray ray(r.GetOrigin(), r.GetDirection(), 0.1f, INFINITY);
	Intersection isec;

    for(int i=0; i < 3; i++ )
    {
		if (!scene.GetIntersection(ray, isec))
			return Spectrum(0.0f);

		BSDF * bsdf = isec.GetBSDF(ray);

		const Point &p = isec.m_DifferentialGeometry.m_Point;
		const Normal &n = isec.m_DifferentialGeometry.m_Normal;

		Vec3 wo = -ray.m_direction;

		//get a new direction by sampling brdf
		Vec3 wi;
		float brdf_sample_pdf;
		Spectrum f = bsdf->Sample_f(wo, wi, &brdf_sample_pdf);

		//set next indirect bouncing ray
		ray = Ray(p, wi, 0.1f, INFINITY);

		//do we hit a light ?
		if (isec.m_Primitive->GetAreaLight())
		{
			L = L * isec.Le(wo);
			return L;
		}

		//direct lighting contribution
		Spectrum Ld = DirectLightingEstimate(scene, renderer, p, n, wo, 0.0, bsdf, m_dls);

		//indirect
		L = Ld;// +L * f  * AbsDot(n, wi) / brdf_sample_pdf;

        //!!!!
        delete bsdf;
    }

	//we hit no light
	return Spectrum(0.0f);
}
