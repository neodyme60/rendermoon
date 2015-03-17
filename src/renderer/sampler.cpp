#include <rendermoon.h>
//#include <thread>
#include <boost/thread.hpp>

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


using namespace boost;

void Sampler::Task(void *data)
{
	thread_data* td = static_cast<thread_data*>(data);

	Scene *scene = td->scene;
	int width = td->width;
	int ystart = td->ystart;
	int yend = td->yend;
	int  id=td->thread_id;
	
	Camera* camera = scene->GetCamera();
	Film* film = camera->GetFilm();

	Ray ray;
	CameraSample cameraSample;
	printf("start thread %d  s:%d e:%d \n", td->thread_id, td->ystart, td->yend);

	for (int y = ystart; y< yend; y++)
	{
		for (int x = 0; x < film->GetWidth(); x++)
		{
			cameraSample.imageX = x;
			cameraSample.imageY = y;

			Spectrum Li;
			for (int s = 0; s<m_samples; s++)
			{
				Intersection i;
				camera->GenerateRay(cameraSample, &ray);
				Li += this->Li(scene, ray, i);
			}
			Li /= m_samples;

			film->AddSample(cameraSample, Li);
		}
		printf("thread %d : %d\n", id, int(100.0f*float(y-ystart) / float(yend-ystart)));
	}
	printf("end thread %d\n", td->thread_id);
}



#define NUM_THREADS     1
thread t[NUM_THREADS];
thread_data td[NUM_THREADS];

void Sampler::Render(const Scene *scene)
{
    Camera* camera = scene->GetCamera();
    Film* film = camera->GetFilm();

    Ray ray;
    CameraSample cameraSample;
	/*
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
		*/

		for (int i = 0; i < NUM_THREADS; i++)
		{
			thread_data* tdd=&td[i];
			tdd->thread_id = i;
			tdd->scene = (Scene*)scene;
			tdd->width = film->GetWidth();
			tdd->ystart = i*float(film->GetHeight()) / float(NUM_THREADS);
			tdd->yend = (i + 1)*float(film->GetHeight()) / float(NUM_THREADS);
			t[i] = thread(&this->Task, this, tdd);
		}

		for (int i = 0; i < NUM_THREADS; i++)
		{
			t[i].join();
		}

    }

