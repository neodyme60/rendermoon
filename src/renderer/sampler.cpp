#include <rendermoon.h>

Sampler::Sampler(SurfaceIntegrator * surfaceIntegrator, VolumeIntegrator* volumeIntegrator, int samples) : Renderer(), m_surfaceIntegrator(surfaceIntegrator), m_volumeIntegrator(volumeIntegrator), m_samples(samples)
{

}

Spectrum Sampler::Li(const Scene *scene, Ray& r, Intersection &i)
{
	Spectrum Li = Spectrum();

	if (scene->IsIntersected(r))
	{
		if (scene->GetIntersection(r, i))
		{
			Li = m_surfaceIntegrator->Li(*scene, r, i); 
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
				i.t = 10e5f;

				camera->GenerateRay(cameraSample, &ray);
				Li += this->Li(scene, ray, i);
			}
			Li/=m_samples;

			film->AddSample(cameraSample, Li);
        }
    }
};
