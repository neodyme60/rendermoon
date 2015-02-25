#include <rendermoon.h>

Sampler::Sampler(SurfaceIntegrator * surfaceIntegrator, VolumeIntegrator* volumeIntegrator, int samples) : Renderer(), m_surfaceIntegrator(surfaceIntegrator), m_volumeIntegrator(volumeIntegrator), m_samples(samples)
{

}

Spectrum Sampler::Li(const Scene *scene, const Ray& ray, Intersection &i)
{
	Spectrum Li = Spectrum();

	if (scene->IsIntersected(ray))
	{
		if (scene->GetIntersection(ray, i))
		{
			Li = m_surfaceIntegrator->Li(*scene, *this, ray, i);
		}
		else
			//background
			Li = Spectrum(0.0f);
	}

    return 	Li;
}

void Sampler::Render(const Scene *scene)
{
    Camera* camera = scene->GetCamera();
    Film* film = camera->GetFilm();

    Ray ray;
    CameraSample cameraSample;

    for(int y=0; y< film->GetHeight(); y++)
    {
        for (int x = 0; x < film->GetWidth(); x++)
        {
            cameraSample.imageX = x;
            cameraSample.imageY = y;

			Spectrum Li;
			for(int s=0; s<m_samples; s++)
			{
				Intersection i;
				camera->GenerateRay(cameraSample, &ray);
				Li += this->Li(scene, ray, i);
			}
            printf("%d\n", int(100.0f*float(y * film->GetWidth()+x)/float(film->GetWidth()*film->GetHeight())) );
			Li/=m_samples;

			film->AddSample(cameraSample, Li);
        }
    }
};
