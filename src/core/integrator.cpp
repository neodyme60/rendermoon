#include <rendermoon.h>


Spectrum DirectLightingEstimateMIS(const Scene &scene, const Renderer &renderer, const Point &p, const Normal &n, const Vec3 &wo, float time, BSDF *bsdf, Light *light)
{
    Spectrum L(0.0f);
    float light_sample_pdf, brdf_sample_pdf;
    VisibilityTester visibility;
    Spectrum f(0.0f);
    Vec3 wi;

    //get light emit by sample direction on light, pdf
    Spectrum Li = light->Sample_L(p, 0.1f, 0.0, &wi, &light_sample_pdf, visibility);

    if (light_sample_pdf > 0.0f && !Li.IsBlack())
    {
        brdf_sample_pdf = bsdf->Pdf(wo, wi);

        float weight = PowerHeuristic(1, light_sample_pdf, 1, brdf_sample_pdf);

        //get brdf value
        f = bsdf->f(wo, wi);

        //shadow ray test
        if (!f.IsBlack() && visibility.Unoccluded(scene))
			L += f * Li * max(Dot(wi, n), 0.0f) * weight / light_sample_pdf;
    }

    //----------------------
	Li = Spectrum(0.0f);
    f = bsdf->Sample_f(wo, wi, &brdf_sample_pdf);
    if (!f.IsBlack() && brdf_sample_pdf > 0.0f)
    {
        light_sample_pdf = light->Pdf(p, wi);

        float weight = PowerHeuristic(1, brdf_sample_pdf, 1, light_sample_pdf);

        Intersection lightIsect;
        Ray ray(p, wi, 0.1, INFINITY, time);
        if (scene.GetIntersection(ray, lightIsect))
        {
            if (lightIsect.m_Primitive->GetAreaLight() == light)
                Li = lightIsect.Le(-wi);
        }
        else
            Li = light->Le(ray);

        if (!Li.IsBlack())
        {
            L += f * Li * max(Dot(wi, n), 0.0f) * weight / brdf_sample_pdf;
        }
    }
    return L;
}


Spectrum DirectLightingEstimateLightSampling(const Scene &scene, const Renderer &renderer, const Point &p, const Normal &n, const Vec3 &wo, float time, BSDF *bsdf, Light *light)
{
    Vec3 wi;
    Spectrum L(0.0f);
    float light_sample_pdf;
    VisibilityTester visibility;

    //get light emit by sample direction on light, pdf
    Spectrum Li = light->Sample_L(p, 0.1f, 0.0, &wi, &light_sample_pdf, visibility);

	const Ray r;
	if (light_sample_pdf > 0. && !Li.IsBlack())
	{
		//get brdf value
		Spectrum  f = bsdf->f(wo, wi);
		if (!f.IsBlack() && visibility.Unoccluded(scene))
		{
			L += f* Li * max(Dot(wi, n), 0.0f) / light_sample_pdf;
		}
	}
    return L;
}


Spectrum DirectLightingEstimateBrdfSampling(const Scene &scene, const Renderer &renderer, const Point &p, const Normal &n, const Vec3 &wo, float time, BSDF *bsdf, Light *light)
{
    Vec3 wi;
    Spectrum L(0.0f);
    Spectrum Li(0.0f);
    float brdf_sample_pdf;
    VisibilityTester visibility;

    Spectrum f = bsdf->Sample_f(wo, wi, &brdf_sample_pdf);

    if (!f.IsBlack())
    {
        Intersection lightIsect;
        Ray ray(p, wi, 0.1, INFINITY, time);
        if (scene.GetIntersection(ray, lightIsect))
        {
            if (lightIsect.m_Primitive->GetAreaLight() == light)
                Li = lightIsect.Le(-wi);
        }
        else
            Li = light->Le(ray);

		L = f * Li * max(Dot(wi, n), 0.0f) / brdf_sample_pdf;
    }
    return L;
}


Spectrum DirectLightingEstimateOnLight(const Scene &scene, const Renderer &renderer, const Point &p, const Normal &n, const Vec3 &wo, float time, BSDF *bsdf, Light *light, DirectLightingStrategy sls)
{
    if (sls == DIRECT_LIGHTING_BRDF_ONLY)
        return  DirectLightingEstimateBrdfSampling(scene, renderer, p, n, wo, time, bsdf, light);
    else if (sls == DIRECT_LIGHTING_LIGHT_ONLY)
        return  DirectLightingEstimateLightSampling(scene, renderer, p, n, wo, time, bsdf, light);
    else
        return  DirectLightingEstimateMIS(scene, renderer, p, n, wo, time, bsdf, light);
}

Spectrum DirectLightingEstimate(const Scene &scene, const Renderer &renderer, const Point &p, const Normal &n, const Vec3 &wo, float time, BSDF *bsdf, DirectLightingStrategy sls)
{
    Spectrum L(0.0f);

    vector<Light*>::const_iterator iterator;
    for (iterator = scene.m_lights.begin(); iterator != scene.m_lights.end(); ++iterator)
    {
        Spectrum Ld(0.0f);
        AreaLight *light = static_cast<AreaLight *>(*iterator);
        for (int j = 0; j < light->GetSamplesCount(); ++j)
        {
            Ld += DirectLightingEstimateOnLight(scene, renderer, p, n, wo, time, bsdf, light, sls);
        }
        L += Ld/light->GetSamplesCount();
    }
    return L;

}

