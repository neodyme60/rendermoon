#include <iostream>
#include <rendermoon.h>
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
void tp1_5(int samples, std::string filename)
{
	//primitives list
    std::list<Primitive*> primitives;

	//lights list
    std::list<Light*> lights;

	//
	//
	//shape 1
	//
	//Sphere(1e5, Vec( 1e5+1,40.8,81.6), Vec(),Vec(.75,.25,.25),DIFF),//Left
	Transform t1a= Transform::CreateTranslate(1e5+99,40.8f,81.6f);
	Transform t1b= t1a.GetInverse();
	Shape *s1 = new Sphere(&t1a, &t1b, 1e5f);
	Material *m1 = new DiffuseMaterial(Vec3(0.75f,0.25f,0.25f));
	GeometricPrimitive *g1= new GeometricPrimitive(s1, m1, 0);

	//
	//shape 2
	//
//	   Sphere(1e5, Vec(-1e5+99,40.8,81.6),Vec(),Vec(.25,.25,.75),DIFF),//Rght 
	Transform t2a= Transform::CreateTranslate(-1e5f-1.0f, 40.8f, 81.6f);
	Transform t2b= t2a.GetInverse();
	Shape *s2 = new Sphere(&t2a, &t2b, 1e5);
	Material *m2 = new DiffuseMaterial(Vec3(0.25f,0.25f,0.75f));
	GeometricPrimitive *g2= new GeometricPrimitive(s2, m2, 0);

	//
	//shape 3
	//
	//   Sphere(1e5, Vec(50,40.8, 1e5),     Vec(),Vec(.75,.75,.75),DIFF),//Back 
	Transform t3a= Transform::CreateTranslate(50.0f,40.8f, 1e5);
	Transform t3b= t3a.GetInverse();
	Shape *s3 = new Sphere(&t3a, &t3b, 1e5f);
	Material *m3 = new DiffuseMaterial(Vec3(0.75f,0.75f,0.75f));
	GeometricPrimitive* g3 = new GeometricPrimitive(s3, m3, 0);

	//
	//shape 4
	//
//	Sphere(1e5, Vec(50,40.8,-1e5+170), Vec(),Vec(),           DIFF),//Frnt 
	Transform t4a= Transform::CreateTranslate(50.0f,40.8f,-1e5+120);
	Transform t4b= t4a.GetInverse();
	Shape *s4 = new Sphere(&t4a, &t4b, 1e5f);
	Material *m4 = new DiffuseMaterial(Vec3(1.0f,1.0f,1.0f));
	GeometricPrimitive* g4 = new GeometricPrimitive(s4, m4, 0);
		   
	//
	//shape 5
	//
//		   Sphere(1e5, Vec(50, 1e5, 81.6),    Vec(),Vec(.75,.75,.75),DIFF),//Botm 
	Transform t5a= Transform::CreateTranslate(50, -1e5, 0);
	Transform t5b= t5a.GetInverse();
	Shape *s5 = new Sphere(&t5a, &t5b, 1e5f);
	Material *m5 = new DiffuseMaterial(Vec3(0.75f,0.75f,0.75f));
	GeometricPrimitive* g5 = new GeometricPrimitive(s5, m5, 0);
	//
	//shape 6
	//
//	Sphere(1e5, Vec(50,-1e5+81.6,81.6),Vec(),Vec(.75,.75,.75),DIFF),//Top 
	Transform t6a= Transform::CreateTranslate(50.0f, 1e5f+81.6f, 90.6f);
	Transform t6b= t6a.GetInverse();
	Shape *s6 = new Sphere(&t6a, &t6b, 1e5);
	Material *m6 = new DiffuseMaterial(Vec3(0.75f,0.75f,0.75f));
	GeometricPrimitive* g6 = new GeometricPrimitive(s6, m6, 0);

	//
	//shape 7
	//
//	Sphere(16.5,Vec(27,16.5,47),       Vec(),Vec(1,1,1)*.999, SPEC),//Mirr 
	Transform t7a= Transform::CreateTranslate(27.0f, 16.5f, 180.0f);
	Transform t7b= t7a.GetInverse();
	Shape *s7 = new Sphere(&t7a, &t7b, 16.5f);
	Material *m7 = new DiffuseMaterial(Vec3(1.0f,1.0f,1.0f));
	GeometricPrimitive* g7 = new GeometricPrimitive(s7, m7, 0);

	//
	//shape 8
	//
//	Sphere(16.5,Vec(73,16.5,78),       Vec(),Vec(1,1,1)*.999, REFR),//Glas 
	Transform t8a= Transform::CreateTranslate(73.0f, 16.5f, 150.0f);
	Transform t8b= t8a.GetInverse();
	Shape *s8 = new Sphere(&t8a, &t8b, 16.5f);
	Material *m8 = new DiffuseMaterial(Vec3(1.0f,1.0f,1.0f));
	GeometricPrimitive* g8 = new GeometricPrimitive(s8, m8, 0);

	//
	//shape 9 lite
	//
	Transform t9a= Transform::CreateTranslate(70.0f, 70.5f, 180.0f);
	Transform t9b= t9a.GetInverse();
	Shape *s9 = new Sphere(&t9a, &t9b, 2.0f);
	Material *m9 = new DiffuseMaterial(Vec3(M_PI*0.75f, M_PI*0.75f, M_PI)*70.0f);
    AreaLight * al = new AreaLight(t9a);
	GeometricPrimitive* g9 = new GeometricPrimitive(s9, m9, al);
	lights.push_back(al);
    primitives.push_back(g9);

	//Accelerator
	primitives.push_back(g1);
	primitives.push_back(g2);
//	primitives.push_back(g3);
	primitives.push_back(g4);
	primitives.push_back(g5);
	primitives.push_back(g6);
	primitives.push_back(g7);
	primitives.push_back(g8);
	primitives.push_back(g9);
    DummyAccelerator *accelerator = new DummyAccelerator(primitives);

    //create film
    Film * film = new Image(512, 384, filename);
	
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
    VolumeIntegrator* volume_integrator = nullPtr;
	SurfaceIntegrator* surface_integrator =  new DirectLighting();

    //renderer
    Renderer * renderer = new Sampler(surface_integrator, volume_integrator, samples);

    //scene
    Scene* scene = new Scene(accelerator, lights, camera);

    renderer->Render(scene);

	film->WriteImage();
}



int main()
{
//	task01();
//	task02();
//	task03();
//	task04();

//	tp1_4();
	tp1_5(2, "uniform_direct_lighting_2_samples_1024x768.tga");
}