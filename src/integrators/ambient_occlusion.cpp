#include <rendermoon.h>

class Ray;
class Spectrum;
struct Intersection;

AmbientOcclusion::AmbientOcclusion(int samples_count, float max_distance) : m_samples_count(samples_count), m_max_distance(max_distance)
{

}

Spectrum AmbientOcclusion::Li(const Scene& scene, const Renderer& renderer, const Ray& r, const Intersection &isect)
{
    Spectrum color = Spectrum(0.0f);
    BSDF *bsdf = isect.GetBSDF(r);

    int clear = 0;
    for(int s = 0; s < m_samples_count; s++)
    {
        Vec3 w = UniformSampleSphere(GetRandom(), GetRandom());
        if (Dot(w, isect.m_DifferentialGeometry.m_Normal) < 0.) w = -w;
        Ray r(isect.m_DifferentialGeometry.m_Point, w, 0.1f, m_max_distance);
		if (scene.IsIntersected(r))
			clear = clear;
		else
            ++clear;
    }

	delete bsdf;

	return Spectrum(float(clear) / float(m_samples_count));
}

