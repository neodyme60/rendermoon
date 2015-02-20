#include <rendermoon.h>


Spectrum DirectLightingEstimate(const Scene& scene, const Renderer *renderer, const Point &p, const Normal &n, const Vec3 &wo, float time, BSDF *bsdf)
{
	Spectrum L(0.0f);

	std::list<Light*>::const_iterator iterator;
	for (iterator = scene.m_lights.begin(); iterator != scene.m_lights.end(); ++iterator)
	{
		AreaLight*	light = static_cast<AreaLight*>(*iterator);

		Normal		light_sample_normal;
		Point		light_sample_point;
		float		light_sample_pdf;

		float		brdf_sample_pdf;

		Vec3        wi;       //intersectionToLightSample;
		Spectrum    Li;
		Spectrum    f;

#if defined(SAMPLE_LIGHT_ONLY)
		//
		//sample light
		//

		//get light emit by sample direction on light, pdf
		Li = light->Sample_L(p, 0.1f, 0.0, &wi, &light_sample_pdf);

		//get brdf value
		f = bsdf->f(wo, wi);

		//shadow ray test
		Ray rt;
		rt.SetOrigin(p);
		rt.SetDirection(Normalize(light_sample_point - p));
		rt.mint = 0.01f;
		rt.maxt = (light_sample_point - p).Length();
		//		if (scene.ShadowRayTest(rt))
		//			continue;

		L += f * Li * (AbsDot(wi, n) / light_sample_pdf);
#elif defined(SAMPLE_BRDF_ONLY)

		//
		//sample brdf
		//
		f = bsdf->Sample_f(wo, wi, &brdf_sample_pdf);

		Intersection lightIsect;
		Ray ray(p, wi, 0.1, INFINITY, time);
		if (scene.GetIntersection(ray, lightIsect)) 
		{
			if (lightIsect.m_Primitive->GetAreaLight() == light)
				Li = lightIsect.Le(-wi);
		}
		else
			Li = light->Le(ray);

		L += f * Li * (AbsDot(wi, n) / brdf_sample_pdf);

#else
		//get light emit by sample direction on light, pdf
		Li = light->Sample_L(p, 0.1f, 0.0, &wi, &light_sample_pdf);
		
		if (light_sample_pdf > 0.0f && !Li.IsBlack())
		{
			brdf_sample_pdf = bsdf->Pdf(wo, wi);

			float weight = PowerHeuristic(1, light_sample_pdf, 1, brdf_sample_pdf);

			//get brdf value
			f = bsdf->f(wo, wi);

			//shadow ray test
/*			Ray rt(p, wi, )
			rt.SetOrigin(p);
			rt.SetDirection(Normalize(light_sample_point - p));
			rt.mint = 0.01f;
			rt.maxt = (light_sample_point - p).Length();
			if (scene.ShadowRayTest(rt))
			//			continue;
			*/
			L += f * Li * (AbsDot(wi, n) * weight / light_sample_pdf);
		}
		
		//----------------------		
		f = bsdf->Sample_f(wo, wi, &brdf_sample_pdf);
		if (!f.IsBlack() && brdf_sample_pdf > 0.0f)
		{

			light_sample_pdf = light->Pdf(p, wi);

			float weight = PowerHeuristic(1, brdf_sample_pdf, 1, light_sample_pdf);

			Spectrum Li(0.0f);
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
				L += f * Li * (AbsDot(wi, n) * weight / brdf_sample_pdf);
			}
		}
#endif
	}
	return L;

}