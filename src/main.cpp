#include <iostream>
#include <rendermoon.h>

//#include <vld.h>
/*
void tp1_4()
{
	//primitives list
    std::list<Primitive*> primitives;

	//lights list
    std::list<Primitive*> lights;

	//
	//shape 1
	//
	Transform t1a= Transform::CreateTranslate(80.0f, -10e5f, 0.0f);
	Transform t1b= t1a.GetInverse();
	Primitive *g1 = new Sphere(t1a, t1b, 10e5f);
	g1->m_material = new DiffuseMaterial(Vec3(0.75f, 0.75f, 0.75f));

	//
	//shape 2
	//
	Transform t2a= Transform::CreateTranslate(50.0, 40.0, 0.0);
	Transform t2b= t2a.GetInverse();
	Primitive *g2 = new Sphere(t2a, t2b, 40.0f);
	g2->m_material = new DiffuseMaterial(Vec3(0.3f, 0.5f, 0.75f));


	//
	//lights
	//
	Transform l1a= Transform();
	Transform l1b= t1a.GetInverse();
	Primitive *l1 = new DirectionalLight(Vec3(-10.0f, 4.0f, 10.0f));
	l1->m_material = new DiffuseMaterial(Vec3(M_PI, M_PI, M_PI));
	lights.push_back(l1);

	//Accelerator
	primitives.push_back(g1);
	primitives.push_back(g2);
    DummyAccelerator *accelerator = new DummyAccelerator(primitives);

    //create film
    Film * film = new Image(256, 256, "task01.tga");
	
    //create camera
	Transform cam2world = Transform::CreateLookAt(Point(50.0f, 52.0f, 296.0f), Point(50.0f, 52.0f-0.043f, 296.0f-1.0f), Vec3(0.0, 1.0, 0.0)).GetInverse();

    float aspectratio =float(film->GetWidth())/float(film->GetHeight());
    float screenWindow[4];
    if (aspectratio > 1.f)
    {
        screenWindow[0] = -aspectratio;
        screenWindow[1] =  aspectratio;
        screenWindow[2] = -1.f;
        screenWindow[3] =  1.f;
    }
    else
    {
        screenWindow[0] = -1.f;
        screenWindow[1] =  1.f;
        screenWindow[2] = -1.f / aspectratio;
        screenWindow[3] =  1.f / aspectratio;
    }
    float fov = 29.5*2;
    PerspectiveCamera *camera = new PerspectiveCamera(cam2world, screenWindow, fov, film);

    //integrator
    VolumeIntegrator* volume_integrator = nullPtr;
	SurfaceIntegrator* surface_integrator =  new DirectLighting();

    //renderer
    Renderer * renderer = new Sampler(surface_integrator, volume_integrator, 1);

    //scene
    Scene* scene = new Scene(accelerator, lights, camera);

    renderer->Render(scene);

	film->WriteImage();
}


void tp1_5_good()
{
	//primitives list
    std::list<Primitive*> primitives;

	//lights list
    std::list<Primitive*> lights;

	//
	//shape 1
	//
	Transform t1a= Transform::CreateTranslate(0.0f, -10e5f, 0.0f);
	Transform t1b= t1a.GetInverse();
	Primitive *g1 = new Sphere(t1a, t1b, 10e5f);
	g1->m_material = new DiffuseMaterial(Vec3(0.75f, 0.75f, 0.75f));

	//
	//shape 2
	//
	Transform t2a= Transform::CreateTranslate(0.0, 4.0, 0.0);
	Transform t2b= t2a.GetInverse();
	Primitive *g2 = new Sphere(t2a, t2b, 4.0f);
	g2->m_material = new DiffuseMaterial(Vec3(0.3f, 0.5f, 0.75f));


	//
	//lights
	//
	Transform t3a= Transform::CreateTranslate(0.0, 10.0, 0.0);
	Transform t3b= t3a.GetInverse();
	Primitive *l1 = new Sphere(t3a, t3b, 1.0f);
	l1->m_material = new DiffuseMaterial(Vec3(1.0, 1.0, 1.0));
	lights.push_back(l1);

	//Accelerator
	primitives.push_back(g1);
	primitives.push_back(g2);
    DummyAccelerator *accelerator = new DummyAccelerator(primitives);

    //create film
    Film * film = new Image(256, 256, "task01.tga");
	
    //create camera
	Transform cam2world = Transform::CreateLookAt(Point(0.0f, 5.0f, 25.0f), Point(0.0f, 0.0f, 0.0f), Vec3(0.0, 1.0, 0.0)).GetInverse();

    float aspectratio =float(film->GetWidth())/float(film->GetHeight());
    float screenWindow[4];
    if (aspectratio > 1.f)
    {
        screenWindow[0] = -aspectratio;
        screenWindow[1] =  aspectratio;
        screenWindow[2] = -1.f;
        screenWindow[3] =  1.f;
    }
    else
    {
        screenWindow[0] = -1.f;
        screenWindow[1] =  1.f;
        screenWindow[2] = -1.f / aspectratio;
        screenWindow[3] =  1.f / aspectratio;
    }
    float fov = 29.5*2;
    PerspectiveCamera *camera = new PerspectiveCamera(cam2world, screenWindow, fov, film);

    //integrator
    VolumeIntegrator* volume_integrator = nullPtr;
	SurfaceIntegrator* surface_integrator =  new DirectLighting();

    //renderer
    Renderer * renderer = new Sampler(surface_integrator, volume_integrator,1);

    //scene
    Scene* scene = new Scene(accelerator, lights, camera);

    renderer->Render(scene);

	film->WriteImage();
}


void tp1_55()
{
	//primitives list
    std::list<Primitive*> primitives;

	//lights list
    std::list<Primitive*> lights;

	//
	//shape 1
	//
	Transform t1a= Transform::CreateTranslate(0.0f, -10e5f, 0.0f);
	Transform t1b= t1a.GetInverse();
	Primitive *g1 = new Sphere(t1a, t1b, 10e5f);
	g1->m_material = new DiffuseMaterial(Vec3(0.75f, 0.75f, 0.75f));

	//
	//shape 2
	//
	Transform t2a= Transform::CreateTranslate(0.0, 4.0, 0.0);
	Transform t2b= t2a.GetInverse();
	Primitive *g2 = new Sphere(t2a, t2b, 4.0f);
	g2->m_material = new DiffuseMaterial(Vec3(0.3f, 0.5f, 0.75f));


	//
	//lights
	//
	Transform t3a= Transform::CreateTranslate(0.0, 10.0, 0.0);
	Transform t3b= t3a.GetInverse();
	Primitive *l1 = new Sphere(t3a, t3b, 1.0f);
	l1->m_material = new DiffuseMaterial(Vec3(13.0, 13.0, 13.0));
	lights.push_back(l1);

	//Accelerator
	primitives.push_back(g1);
	primitives.push_back(g2);
    DummyAccelerator *accelerator = new DummyAccelerator(primitives);

    //create film
    Film * film = new Image(256, 256, "task01.tga");
	
    //create camera
	Transform cam2world = Transform::CreateLookAt(Point(0.0f, 5.0f, 25.0f), Point(0.0f, 0.0f, 0.0f), Vec3(0.0, 1.0, 0.0)).GetInverse();

    float aspectratio =float(film->GetWidth())/float(film->GetHeight());
    float screenWindow[4];
    if (aspectratio > 1.f)
    {
        screenWindow[0] = -aspectratio;
        screenWindow[1] =  aspectratio;
        screenWindow[2] = -1.f;
        screenWindow[3] =  1.f;
    }
    else
    {
        screenWindow[0] = -1.f;
        screenWindow[1] =  1.f;
        screenWindow[2] = -1.f / aspectratio;
        screenWindow[3] =  1.f / aspectratio;
    }
    float fov = 29.5*2;
    PerspectiveCamera *camera = new PerspectiveCamera(cam2world, screenWindow, fov, film);

    //integrator
    VolumeIntegrator* volume_integrator = nullPtr;
	SurfaceIntegrator* surface_integrator =  new DirectLighting();

    //renderer
    Renderer * renderer = new Sampler(surface_integrator, volume_integrator,1);

    //scene
    Scene* scene = new Scene(accelerator, lights, camera);

    renderer->Render(scene);

	film->WriteImage();
}

void task03()
{
	    //primitives list
    std::list<Primitive*> primitives;

	//light list
    std::list<Primitive*> lights;

	//material
	Material * mat= new DiffuseMaterial(Vec3(1.0f,1.0f,1.0f));

	//
	//shape 1
	//
	Transform t1a= Transform::CreateTranslate(0, -0, 0.0);
	Transform t1b= t1a.GetInverse();
	Primitive *g1 = new Sphere(t1a, t1b, 1);

	//Accelerator
	primitives.push_back(g1);

    DummyAccelerator *accelerator = new DummyAccelerator(primitives);

    //create film
    Film * film = new Image(256, 256, "task01.tga");
	
    //create camera
	Transform cam2world = Transform::CreateLookAt(Point(0.0, 0.0, -6.0), Point(0.0, -0, 0.0), Vec3(0.0, 1.0, 0.0)).GetInverse();

    float aspectratio =float(film->GetWidth())/float(film->GetHeight());
    float screenWindow[4];
    if (aspectratio > 1.f)
    {
        screenWindow[0] = -aspectratio;
        screenWindow[1] =  aspectratio;
        screenWindow[2] = -1.f;
        screenWindow[3] =  1.f;
    }
    else
    {
        screenWindow[0] = -1.f;
        screenWindow[1] =  1.f;
        screenWindow[2] = -1.f / aspectratio;
        screenWindow[3] =  1.f / aspectratio;
    }
    float fov = 29.5*2;
    PerspectiveCamera *camera = new PerspectiveCamera(cam2world, screenWindow, fov, film);
//     OrthographicCamera *camera = new OrthographicCamera(cam2world, screenWindow, film);

    //integrator
    VolumeIntegrator* volume_integrator = nullPtr;
    SurfaceIntegrator* surface_integrator = new DirectLighting();

    //renderer
    Renderer * renderer = new Sampler(surface_integrator, volume_integrator,1);

    //scene
    Scene* scene = new Scene(accelerator, lights, camera);

    renderer->Render(scene);

	film->WriteImage();
}

void task01()
{
	    //primitives list
    std::list<Primitive*> primitives;

	//material
	Material * mat= new DiffuseMaterial(Vec3(1.0f,1.0f,1.0f));

	//
	//shape 1
	//
	Transform t1a= Transform::CreateTranslate(2, -0, 0.0);
	Transform t1b= t1a.GetInverse();
	Primitive *g1 = new Sphere(t1a, t1b, 1);

	//
	//shape 2
	//
	Transform t2a= Transform::CreateTranslate(-2.0, 0.0, 0.0);
	Transform t2b= t2a.GetInverse();
	Primitive *g2 = new Sphere(t2a, t2b, 1.0);

	//
	//shape 3
	//
	Transform t3a= Transform::CreateTranslate(0.0, -1e5f, 0.0);
	Transform t3b= t3a.GetInverse();
	Primitive *g3 = new Sphere(t3a, t3b, 1e5f);

	//Accelerator
	primitives.push_back(g1);
	primitives.push_back(g2);
	primitives.push_back(g3);
    DummyAccelerator *accelerator = new DummyAccelerator(primitives);

    //create film
    Film * film = new Image(256, 256, "task01.tga");
	
    //create camera
	Transform cam2world = Transform::CreateLookAt(Point(0.0, 2.0, -16.0), Point(0.0, -0, 0.0), Vec3(0.0, 1.0, 0.0)).GetInverse();

    float aspectratio =float(film->GetWidth())/float(film->GetHeight());
    float screenWindow[4];
    if (aspectratio > 1.f)
    {
        screenWindow[0] = -aspectratio;
        screenWindow[1] =  aspectratio;
        screenWindow[2] = -1.f;
        screenWindow[3] =  1.f;
    }
    else
    {
        screenWindow[0] = -1.f;
        screenWindow[1] =  1.f;
        screenWindow[2] = -1.f / aspectratio;
        screenWindow[3] =  1.f / aspectratio;
    }
    float fov = 29.5*2;
    PerspectiveCamera *camera = new PerspectiveCamera(cam2world, screenWindow, fov, film);
//     OrthographicCamera *camera = new OrthographicCamera(cam2world, screenWindow, film);

    //integrator
    VolumeIntegrator* volume_integrator = nullPtr;
    SurfaceIntegrator* surface_integrator = new DirectLighting();

    //renderer
    Renderer * renderer = new Sampler(surface_integrator, volume_integrator,1);

	//lights
	std::list<Primitive*> lights;

    //scene
    Scene* scene = new Scene(accelerator, lights, camera);

    renderer->Render(scene);

	film->WriteImage();
}

void task02()
{
	    //primitives list
    std::list<Primitive*> primitives;

	//material
	Material * mat= new DiffuseMaterial(Vec3(1.0f,1.0f,1.0f));


	//
	//shape 1
	//
	//Sphere(1e5, Vec( 1e5+1,40.8,81.6), Vec(),Vec(.75,.25,.25),DIFF),//Left
	Transform t1a= Transform::CreateTranslate(1e5+1,40.8f,81.6f);
	Transform t1b= t1a.GetInverse();
	Primitive *g1 = new Sphere(t1a, t1b, 1e5f);
	//
	//shape 2
	//
//	   Sphere(1e5, Vec(-1e5+99,40.8,81.6),Vec(),Vec(.25,.25,.75),DIFF),//Rght 
	Transform t2a= Transform::CreateTranslate(-1e5f+99, 40.8f, 81.6f);
	Transform t2b= t2a.GetInverse();
	Primitive *g2 = new Sphere(t2a, t2b, 1e5);

	//
	//shape 3
	//
	//   Sphere(1e5, Vec(50,40.8, 1e5),     Vec(),Vec(.75,.75,.75),DIFF),//Back 
	Transform t3a= Transform::CreateTranslate(50.0f,40.8f, 1e5);
	Transform t3b= t3a.GetInverse();
	Primitive *g3 = new Sphere(t3a, t3b, 1e5f);


	//
	//shape 4
	//
//	Sphere(1e5, Vec(50,40.8,-1e5+170), Vec(),Vec(),           DIFF),//Frnt 
	Transform t4a= Transform::CreateTranslate(50.0f,40.8f,-1e5+170);
	Transform t4b= t4a.GetInverse();
	Primitive *g4 = new Sphere(t4a, t4b, 1e5f);
		   
	//
	//shape 5
	//
//		   Sphere(1e5, Vec(50, 1e5, 81.6),    Vec(),Vec(.75,.75,.75),DIFF),//Botm 
	Transform t5a= Transform::CreateTranslate(50, -1e5, 0);
	Transform t5b= t5a.GetInverse();
	Primitive *g5 = new Sphere(t5a, t5b, 1e5f);
			   
	//
	//shape 6
	//
//	Sphere(1e5, Vec(50,-1e5+81.6,81.6),Vec(),Vec(.75,.75,.75),DIFF),//Top 
	Transform t6a= Transform::CreateTranslate(50.0f,-1e5f+81.6f, 81.6f);
	Transform t6b= t6a.GetInverse();
	Primitive *g6 = new Sphere(t6a, t6b, 1e5);
				   
	//
	//shape 7
	//
//	Sphere(16.5,Vec(27,16.5,47),       Vec(),Vec(1,1,1)*.999, SPEC),//Mirr 
	Transform t7a= Transform::CreateTranslate(27.0f, 16.5f, 47.0f);
	Transform t7b= t7a.GetInverse();
	Primitive *g7 = new Sphere(t7a, t7b, 16.5f);

	//
	//shape 8
	//
//	Sphere(16.5,Vec(73,16.5,78),       Vec(),Vec(1,1,1)*.999, REFR),//Glas 
	Transform t8a= Transform::CreateTranslate(73,16.5,78);
	Transform t8b= t8a.GetInverse();
	Primitive *g8 = new Sphere(t8a, t8b, 16.5);

	//
	//shape 9
	//
//	Sphere(600, Vec(50,681.6-.27,81.6),Vec(12,12,12),  Vec(), DIFF) //Lite 
	Transform t9a= Transform::CreateTranslate(50.0f, 681.6f-0.27f, 81.6f);
	Transform t9b= t9a.GetInverse();
	Primitive *g9 = new Sphere(t9a, t9b, 600.0f);
						   


	//Accelerator

	primitives.push_back(g1); // left
	primitives.push_back(g2); //Rght 

	primitives.push_back(g3); //back
//	primitives.push_back(g4);//Frnt 
	primitives.push_back(g5);//bottom
	primitives.push_back(g6);//Top 

	primitives.push_back(g7);  //ball Mirr
	primitives.push_back(g8);  //ball glass
	primitives.push_back(g9); //Lite 
	
    DummyAccelerator *accelerator = new DummyAccelerator(primitives);

    //create film
    Film * film = new Image(256, 256, "task01.tga");
	
    //create camera
	Transform cam2world = Transform::CreateLookAt(Point(50.0f, 52.0f, 295.6f ), Point(50.0f, 52.0f-0.042612f, 295.6f-1.0f), Vec3(0.0f, 1.0f, 0.0f)).GetInverse();
    float aspectratio =float(film->GetWidth())/float(film->GetHeight());
    float screenWindow[4];
    if (aspectratio > 1.f)
    {
        screenWindow[0] = -aspectratio;
        screenWindow[1] =  aspectratio;
        screenWindow[2] = -1.f;
        screenWindow[3] =  1.f;
    }
    else
    {
        screenWindow[0] = -1.f;
        screenWindow[1] =  1.f;
        screenWindow[2] = -1.f / aspectratio;
        screenWindow[3] =  1.f / aspectratio;
    }
    float fov = 30;
    PerspectiveCamera *camera = new PerspectiveCamera(cam2world, screenWindow, fov, film);
//     OrthographicCamera *camera = new OrthographicCamera(cam2world, screenWindow, film);

    //integrator
    VolumeIntegrator* volume_integrator = nullPtr;
    SurfaceIntegrator* surface_integrator = new DirectLighting();

    //renderer
    Renderer * renderer = new Sampler(surface_integrator, volume_integrator,1);

	//lights
	std::list<Primitive*> lights;

    //scene
    Scene* scene = new Scene(accelerator, lights, camera);

    renderer->Render(scene);

	film->WriteImage();
}

void task04()
{
	//primitives list
    std::list<Primitive*> primitives;

	//light list
    std::list<Primitive*> lights;

	//material
	Material * mat= new DiffuseMaterial(Vec3(1.0f,1.0f,1.0f));


	//
	//shape 1
	//
	//Sphere(1e5, Vec( 1e5+1,40.8,81.6), Vec(),Vec(.75,.25,.25),DIFF),//Left
	Transform t1a= Transform::CreateTranslate(1e5+1,40.8f,81.6f);
	Transform t1b= t1a.GetInverse();
	Primitive *g1 = new Sphere(t1a, t1b, 1e5f);
	g1->name = "Left";
	g1->m_material = new DiffuseMaterial(Vec3(0.75f,0.25f,0.25f));
	//
	//shape 2
	//
//	   Sphere(1e5, Vec(-1e5+99,40.8,81.6),Vec(),Vec(.25,.25,.75),DIFF),//Rght 
	Transform t2a= Transform::CreateTranslate(-1e5f+99, 40.8f, 81.6f);
	Transform t2b= t2a.GetInverse();
	Primitive *g2 = new Sphere(t2a, t2b, 1e5);
	g2->name = "Rght";
	g2->m_material = new DiffuseMaterial(Vec3(0.25f,0.25f,0.75f));

	//
	//shape 3
	//
	//   Sphere(1e5, Vec(50,40.8, 1e5),     Vec(),Vec(.75,.75,.75),DIFF),//Back 
	Transform t3a= Transform::CreateTranslate(50.0f,40.8f, 1e5);
	Transform t3b= t3a.GetInverse();
	Primitive *g3 = new Sphere(t3a, t3b, 1e5f);
	g3->name = "Back";
	g3->m_material = new DiffuseMaterial(Vec3(0.75f,0.75f,0.75f));


	//
	//shape 4
	//
//	Sphere(1e5, Vec(50,40.8,-1e5+170), Vec(),Vec(),           DIFF),//Frnt 
	Transform t4a= Transform::CreateTranslate(50.0f,40.8f,-1e5+170);
	Transform t4b= t4a.GetInverse();
	Primitive *g4 = new Sphere(t4a, t4b, 1e5f);
	g4->name = "Frnt";
	g4->m_material = new DiffuseMaterial(Vec3(1.0f,1.0f,1.0f));
		   
	//
	//shape 5
	//
//		   Sphere(1e5, Vec(50, 1e5, 81.6),    Vec(),Vec(.75,.75,.75),DIFF),//Botm 
	Transform t5a= Transform::CreateTranslate(50, -1e5, 0);
	Transform t5b= t5a.GetInverse();
	Primitive *g5 = new Sphere(t5a, t5b, 1e5f);
	g5->name = "bottom";
	g5->m_material = new DiffuseMaterial(Vec3(0.75f,0.75f,0.75f));
			   
	//
	//shape 6
	//
//	Sphere(1e5, Vec(50,-1e5+81.6,81.6),Vec(),Vec(.75,.75,.75),DIFF),//Top 
	Transform t6a= Transform::CreateTranslate(50.0f,-1e5f+81.6f, 81.6f);
	Transform t6b= t6a.GetInverse();
	Primitive *g6 = new Sphere(t6a, t6b, 1e5);
	g6->name = "Top";
	g6->m_material = new DiffuseMaterial(Vec3(0.75f,0.75f,0.75f));

	//
	//shape 7
	//
//	Sphere(16.5,Vec(27,16.5,47),       Vec(),Vec(1,1,1)*.999, SPEC),//Mirr 
	Transform t7a= Transform::CreateTranslate(27.0f, 16.5f, 47.0f);
	Transform t7b= t7a.GetInverse();
	Primitive *g7 = new Sphere(t7a, t7b, 16.5f);
	g7->name = "Mirr";
	g7->m_material = new DiffuseMaterial(Vec3(1.0f,1.0f,1.0f));

	//
	//shape 8
	//
//	Sphere(16.5,Vec(73,16.5,78),       Vec(),Vec(1,1,1)*.999, REFR),//Glas 
	Transform t8a= Transform::CreateTranslate(0.0f, 25.0f, 80.f);
	Transform t8b= t8a.GetInverse();
	Primitive *g8 = new Sphere(t8a, t8b, 25.0f);
	g8->name = "Glas";
	g8->m_material = new DiffuseMaterial(Vec3(1.0f,1.0f,1.0f));
	//
	//shape 9
	//
//	Sphere(600, Vec(50,681.6-.27,81.6),Vec(12,12,12),  Vec(), DIFF) //Lite 
					   
	Transform t9a= Transform::CreateTranslate(0.0f, 80.0f, 0.0f);
	Transform t9b= t9a.GetInverse();
	Primitive *g9 = new Sphere(t9a, t9b, 2.0f);
	g9->name = "Lite";
	g9->isemiter = true;
	g9->m_material = new DiffuseMaterial(Vec3(1.0f,1.0f,1.0f));
	//Accelerator

//	primitives.push_back(g1); // left
	//primitives.push_back(g2); //Rght 

//	primitives.push_back(g3); //back
//	primitives.push_back(g4);//Frnt 
	primitives.push_back(g5);//bottom
//	primitives.push_back(g6);//Top 

//	primitives.push_back(g7);  //ball Mirr
	primitives.push_back(g8);  //ball glass
//	primitives.push_back(g9);  //ball glass
	lights.push_back(g9); //Lite 
	
    DummyAccelerator *accelerator = new DummyAccelerator(primitives);

    //create film
    Film * film = new Image(128, 128, "task01.tga");
	
    //create camera
	Transform cam2world = Transform::CreateLookAt(Point(0.0f, 40.0f, 500.6f ), Point(0.0f, 10.0f, 0.0f), Vec3(0.0f, 1.0f, 0.0f)).GetInverse();
    float aspectratio =float(film->GetWidth())/float(film->GetHeight());
    float screenWindow[4];
    if (aspectratio > 1.f)
    {
        screenWindow[0] = -aspectratio;
        screenWindow[1] =  aspectratio;
        screenWindow[2] = -1.f;
        screenWindow[3] =  1.f;
    }
    else
    {
        screenWindow[0] = -1.f;
        screenWindow[1] =  1.f;
        screenWindow[2] = -1.f / aspectratio;
        screenWindow[3] =  1.f / aspectratio;
    }
    float fov = 30;
    PerspectiveCamera *camera = new PerspectiveCamera(cam2world, screenWindow, fov, film);
//     OrthographicCamera *camera = new OrthographicCamera(cam2world, screenWindow, film);

    //integrator
    VolumeIntegrator* volume_integrator = nullPtr;
    SurfaceIntegrator* surface_integrator = new DirectLighting();

    //renderer
    Renderer * renderer = new Sampler(surface_integrator, volume_integrator,1);

    //scene
    Scene* scene = new Scene(accelerator, lights, camera);

    renderer->Render(scene);

	film->WriteImage();
}

void tp1_5()
{
	//primitives list
    std::list<Primitive*> primitives;

	//lights list
    std::list<Primitive*> lights;

	//
	//shape 1  bottom
	//
	Transform t1a= Transform::CreateTranslate(0.0f, -10e5f-50.0f, 0.0f);
	Transform t1b= t1a.GetInverse();
	Primitive *g1 = new Sphere(t1a, t1b, 10e5f);
	g1->m_material = new DiffuseMaterial(Vec3(0.75f, 0.75f, 0.75f));

	//
	//shape 2
	//
	Transform t2a= Transform::CreateTranslate(0.0, 4.0, 0.0);
	Transform t2b= t2a.GetInverse();
	Primitive *g2 = new Sphere(t2a, t2b, 4.0f);
	g2->m_material = new DiffuseMaterial(Vec3(0.3f, 0.5f, 0.75f));

	//
	//shape 3  left
	//
	Transform t3a= Transform::CreateTranslate(-50.0f-1e5f, 0.0, 0.0);
	Transform t3b= t3a.GetInverse();
	Primitive *g3 = new Sphere(t3a, t3b, 1e5f);
	g3->m_material = new DiffuseMaterial(Vec3(0.75f,0.25f,0.25f));

	//
	//shape 4  right
	//
	Transform t4a= Transform::CreateTranslate(+50.0f+1e5f, 0.0, 0.0);
	Transform t4b= t4a.GetInverse();
	Primitive *g4 = new Sphere(t4a, t4b, 1e5f);
	g4->m_material = new DiffuseMaterial(Vec3(0.25f, 0.25f, 0.75f));

	//
	//shape 5 top
	//
	Transform t5a= Transform::CreateTranslate(0.0, 10e5f+50.0f, 0.0);
	Transform t5b= t4a.GetInverse();
	Primitive *g5 = new Sphere(t5a, t5b, 1e5f);
	g5->m_material = new DiffuseMaterial(Vec3(0.75f, 0.75f, 0.75f));


	//
	//lights
	//
	Transform tla= Transform::CreateTranslate(0.0, 10.0, 0.0);
	Transform tlb= t3a.GetInverse();
	Primitive *l1 = new Sphere(tla, tlb, 1.0f);
	l1->m_material = new DiffuseMaterial(Vec3(10.0, 10.0, 10.0));
	lights.push_back(l1);

	//Accelerator
	primitives.push_back(g1);
	primitives.push_back(g2);
	primitives.push_back(g3);
	primitives.push_back(g4);
	primitives.push_back(g5);
    DummyAccelerator *accelerator = new DummyAccelerator(primitives);

    //create film
    Film * film = new Image(256, 256, "task01.tga");
	
    //create camera
	Transform cam2world = Transform::CreateLookAt(Point(0.0f, 5.0f, 255.0f), Point(0.0f, 0.0f, 0.0f), Vec3(0.0, 1.0, 0.0)).GetInverse();

    float aspectratio =float(film->GetWidth())/float(film->GetHeight());
    float screenWindow[4];
    if (aspectratio > 1.f)
    {
        screenWindow[0] = -aspectratio;
        screenWindow[1] =  aspectratio;
        screenWindow[2] = -1.f;
        screenWindow[3] =  1.f;
    }
    else
    {
        screenWindow[0] = -1.f;
        screenWindow[1] =  1.f;
        screenWindow[2] = -1.f / aspectratio;
        screenWindow[3] =  1.f / aspectratio;
    }
    float fov = 29.5*2;
    PerspectiveCamera *camera = new PerspectiveCamera(cam2world, screenWindow, fov, film);

    //integrator
    VolumeIntegrator* volume_integrator = nullPtr;
	SurfaceIntegrator* surface_integrator =  new DirectLighting();

    //renderer
    Renderer * renderer = new Sampler(surface_integrator, volume_integrator);

    //scene
    Scene* scene = new Scene(accelerator, lights, camera);

    renderer->Render(scene);

	film->WriteImage();
}
*/

void tp1_5(int samples, std::string filename, int width, int height)
{
	//primitives list
    vector<Reference<Primitive>> primitives;

	//lights list
    vector<Light*> lights;

	//
	//
	//shape 1
	//
	//Sphere(1e5, Vec( 1e5+1,40.8,81.6), Vec(),Vec(.75,.25,.25),DIFF),//Left
	Transform t1a= Transform::CreateTranslate(1e5+1,40.8f,81.6f);
	Transform t1b= t1a.GetInverse();
	Reference<Shape> s1 = Reference<Shape>(new Sphere(&t1a, &t1b, false, 1e5f));
	Material *m1 = new DiffuseMaterial(Spectrum(Vec3(0.75f,0.25f,0.25f)));
	Reference<Primitive> g1(new GeometricPrimitive(s1, m1, NULL));

	//
	//shape 2
	//
//	   Sphere(1e5, Vec(-1e5+99,40.8,81.6),Vec(),Vec(.25,.25,.75),DIFF),//Rght 
	Transform t2a= Transform::CreateTranslate(-1e5f+99.0f, 40.8f, 81.6f);
	Transform t2b= t2a.GetInverse();
    Reference<Shape> s2 = Reference<Shape>(new Sphere(&t2a, &t2b, false, 1e5));
	Material *m2 = new DiffuseMaterial(Spectrum(Vec3(0.25f,0.25f,0.75f)));
    Reference<Primitive> g2(new GeometricPrimitive(s2, m2, NULL));

	//
	//shape 3
	//
	//   Sphere(1e5, Vec(50,40.8, 1e5),     Vec(),Vec(.75,.75,.75),DIFF),//Back 
	Transform t3a= Transform::CreateTranslate(50.0f,40.8f, 1e5);
	Transform t3b= t3a.GetInverse();
    Reference<Shape> s3 = Reference<Shape>(new Sphere(&t3a, &t3b, false,1e5f));
	Material *m3 = new DiffuseMaterial(Spectrum(Vec3(0.75f,0.75f,0.75f)));
    Reference<Primitive> g3(new GeometricPrimitive(s3, m3, NULL));

	//
	//shape 4
	//
//	Sphere(1e5, Vec(50,40.8,-1e5+170), Vec(),Vec(),           DIFF),//Frnt 
	Transform t4a= Transform::CreateTranslate(50.0f,40.8f,-1e5+120);
	Transform t4b= t4a.GetInverse();
    Reference<Shape> s4 = Reference<Shape>(new Sphere(&t4a, &t4b, false,1e5f));
	Material *m4 = new DiffuseMaterial(Spectrum(Vec3(1.0f,1.0f,1.0f)));
    Reference<Primitive> g4(new GeometricPrimitive(s4, m4, NULL));
		   
	//
	//shape 5
	//
//		   Sphere(1e5, Vec(50, 1e5, 81.6),    Vec(),Vec(.75,.75,.75),DIFF),//Botm 
	Transform t5a= Transform::CreateTranslate(50, -1e5, 0);
	Transform t5b= t5a.GetInverse();
    Reference<Shape> s5 = Reference<Shape>(new Sphere(&t5a, &t5b, false, 1e5f));
	Material *m5 = new DiffuseMaterial(Spectrum(Vec3(0.75f,0.75f,0.75f)));
    Reference<Primitive> g5 = (new GeometricPrimitive(s5, m5, NULL));
	//
	//shape 6
	//
//	Sphere(1e5, Vec(50,-1e5+81.6,81.6),Vec(),Vec(.75,.75,.75),DIFF),//Top 
	Transform t6a= Transform::CreateTranslate(50.0f, 1e5f+81.6f, 90.6f);
	Transform t6b= t6a.GetInverse();
    Reference<Shape> s6 = Reference<Shape>(new Sphere(&t6a, &t6b, false, 1e5));
	Material *m6 = new DiffuseMaterial(Spectrum(Vec3(0.75f,0.75f,0.75f)));
    Reference<Primitive> g6(new GeometricPrimitive(s6, m6, NULL));

	//
	//shape 7
	//
//	Sphere(16.5,Vec(27,16.5,47),       Vec(),Vec(1,1,1)*.999, SPEC),//Mirr 
	Transform t7a= Transform::CreateTranslate(27.0f, 16.5f, 180.0f);
	Transform t7b= t7a.GetInverse();
    Reference<Shape> s7 = Reference<Shape>(new Sphere(&t7a, &t7b, false, 16.5f));
	Material *m7 = new DiffuseMaterial(Spectrum(Vec3(1.0f,1.0f,1.0f)));
    Reference<Primitive> g7(new GeometricPrimitive(s7, m7, NULL));

	//
	//shape 8
	//
//	Sphere(16.5,Vec(73,16.5,78),       Vec(),Vec(1,1,1)*.999, REFR),//Glas 
	Transform t8a= Transform::CreateTranslate(73.0f, 16.5f, 150.0f);
	Transform t8b= t8a.GetInverse();
    Reference<Shape> s8 = Reference<Shape>(new Sphere(&t8a, &t8b, false, 16.5f));
	Material *m8 = new DiffuseMaterial(Spectrum(Vec3(1.0f,1.0f,1.0f)));
    Reference<Primitive> g8(new GeometricPrimitive(s8, m8, NULL));

	//
	//shape 9 lite
	//
	Transform t9a= Transform::CreateTranslate(70.0f, 70.5f, 180.0f);
	Transform t9b= t9a.GetInverse();
    Reference<Shape> s9 = Reference<Shape>(new Sphere(&t9a, &t9b, false, 2.0f));
	Material *m9 = new DiffuseMaterial(Spectrum(Vec3(M_PI*0.75f, M_PI*0.75f, M_PI)*70.0f));
    Spectrum a1l = Spectrum(130.0);
    DiffuseAreaLight * al = new DiffuseAreaLight(t9a, a1l, 1, s9);
    Reference<Primitive> g9(new GeometricPrimitive(s9, m9, al));
	lights.push_back(al);
    primitives.push_back(Reference<Primitive>(g9));

	//Accelerator
	primitives.push_back(g1);
	primitives.push_back(g2);
////	primitives.push_back(g3);
	primitives.push_back(g4);
	primitives.push_back(g5);
	primitives.push_back(g6);
	primitives.push_back(g7);
	primitives.push_back(g8);
	primitives.push_back(g9);


    DummyAccelerator *accelerator = new DummyAccelerator(primitives);

    //create film
	Film * film = new Image(width, height, filename);

    //create camera
	Transform cam2world = Transform::CreateLookAt(Point(50.0f, 52.0f, 295.6f ), Point(50.0f, 52.0f-0.042612f, 295.6f-1.0f), Vec3(0.0f, 1.0f, 0.0f)).GetInverse();

    float aspectratio =float(film->GetWidth())/float(film->GetHeight());
    float screenWindow[4];
    if (aspectratio > 1.f)
    {
        screenWindow[0] = -aspectratio;
        screenWindow[1] =  aspectratio;
        screenWindow[2] = -1.f;
        screenWindow[3] =  1.f;
    }
    else
    {
        screenWindow[0] = -1.f;
        screenWindow[1] =  1.f;
        screenWindow[2] = -1.f / aspectratio;
        screenWindow[3] =  1.f / aspectratio;
    }
    float fov = 29.5*2;
    PerspectiveCamera *camera = new PerspectiveCamera(cam2world, screenWindow, fov, film);

    //integrator
    VolumeIntegrator* volume_integrator = 0;
//    SurfaceIntegrator* surface_integrator =  new AmbientOcclusion(10, 10.0f);
    SurfaceIntegrator* surface_integrator =  new DirectLighting();

    //renderer
    Renderer * renderer = new Sampler(surface_integrator, volume_integrator, samples);

    //scene
    Scene* scene = new Scene(accelerator, lights, camera);

    renderer->Render(scene);

	film->WriteImage();
}


void monkey_mesh_light(int samples, std::string filename, int width, int height, DirectLightingStrategy dls, int light_samples)
{
	//primitives list
	vector<Reference<Primitive>> primitives;

	//lights list
	vector<Light*> lights;

	Transform t1a = Transform::CreateTranslate(0.0f, -0.5f, 0.0f);
	Transform t1b = t1a.GetInverse();

	ObjMeshLoader obj_loader;

	//floor
	obj_loader.Parse("scenes/mitsuba_cornallbox/meshes/cbox_floor.obj");
	Reference<Shape> floor = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size() / 3, (int)obj_loader.m_Points.size(),
		obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
		obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
		obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
		0,
		obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m1 = new DiffuseMaterial(Spectrum(Vec3(0.75f, 0.75f, 0.75f)));
	Primitive *g1 = new GeometricPrimitive(floor, m1, NULL);
	if (!g1->CanIntersect())
	{
		vector<Reference<Primitive> > refinedPrimitives;
		g1->FullyRefine(refinedPrimitives);
		g1 = new DummyAccelerator(refinedPrimitives);
	}


	//ceiling
	obj_loader.Parse("scenes/mitsuba_cornallbox/meshes/cbox_ceiling.obj");
	Reference<Shape> ceiling = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size() / 3, (int)obj_loader.m_Points.size(),
		obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
		obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
		obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
		0,
		obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m2 = new DiffuseMaterial(Spectrum(Vec3(0.75f, 0.75f, 0.75f)));
	Primitive *g2 = new GeometricPrimitive(ceiling, m2, NULL);
	if (!g2->CanIntersect())
	{
		vector<Reference<Primitive> > refinedPrimitives;
		g2->FullyRefine(refinedPrimitives);
		g2 = new DummyAccelerator(refinedPrimitives);
	}


	//back
	obj_loader.Parse("scenes/mitsuba_cornallbox/meshes/cbox_back.obj");
	Reference<Shape> back = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size() / 3, (int)obj_loader.m_Points.size(),
		obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
		obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
		obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
		0,
		obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m3 = new DiffuseMaterial(Spectrum(Vec3(0.75f, 0.75f, 0.75f)));
	Primitive* g3 = new GeometricPrimitive(back, m3, NULL);
	if (!g3->CanIntersect())
	{
		vector<Reference<Primitive> > refinedPrimitives;
		g3->FullyRefine(refinedPrimitives);
		g3 = new DummyAccelerator(refinedPrimitives);
	}

	//greenwall
	obj_loader.Parse("scenes/mitsuba_cornallbox/meshes/cbox_greenwall.obj");
	Reference<Shape> greenwall = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size() / 3, (int)obj_loader.m_Points.size(),
		obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
		obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
		obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
		0,
		obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m4 = new DiffuseMaterial(Spectrum(Vec3(0.75f, 0.25f, 0.25f)));
	Primitive* g4 = new GeometricPrimitive(greenwall, m4, NULL);
	if (!g4->CanIntersect())
	{
		vector<Reference<Primitive> > refinedPrimitives;
		g4->FullyRefine(refinedPrimitives);
		g4 = new DummyAccelerator(refinedPrimitives);
	}

	//redwall
	obj_loader.Parse("scenes/mitsuba_cornallbox/meshes/cbox_redwall.obj");
	Reference<Shape> redwall = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size() / 3, (int)obj_loader.m_Points.size(),
		obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
		obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
		obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
		0,
		obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m5 = new DiffuseMaterial(Spectrum(Vec3(0.25f, 0.25f, 0.75f)));
	Primitive* g5 = new GeometricPrimitive(redwall, m5, NULL);
	if (!g5->CanIntersect())
	{
		vector<Reference<Primitive> > refinedPrimitives;
		g5->FullyRefine(refinedPrimitives);
		g5 = new DummyAccelerator(refinedPrimitives);
	}
	/*
	//ball
	Transform s1a = Transform::CreateTranslate(135.0, 100.0, 315.5);
	Transform s1b = s1a.GetInverse();
	Reference<Shape> largebox = Reference<Shape>(new Sphere(&s1a, &s1b, 100.0f));
	Material *m6 = new DiffuseMaterial(Spectrum(Vec3(1.0f, 1.0f, 1.0f)));
	Primitive* g6 = new GeometricPrimitive(largebox, m6, NULL);
	if (!g6->CanIntersect())
	{
		vector<Reference<Primitive> > refinedPrimitives;
		g6->FullyRefine(refinedPrimitives);
		g6 = new DummyAccelerator(refinedPrimitives);
	}
	*/
	/*
	//monkey
	Transform s2a = Transform::CreateTranslate(278.0, 200.0, 400.5)*Transform::CreateScale(20.0f, 20.0f, 20.0f)*Transform::CreateRotate_y(180.0f);
	Transform s2b = s2a.GetInverse();
	obj_loader.Parse("scenes/obj/blender_monkey.obj");
	//obj_loader.Parse("scenes/obj/cube.obj");
	Reference<Shape> monkey = Reference<Shape>(new TriangleMesh(&s2a, &s2b, true, (int)obj_loader.m_VertexIndex.size() / 3, (int)obj_loader.m_Points.size(),
		obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
		obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
		obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
		0,
		obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m7 = new DiffuseMaterial(Spectrum(Vec3(0.25f, 0.75, 0.75)));
	Primitive* g7 = new GeometricPrimitive(monkey, m7, NULL);
	if (!g7->CanIntersect())
	{
		vector<Reference<Primitive> > refinedPrimitives;
		g7->FullyRefine(refinedPrimitives);
		g7 = new DummyAccelerator(refinedPrimitives);
	}
	*/

	//light
	/*
	Transform t9a = Transform::CreateTranslate(278.0, 920.0, 270.5);
	Transform t9b = t9a.GetInverse();
	Reference<Shape> s9 = Reference<Shape>(new Sphere(&t9a, &t9b, 400.0f));
	*/
	/*
	Transform t9a = Transform::CreateTranslate(278.0, 400.0, 270.5);
	Transform t9b = t9a.GetInverse();
	Reference<Shape> s9 = Reference<Shape>(new Sphere(&t9a, &t9b, false, 50.0f));
	*/
	Transform t9a = Transform::CreateTranslate(278.0, 200.0, 270)*Transform::CreateScale(30.0f, 30.0f, 30.0f)*Transform::CreateRotate_y(180.0f);
	Transform t9b = t9a.GetInverse();
	obj_loader.Parse("scenes/obj/blender_monkey.obj");
	Reference<Shape> s9 = Reference<Shape>(new TriangleMesh(&t9a, &t9b, false, (int)obj_loader.m_VertexIndex.size() / 3, (int)obj_loader.m_Points.size(),
		obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
		obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
		obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
		0,
		obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m9 = new DiffuseMaterial(Spectrum(0.0));
	Spectrum a1l = Spectrum(12.0);
	DiffuseAreaLight * al = new DiffuseAreaLight(t9a, a1l, light_samples, s9);
	Primitive* g9 = new GeometricPrimitive(s9, m9, al);
	lights.push_back(al);
	if (!g9->CanIntersect())
	{
		vector<Reference<Primitive> > refinedPrimitives;
		g9->FullyRefine(refinedPrimitives);
		g9 = new DummyAccelerator(refinedPrimitives);
	}
	primitives.push_back(g9);

	//Accelerator
	primitives.push_back(g1);
	primitives.push_back(g2);
	primitives.push_back(g3);
	primitives.push_back(g4);
	primitives.push_back(g5);
	//	primitives.push_back(g6);
//	primitives.push_back(g7);

	Primitive *accelerator = new BVHAccel(primitives);

	//create film
	Film * film = new Image(width, height, filename);

	//create camera
	Transform cam2world = Transform::CreateLookAt(Point(278.0f, 273.0f, -700.0f), Point(278.0f, 273.0f, -0.0f), Vec3(0.0f, 1.0f, 0.0f)).GetInverse();

	float aspectratio = float(film->GetWidth()) / float(film->GetHeight());
	float screenWindow[4];
	if (aspectratio > 1.f)
	{
		screenWindow[0] = -aspectratio;
		screenWindow[1] = aspectratio;
		screenWindow[2] = -1.f;
		screenWindow[3] = 1.f;
	}
	else
	{
		screenWindow[0] = -1.f;
		screenWindow[1] = 1.f;
		screenWindow[2] = -1.f / aspectratio;
		screenWindow[3] = 1.f / aspectratio;
	}
	float fov = 39.3077 * 1.0;
	PerspectiveCamera *camera = new PerspectiveCamera(cam2world, screenWindow, fov, film);

	//integrator
	VolumeIntegrator* volume_integrator = nullPtr;
	//    SurfaceIntegrator* surface_integrator =  new AmbientOcclusion(10, 10.0f);
	SurfaceIntegrator* surface_integrator = new DirectLighting(dls);
	//SurfaceIntegrator* surface_integrator = new PathTracing(dls);

	//renderer
	Renderer * renderer = new Sampler(surface_integrator, volume_integrator, samples);

	//scene
	Scene* scene = new Scene(accelerator, lights, camera);

	renderer->Render(scene);

	film->WriteImage();
}


void jensen_cbox(int samples, std::string filename, int width, int height, DirectLightingStrategy dls)
{
	//primitives list
	vector<Reference<Primitive>> primitives;

	//lights list
	vector<Light*> lights;

	Transform t1a = Transform::CreateTranslate(0.0f, -0.5f, 0.0f);
	Transform t1b = t1a.GetInverse();

	ObjMeshLoader obj_loader;

	//floor
	obj_loader.Parse("scenes/mitsuba_cornallbox/meshes/cbox_floor.obj");
	Reference<Shape> floor = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size() / 3, (int)obj_loader.m_Points.size(),
		obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
		obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
		obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
		0,
		obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m1 = new DiffuseMaterial(Spectrum(Vec3(0.75f, 0.75f, 0.75f)));
	Primitive *g1 = new GeometricPrimitive(floor, m1, NULL);
	if (!g1->CanIntersect())
	{
		vector<Reference<Primitive> > refinedPrimitives;
		g1->FullyRefine(refinedPrimitives);
		g1 = new DummyAccelerator(refinedPrimitives);
	}


	//ceiling
	obj_loader.Parse("scenes/mitsuba_cornallbox/meshes/cbox_ceiling.obj");
	Reference<Shape> ceiling = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size() / 3, (int)obj_loader.m_Points.size(),
		obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
		obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
		obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
		0,
		obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m2 = new DiffuseMaterial(Spectrum(Vec3(0.75f, 0.75f, 0.75f)));
	Primitive *g2 = new GeometricPrimitive(ceiling, m2, NULL);
	if (!g2->CanIntersect())
	{
		vector<Reference<Primitive> > refinedPrimitives;
		g2->FullyRefine(refinedPrimitives);
		g2 = new DummyAccelerator(refinedPrimitives);
	}


	//back
	obj_loader.Parse("scenes/mitsuba_cornallbox/meshes/cbox_back.obj");
	Reference<Shape> back = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size() / 3, (int)obj_loader.m_Points.size(),
		obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
		obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
		obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
		0,
		obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m3 = new DiffuseMaterial(Spectrum(Vec3(0.75f, 0.75f, 0.75f)));
	Primitive* g3 = new GeometricPrimitive(back, m3, NULL);
	if (!g3->CanIntersect())
	{
		vector<Reference<Primitive> > refinedPrimitives;
		g3->FullyRefine(refinedPrimitives);
		g3 = new DummyAccelerator(refinedPrimitives);
	}

	//greenwall
	obj_loader.Parse("scenes/mitsuba_cornallbox/meshes/cbox_greenwall.obj");
	Reference<Shape> greenwall = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size() / 3, (int)obj_loader.m_Points.size(),
		obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
		obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
		obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
		0,
		obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m4 = new DiffuseMaterial(Spectrum(Vec3(0.75f, 0.25f, 0.25f)));
	Primitive* g4 = new GeometricPrimitive(greenwall, m4, NULL);
	if (!g4->CanIntersect())
	{
		vector<Reference<Primitive> > refinedPrimitives;
		g4->FullyRefine(refinedPrimitives);
		g4 = new DummyAccelerator(refinedPrimitives);
	}

	//redwall
	obj_loader.Parse("scenes/mitsuba_cornallbox/meshes/cbox_redwall.obj");
	Reference<Shape> redwall = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size() / 3, (int)obj_loader.m_Points.size(),
		obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
		obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
		obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
		0,
		obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m5 = new DiffuseMaterial(Spectrum(Vec3(0.25f, 0.25f, 0.75f)));
	Primitive* g5 = new GeometricPrimitive(redwall, m5, NULL);
	if (!g5->CanIntersect())
	{
		vector<Reference<Primitive> > refinedPrimitives;
		g5->FullyRefine(refinedPrimitives);
		g5 = new DummyAccelerator(refinedPrimitives);
	}

	//ball
	Transform s1a = Transform::CreateTranslate(135.0, 100.0, 315.5);
	Transform s1b = s1a.GetInverse();
	Reference<Shape> largebox = Reference<Shape>(new Sphere(&s1a, &s1b, false, 100.0f));
	Material *m6 = new DiffuseMaterial(Spectrum(Vec3(1.0f, 1.0f, 1.0f)));
	Primitive* g6 = new GeometricPrimitive(largebox, m6, NULL);
	if (!g6->CanIntersect())
	{
		vector<Reference<Primitive> > refinedPrimitives;
		g6->FullyRefine(refinedPrimitives);
		g6 = new DummyAccelerator(refinedPrimitives);
	}

	//ball
	Transform s2a = Transform::CreateTranslate(420.0, 100.0, 415.5);
	Transform s2b = s2a.GetInverse();
	Reference<Shape> smallbox = Reference<Shape>(new Sphere(&s2a, &s2b, false, 100.0f));
	Material *m7 = new DiffuseMaterial(Spectrum(Vec3(1.0f, 1.0f, 1.0f)));
	Primitive* g7 = new GeometricPrimitive(smallbox, m7, NULL);
	if (!g7->CanIntersect())
	{
		vector<Reference<Primitive> > refinedPrimitives;
		g7->FullyRefine(refinedPrimitives);
		g7 = new DummyAccelerator(refinedPrimitives);
	}


	//light
	/*
	Transform t9a = Transform::CreateTranslate(278.0, 920.0, 270.5);
	Transform t9b = t9a.GetInverse();
	Reference<Shape> s9 = Reference<Shape>(new Sphere(&t9a, &t9b, 400.0f));
	*/
	
	Transform t9a = Transform::CreateTranslate(278.0, 400.0, 270.5);
	Transform t9b = t9a.GetInverse();
	Reference<Shape> s9 = Reference<Shape>(new Sphere(&t9a, &t9b, false, 100.0f));
	
	Material *m9 = new DiffuseMaterial(Spectrum(0.0));
	Spectrum a1l = Spectrum(12.0);
	DiffuseAreaLight * al = new DiffuseAreaLight(t9a, a1l, 1, s9);
	GeometricPrimitive* g9 = new GeometricPrimitive(s9, m9, al);
	lights.push_back(al);
	primitives.push_back(g9);

	//Accelerator
	primitives.push_back(g1);
	primitives.push_back(g2);
	primitives.push_back(g3);
	primitives.push_back(g4);
	primitives.push_back(g5);
	primitives.push_back(g6);
	primitives.push_back(g7);

	Primitive *accelerator = new BVHAccel(primitives);

	//create film
	Film * film = new Image(width, height, filename);

	//create camera
	Transform cam2world = Transform::CreateLookAt(Point(278.0f, 273.0f, -700.0f), Point(278.0f, 273.0f, -0.0f), Vec3(0.0f, 1.0f, 0.0f)).GetInverse();

	float aspectratio = float(film->GetWidth()) / float(film->GetHeight());
	float screenWindow[4];
	if (aspectratio > 1.f)
	{
		screenWindow[0] = -aspectratio;
		screenWindow[1] = aspectratio;
		screenWindow[2] = -1.f;
		screenWindow[3] = 1.f;
	}
	else
	{
		screenWindow[0] = -1.f;
		screenWindow[1] = 1.f;
		screenWindow[2] = -1.f / aspectratio;
		screenWindow[3] = 1.f / aspectratio;
	}
	float fov = 39.3077 * 1.0;
	PerspectiveCamera *camera = new PerspectiveCamera(cam2world, screenWindow, fov, film);

	//integrator
	VolumeIntegrator* volume_integrator = nullPtr;
	//    SurfaceIntegrator* surface_integrator =  new AmbientOcclusion(10, 10.0f);
//	SurfaceIntegrator* surface_integrator = new DirectLighting(dls);
	SurfaceIntegrator* surface_integrator = new PathTracing(dls);

	//renderer
	Renderer * renderer = new Sampler(surface_integrator, volume_integrator, samples);

	//scene
	Scene* scene = new Scene(accelerator, lights, camera);

	renderer->Render(scene);

	film->WriteImage();
}


void mitsuba_cbox(int samples, std::string filename, int width, int height, DirectLightingStrategy dls)
{
    //primitives list
    vector<Reference<Primitive>> primitives;

    //lights list
    vector<Light*> lights;

    Transform t1a= Transform::CreateTranslate(0.0f, -0.5f, 0.0f);
    Transform t1b= t1a.GetInverse();

    ObjMeshLoader obj_loader;

    //floor
    obj_loader.Parse("scenes/mitsuba_cornallbox/meshes/cbox_floor.obj");
    Reference<Shape> floor = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size() / 3, (int)obj_loader.m_Points.size(),
            obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0]:0,
            obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
            obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
            0,
            obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m1 = new DiffuseMaterial(Spectrum(Vec3(0.75f, 0.75f, 0.75f)));
    Primitive *g1= new GeometricPrimitive(floor, m1, NULL);
    if (!g1->CanIntersect())
    {
        vector<Reference<Primitive> > refinedPrimitives;
        g1->FullyRefine(refinedPrimitives);
        g1 = new DummyAccelerator(refinedPrimitives);
    }


    //ceiling
    obj_loader.Parse("scenes/mitsuba_cornallbox/meshes/cbox_ceiling.obj");
    Reference<Shape> ceiling = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size()/3, (int)obj_loader.m_Points.size(),
            obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
            obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
            obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
            0,
            obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m2 = new DiffuseMaterial(Spectrum(Vec3(0.75f, 0.75f, 0.75f)));
    Primitive *g2 = new GeometricPrimitive(ceiling, m2, NULL);
    if (!g2->CanIntersect())
    {
        vector<Reference<Primitive> > refinedPrimitives;
        g2->FullyRefine(refinedPrimitives);
        g2 = new DummyAccelerator(refinedPrimitives);
    }


    //back
    obj_loader.Parse("scenes/mitsuba_cornallbox/meshes/cbox_back.obj");
    Reference<Shape> back = Reference<Shape> (new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size()/3, (int)obj_loader.m_Points.size(),
            obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
            obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
            obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
            0,
            obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
    Material *m3 = new DiffuseMaterial(Spectrum(Vec3(0.75f, 0.75f, 0.75f)));
    Primitive* g3 = new GeometricPrimitive(back, m3, NULL);
    if (!g3->CanIntersect())
    {
        vector<Reference<Primitive> > refinedPrimitives;
        g3->FullyRefine(refinedPrimitives);
        g3 = new DummyAccelerator(refinedPrimitives);
    }

    //greenwall
    obj_loader.Parse("scenes/mitsuba_cornallbox/meshes/cbox_greenwall.obj");
    Reference<Shape> greenwall = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size()/3, (int)obj_loader.m_Points.size(),
            obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
            obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
            obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
            0,
            obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m4 = new DiffuseMaterial(Spectrum(Vec3(0.25f, 0.75f, 0.25f)));
    Primitive* g4 = new GeometricPrimitive(greenwall, m4, NULL);
    if (!g4->CanIntersect())
    {
        vector<Reference<Primitive> > refinedPrimitives;
        g4->FullyRefine(refinedPrimitives);
        g4 = new DummyAccelerator(refinedPrimitives);
    }

    //redwall
    obj_loader.Parse("scenes/mitsuba_cornallbox/meshes/cbox_redwall.obj");
    Reference<Shape> redwall = Reference<Shape> (new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size()/3, (int)obj_loader.m_Points.size(),
            obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
            obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
            obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
            0,
            obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m5 = new DiffuseMaterial(Spectrum(Vec3(0.75f, 0.25f, 0.25f)));
    Primitive* g5 = new GeometricPrimitive(redwall, m5, NULL);
    if (!g5->CanIntersect())
    {
        vector<Reference<Primitive> > refinedPrimitives;
        g5->FullyRefine(refinedPrimitives);
        g5 = new DummyAccelerator(refinedPrimitives);
    }

    //largebox
    obj_loader.Parse("scenes/mitsuba_cornallbox/meshes/cbox_largebox.obj");
    Reference<Shape> largebox = Reference<Shape> (new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size() / 3, (int)obj_loader.m_Points.size(),
            obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
            obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
            obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
            0,
            obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
    Material *m6 = new DiffuseMaterial(Spectrum(Vec3(0.75f, 0.75f, 0.75f)));
    Primitive* g6 = new GeometricPrimitive(largebox, m6, NULL);
    if (!g6->CanIntersect())
    {
        vector<Reference<Primitive> > refinedPrimitives;
        g6->FullyRefine(refinedPrimitives);
        g6 = new DummyAccelerator(refinedPrimitives);
    }

    //smallbox
    obj_loader.Parse("scenes/mitsuba_cornallbox/meshes/cbox_smallbox.obj");
    Reference<Shape> smallbox = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size() / 3, (int)obj_loader.m_Points.size(),
            obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
            obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
            obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
            0,
            obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
    Material *m7 = new DiffuseMaterial(Spectrum(Vec3(0.75f, 0.75f, 0.75f)));
    Primitive* g7 = new GeometricPrimitive(smallbox, m7, NULL);
    if (!g7->CanIntersect())
    {
        vector<Reference<Primitive> > refinedPrimitives;
        g7->FullyRefine(refinedPrimitives);
        g7 = new DummyAccelerator(refinedPrimitives);
    }


    //
    //shape 9 lite
    //
    //
	
    Transform t9a = Transform::CreateTranslate(278.0f, 920.79999f, 279.0f);
    Transform t9b= t9a.GetInverse();
    Reference<Shape> s9 = Reference<Shape> (new Sphere(&t9a, &t9b, false, 400.0f));
    Material *m9 = new DiffuseMaterial(Spectrum(Vec3(M_PI*0.75f, M_PI*0.75f, M_PI)*70.0f));
    Spectrum a1l = Spectrum(13.0);
    DiffuseAreaLight * al = new DiffuseAreaLight(t9a, a1l, 1, s9);
    GeometricPrimitive* g9 = new GeometricPrimitive(s9, m9, al);
	/*
	obj_loader.Parse("scenes/mitsuba_cornallbox/meshes/cbox_luminaire.obj");
	Reference<Shape> s9 = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size() / 3, (int)obj_loader.m_Points.size(),
		obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
		obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
		obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
		0,
		obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m9 = new DiffuseMaterial(Spectrum(Vec3(M_PI*0.75f, M_PI*0.75f, M_PI)*70.0f));
	Spectrum a1l = Spectrum(13.0);
	DiffuseAreaLight * al = new DiffuseAreaLight(t1a, a1l, 1, s9);
	Primitive* g9 = new GeometricPrimitive(s9, m9, al);
	if (!g9->CanIntersect())
	{
		vector<Reference<Primitive> > refinedPrimitives;
		g9->FullyRefine(refinedPrimitives);
		g9 = new DummyAccelerator(refinedPrimitives);
	}
	*/
    lights.push_back(al);
    primitives.push_back(g9);

    //Accelerator
    primitives.push_back(g1);
    primitives.push_back(g2);
    primitives.push_back(g3);
    primitives.push_back(g4);
    primitives.push_back(g5);
    primitives.push_back(g6);
    primitives.push_back(g7);

    Primitive *accelerator = new BVHAccel(primitives);

    //create film
	Film * film = new Image(width, height, filename);

    //create camera
    Transform cam2world = Transform::CreateLookAt(Point(278.0f, 273.0f, -800.0f ), Point(278.0f, 273.0f, -799.0f), Vec3(0.0f, 1.0f, 0.0f)).GetInverse();

    float aspectratio =float(film->GetWidth())/float(film->GetHeight());
    float screenWindow[4];
    if (aspectratio > 1.f)
    {
        screenWindow[0] = -aspectratio;
        screenWindow[1] =  aspectratio;
        screenWindow[2] = -1.f;
        screenWindow[3] =  1.f;
    }
    else
    {
        screenWindow[0] = -1.f;
        screenWindow[1] =  1.f;
        screenWindow[2] = -1.f / aspectratio;
        screenWindow[3] =  1.f / aspectratio;
    }
	float fov = 39.3077 * 1.0;
    PerspectiveCamera *camera = new PerspectiveCamera(cam2world, screenWindow, fov, film);

    //integrator
    VolumeIntegrator* volume_integrator = nullPtr;
//    SurfaceIntegrator* surface_integrator =  new AmbientOcclusion(10, 10.0f);
//	SurfaceIntegrator* surface_integrator = new DirectLighting(dls);
	SurfaceIntegrator* surface_integrator = new PathTracing(dls);

    //renderer
    Renderer * renderer = new Sampler(surface_integrator, volume_integrator, samples);

    //scene
    Scene* scene = new Scene(accelerator, lights, camera);

    renderer->Render(scene);

    film->WriteImage();
}

void mitsuba_veach_mis(int samples, std::string filename, int width, int height, DirectLightingStrategy dls, int light_samples_count)
{
    //primitives list
    vector<Reference<Primitive>> primitives;

    //geometric primitives list
    vector<GeometricPrimitive*> geometric_primitives;

    //lights list
    vector<Light*> lights;

    Transform t1a= Transform();
    Transform t1b= t1a.GetInverse();

    ObjMeshLoader obj_loader;

    //floor
    obj_loader.Parse("scenes/mitsuba_veach_mis/floor.obj");
    Reference<Shape> floor = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size() / 3, (int)obj_loader.m_Points.size(),
            obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0]:0,
            obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
            obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
            0,
            obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m1 = new DiffuseMaterial(Spectrum(Vec3(0.4f, 0.4f, 0.4f)));
    Primitive *g1= new GeometricPrimitive(floor, m1, NULL);
    if (!g1->CanIntersect())
    {
        vector<Reference<Primitive> > refinedPrimitives;
        g1->FullyRefine(refinedPrimitives);
        g1 = new DummyAccelerator(refinedPrimitives);
    }

    //plate1
    obj_loader.Parse("scenes/mitsuba_veach_mis/plate1.obj");
    Reference<Shape> plate1 = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size()/3, (int)obj_loader.m_Points.size(),
            obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
            obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
            obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
            0,
            obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m2 = new PhongMaterial(Spectrum(Vec3(0.07f, 0.09f, 0.13f)), 1000.0f);
    Primitive *g2 = new GeometricPrimitive(plate1, m2, NULL);
    if (!g2->CanIntersect())
    {
        vector<Reference<Primitive> > refinedPrimitives;
        g2->FullyRefine(refinedPrimitives);
        g2 = new DummyAccelerator(refinedPrimitives);
    }


    //plate2
    obj_loader.Parse("scenes/mitsuba_veach_mis/plate2.obj");
    Reference<Shape> plate2 = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size()/3, (int)obj_loader.m_Points.size(),
            obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
            obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
            obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
            0,
            obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m3 = new PhongMaterial(Spectrum(Vec3(0.07f, 0.09f, 0.13f)), 300.0f);
    Primitive* g3 = new GeometricPrimitive(plate2, m3, NULL);
    if (!g3->CanIntersect())
    {
        vector<Reference<Primitive> > refinedPrimitives;
        g3->FullyRefine(refinedPrimitives);
        g3 = new DummyAccelerator(refinedPrimitives);
    }


    //plate3
    obj_loader.Parse("scenes/mitsuba_veach_mis/plate3.obj");
    Reference<Shape> plate3 = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size()/3, (int)obj_loader.m_Points.size(),
            obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
            obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
            obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
            0,
            obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m4 = new PhongMaterial(Spectrum(Vec3(0.07f, 0.09f, 0.13f)), 200.0f);
    Primitive* g4 = new GeometricPrimitive(plate3, m4, NULL);
    if (!g4->CanIntersect())
    {
        vector<Reference<Primitive> > refinedPrimitives;
        g4->FullyRefine(refinedPrimitives);
        g4 = new DummyAccelerator(refinedPrimitives);
    }


    //plate4  front
    obj_loader.Parse("scenes/mitsuba_veach_mis/plate4.obj");
    Reference<Shape> plate4 = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size()/3, (int)obj_loader.m_Points.size(),
            obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
            obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
            obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
            0,
            obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m5 = new PhongMaterial(Spectrum(Vec3(0.07f, 0.09f, 0.13f)), 50.0f);
    Primitive* g5 = new GeometricPrimitive(plate4, m5, NULL);
    if (!g5->CanIntersect())
    {
        vector<Reference<Primitive> > refinedPrimitives;
        g5->FullyRefine(refinedPrimitives);
        g5 = new DummyAccelerator(refinedPrimitives);
    }


	Transform t9a = Transform::CreateTranslate(10, 10, 10);
	Transform t9b = t9a.GetInverse();
	Reference<Shape> s9 = Reference<Shape>(new Sphere(&t9a, &t9b, false, 0.5f));
	Material *m9 = new DiffuseMaterial(Spectrum(0.0));
	Spectrum a1l = Spectrum(Vec3(800, 800, 800));
	DiffuseAreaLight * a1 = new DiffuseAreaLight(t9a, a1l, light_samples_count, s9);
	GeometricPrimitive* g9 = new GeometricPrimitive(s9, m9, a1);
	primitives.push_back(g9);
	lights.push_back(a1);

	Transform t11a = Transform::CreateTranslate(-3.75f, 0.0f, 0.0f);
	Transform t11b = t11a.GetInverse();
	Reference<Shape> s11 = Reference<Shape>(new Sphere(&t11a, &t11b, false, 0.03333f));
	Material *m11 = new DiffuseMaterial(Spectrum(0.0f));
	Spectrum a3l = Spectrum(Vec3(901.803, 901.803 ,901.803));
	DiffuseAreaLight * a3 = new DiffuseAreaLight(t11a, a3l, light_samples_count, s11);
	GeometricPrimitive* g11 = new GeometricPrimitive(s11, m11, a3);
	primitives.push_back(g11);
	lights.push_back(a3);

	Transform t10a = Transform::CreateTranslate(-1.25f, 0.0f, 0.0f);
	Transform t10b = t10a.GetInverse();
	Reference<Shape> s10 = Reference<Shape>(new Sphere(&t10a, &t10b, false, 0.1f));
	Material *m10 = new DiffuseMaterial(Spectrum(0.0f));
	Spectrum a2l = Spectrum(Vec3(100, 100, 100));
	DiffuseAreaLight * a2 = new DiffuseAreaLight(t10a, a2l, light_samples_count, s10);
	GeometricPrimitive* g10 = new GeometricPrimitive(s10, m10, a2);
	primitives.push_back(g10);
	lights.push_back(a2);

	Transform t12a = Transform::CreateTranslate(1.25f, 0.0f, 0.0f);
	Transform t12b = t12a.GetInverse();
	Reference<Shape> s12 = Reference<Shape>(new Sphere(&t12a, &t12b, false, 0.3f));
	Material *m12 = new DiffuseMaterial(Spectrum(0.0f));
	Spectrum a4l = Spectrum(Vec3(11.1111, 11.1111 ,11.1111));
	DiffuseAreaLight * a4 = new DiffuseAreaLight(t12a, a4l, light_samples_count, s12);
	GeometricPrimitive* g12 = new GeometricPrimitive(s12, m12, a4);
	primitives.push_back(g12);
	lights.push_back(a4);

	Transform t13a = Transform::CreateTranslate(3.75f, 0.0f, 0.0f);
	Transform t13b = t13a.GetInverse();
	Reference<Shape> s13 = Reference<Shape>(new Sphere(&t13a, &t13b, false, 0.9f));
	Material *m13 = new DiffuseMaterial(Spectrum(0.0f));
	Spectrum a5l = Spectrum(Vec3(1.23457, 1.23457, 1.23457));
	DiffuseAreaLight * a5 = new DiffuseAreaLight(t13a, a5l, light_samples_count, s13);
	GeometricPrimitive* g13 = new GeometricPrimitive(s13, m13, a5);
	primitives.push_back(g13);
	lights.push_back(a5);
 

    //Accelerator
    primitives.push_back(g1);
	primitives.push_back(g2);
    primitives.push_back(g3);
    primitives.push_back(g4);
    primitives.push_back(g5);

    Primitive *accelerator = new BVHAccel(primitives);

    //create film
	Film * film = new Image(width, height, filename);

    //create camera
	Transform cam2world = Transform::CreateLookAt(Point(0.0f, 2.0f, 15.0f), Point(0.0f, -2.0f, 2.5f), Vec3(0.0f, 1.0f, 0.0f)).GetInverse();

    float aspectratio =float(film->GetWidth())/float(film->GetHeight());
    float screenWindow[4];
    if (aspectratio > 1.f)
    {
        screenWindow[0] = -aspectratio;
        screenWindow[1] =  aspectratio;
        screenWindow[2] = -1.f;
        screenWindow[3] =  1.f;
    }
    else
    {
        screenWindow[0] = -1.f;
        screenWindow[1] =  1.f;
        screenWindow[2] = -1.f / aspectratio;
        screenWindow[3] =  1.f / aspectratio;
    }
    float fov = 28.0f;
    PerspectiveCamera *camera = new PerspectiveCamera(cam2world, screenWindow, fov, film);

    //integrator
    VolumeIntegrator* volume_integrator = nullPtr;
//    SurfaceIntegrator* surface_integrator =  new AmbientOcclusion(10, 10.0f);
	SurfaceIntegrator* surface_integrator = new DirectLighting(dls);

    //renderer
    Renderer * renderer = new Sampler(surface_integrator, volume_integrator, samples);

    //scene
    Scene* scene = new Scene(accelerator, lights, camera);

    renderer->Render(scene);

    film->WriteImage();
}


void javascript_cbox(int samples, std::string filename, int width, int height, DirectLightingStrategy dls)
{
	//primitives list
	vector<Reference<Primitive>> primitives;

	//lights list
	vector<Light*> lights;

	Transform t1a = Transform::CreateTranslate(0.0f, -0.5f, 0.0f);
	Transform t1b = t1a.GetInverse();

	ObjMeshLoader obj_loader;

	//floor
	obj_loader.Parse("scenes/javascript_cbox/meshes/cbox_floor.obj");
	Reference<Shape> floor = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size() / 3, (int)obj_loader.m_Points.size(),
		obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
		obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
		obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
		0,
		obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m1 = new DiffuseMaterial(Spectrum(Vec3(0.75f, 0.75f, 0.75f)));
	Primitive *g1 = new GeometricPrimitive(floor, m1, NULL);
	if (!g1->CanIntersect())
	{
		vector<Reference<Primitive> > refinedPrimitives;
		g1->FullyRefine(refinedPrimitives);
		g1 = new DummyAccelerator(refinedPrimitives);
	}


	//ceiling
	obj_loader.Parse("scenes/javascript_cbox/meshes/cbox_ceiling.obj");
	Reference<Shape> ceiling = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size() / 3, (int)obj_loader.m_Points.size(),
		obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
		obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
		obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
		0,
		obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m2 = new DiffuseMaterial(Spectrum(Vec3(0.75f, 0.75f, 0.75f)));
	Primitive *g2 = new GeometricPrimitive(ceiling, m2, NULL);
	if (!g2->CanIntersect())
	{
		vector<Reference<Primitive> > refinedPrimitives;
		g2->FullyRefine(refinedPrimitives);
		g2 = new DummyAccelerator(refinedPrimitives);
	}


	//back
	obj_loader.Parse("scenes/javascript_cbox/meshes/cbox_back.obj");
	Reference<Shape> back = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size() / 3, (int)obj_loader.m_Points.size(),
		obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
		obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
		obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
		0,
		obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m3 = new DiffuseMaterial(Spectrum(Vec3(0.75f, 0.75f, 0.75f)));
	Primitive* g3 = new GeometricPrimitive(back, m3, NULL);
	if (!g3->CanIntersect())
	{
		vector<Reference<Primitive> > refinedPrimitives;
		g3->FullyRefine(refinedPrimitives);
		g3 = new DummyAccelerator(refinedPrimitives);
	}

	//blue
	obj_loader.Parse("scenes/javascript_cbox/meshes/cbox_greenwall.obj");
	Reference<Shape> greenwall = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size() / 3, (int)obj_loader.m_Points.size(),
		obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
		obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
		obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
		0,
		obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m4 = new DiffuseMaterial(Spectrum(Vec3(0.25f, 0.25f, 0.75f)));
	Primitive* g4 = new GeometricPrimitive(greenwall, m4, NULL);
	if (!g4->CanIntersect())
	{
		vector<Reference<Primitive> > refinedPrimitives;
		g4->FullyRefine(refinedPrimitives);
		g4 = new DummyAccelerator(refinedPrimitives);
	}

	//redwall
	obj_loader.Parse("scenes/javascript_cbox/meshes/cbox_redwall.obj");
	Reference<Shape> redwall = Reference<Shape>(new TriangleMesh(&t1a, &t1b, false, (int)obj_loader.m_VertexIndex.size() / 3, (int)obj_loader.m_Points.size(),
		obj_loader.m_VertexIndex.size()>0 ? &obj_loader.m_VertexIndex[0] : 0,
		obj_loader.m_Points.size()>0 ? &obj_loader.m_Points[0] : NULL,
		obj_loader.m_Normals.size()>0 ? &obj_loader.m_Normals[0] : NULL,
		0,
		obj_loader.m_uvs.size()>0 ? &obj_loader.m_uvs[0] : NULL));
	Material *m5 = new DiffuseMaterial(Spectrum(Vec3(0.75f, 0.25f, 0.25f)));
	Primitive* g5 = new GeometricPrimitive(redwall, m5, NULL);
	if (!g5->CanIntersect())
	{
		vector<Reference<Primitive> > refinedPrimitives;
		g5->FullyRefine(refinedPrimitives);
		g5 = new DummyAccelerator(refinedPrimitives);
	}

	//ball
	Transform s1a = Transform::CreateTranslate(135.0, 100.0, 315.5);
	Transform s1b = s1a.GetInverse();
	Reference<Shape> largebox = Reference<Shape>(new Sphere(&s1a, &s1b, false, 100.0f));
	Material *m6 = new DiffuseMaterial(Spectrum(Vec3(1.0f, 1.0f, 1.0f)));
	Primitive* g6 = new GeometricPrimitive(largebox, m6, NULL);
	if (!g6->CanIntersect())
	{
		vector<Reference<Primitive> > refinedPrimitives;
		g6->FullyRefine(refinedPrimitives);
		g6 = new DummyAccelerator(refinedPrimitives);
	}

	//ball
	Transform s2a = Transform::CreateTranslate(420.0, 100.0, 415.5);
	Transform s2b = s2a.GetInverse();
	Reference<Shape> smallbox = Reference<Shape>(new Sphere(&s2a, &s2b, false, 100.0f));
	Material *m7 = new DiffuseMaterial(Spectrum(Vec3(1.0f, 1.0f, 1.0f)));
	Primitive* g7 = new GeometricPrimitive(smallbox, m7, NULL);
	if (!g7->CanIntersect())
	{
		vector<Reference<Primitive> > refinedPrimitives;
		g7->FullyRefine(refinedPrimitives);
		g7 = new DummyAccelerator(refinedPrimitives);
	}

	//light
	Transform t9a = Transform::CreateTranslate(278.0, 930.0, 270.5);
	Transform t9b = t9a.GetInverse();
	Reference<Shape> s9 = Reference<Shape>(new Sphere(&t9a, &t9b, false, 400.0));
	Material *m9 = new DiffuseMaterial(Spectrum(0.0));
	Spectrum a1l = Spectrum(12.0);
	DiffuseAreaLight * al = new DiffuseAreaLight(t9a, a1l, 1, s9);
	GeometricPrimitive* g9 = new GeometricPrimitive(s9, m9, al);
	lights.push_back(al);
	primitives.push_back(g9);

	//Accelerator

	primitives.push_back(g1);
	
	primitives.push_back(g2);
	
	primitives.push_back(g3);
	
	primitives.push_back(g4);

	primitives.push_back(g5);	

	primitives.push_back(g6);
	primitives.push_back(g7);
	
	Primitive *accelerator = new BVHAccel(primitives);

	//create film
	Film * film = new Image(width, height, filename);

	//create camera
	Transform cam2world = Transform::CreateLookAt(Point(278.0f, 273.0f, -480), Point(278.0f, 273.0f, -0.0f), Vec3(0.0f, 1.0f, 0.0f)).GetInverse();

	float aspectratio = float(film->GetWidth()) / float(film->GetHeight());
	float screenWindow[4];
	if (aspectratio > 1.f)
	{
		screenWindow[0] = -aspectratio;
		screenWindow[1] = aspectratio;
		screenWindow[2] = -1.f;
		screenWindow[3] = 1.f;
	}
	else
	{
		screenWindow[0] = -1.f;
		screenWindow[1] = 1.f;
		screenWindow[2] = -1.f / aspectratio;
		screenWindow[3] = 1.f / aspectratio;
	}
	float fov = 55;
	PerspectiveCamera *camera = new PerspectiveCamera(cam2world, screenWindow, fov, film);

	//integrator
	VolumeIntegrator* volume_integrator = nullPtr;
	//    SurfaceIntegrator* surface_integrator =  new AmbientOcclusion(10, 10.0f);
	//SurfaceIntegrator* surface_integrator = new DirectLighting(dls);
	SurfaceIntegrator* surface_integrator = new PathTracing(dls);

	//renderer
	Renderer * renderer = new Sampler(surface_integrator, volume_integrator, samples);

	//scene
	Scene* scene = new Scene(accelerator, lights, camera);

	renderer->Render(scene);

	film->WriteImage();
}



int main()
{
	/*
#ifdef _DEBUG
	int flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	flag |= _CRTDBG_LEAK_CHECK_DF; // Turn on leak-checking bit
	_CrtSetDbgFlag(flag);
	_CrtSetBreakAlloc(2035483);
	#endif*/
	//	task01();
	//	task02();
	//	task03();
	//	task04();

	//	tp1_4();

	//	tp1_5(2, "uniform_direct_lighting_2_samples_1024x768.tga");



//	javascript_cbox(50, "pathtracing.tga", 512, 384, DIRECT_LIGHTING_MIS);

	monkey_mesh_light(30, "monkey.tga", 512 / 4, 384 / 4, DIRECT_LIGHTING_LIGHT_ONLY, 1);


//	jensen_cbox(1, "jensen_l.tga", 512, 384, DIRECT_LIGHTING_LIGHT_ONLY);
//	jensen_cbox(15, "jensen_b.tga", 512, 384, DIRECT_LIGHTING_BRDF_ONLY);
//	jensen_cbox(15, "jensen_mis.tga", 512, 384, DIRECT_LIGHTING_MIS);
	/*
	mitsuba_cbox(512, "mitsuba_l.tga", 512, 384, DIRECT_LIGHTING_LIGHT_ONLY);
	mitsuba_cbox(512, "mitsuba_b.tga", 512, 384, DIRECT_LIGHTING_BRDF_ONLY);
	mitsuba_cbox(512, "mitsuba_mis.tga", 512, 384, DIRECT_LIGHTING_MIS);
	*/
//	mitsuba_veach_mis(50, "veach_l.tga", 512, 384, DIRECT_LIGHTING_LIGHT_ONLY);
//	mitsuba_veach_mis(50, "veach_b.tga", 512, 384, DIRECT_LIGHTING_BRDF_ONLY);
//	mitsuba_veach_mis(1, "veach_m.tga", 512, 384, DIRECT_LIGHTING_BRDF_ONLY, 2);
	
}
