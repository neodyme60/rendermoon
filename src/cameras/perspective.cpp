#include <rendermoon.h>

PerspectiveCamera:: PerspectiveCamera(const Transform &cam2world, const float screenWindow[4], float fov, Film *f)
        : ProjectiveCamera(cam2world, Transform::CreatePerspective(fov, 1e-2f, 1000.f), screenWindow, f)
{
    // Compute differential changes in origin for perspective camera rays
    dxCamera = m_RasterToCamera.TransformPoint(Point(1.0f, 0.0f, 0.0f)) - m_RasterToCamera.TransformPoint(Point(0.0f, 0.0f, 0.0f));
    dyCamera = m_RasterToCamera.TransformPoint(Point(0.0f, 1.0f, 0.0f)) - m_RasterToCamera.TransformPoint(Point(0.0f, 0.0f, 0.0f));
}

float PerspectiveCamera::GenerateRay(const CameraSample &sample, Ray *ray) const
{
    // Generate raster and camera samples
    Point Pras(sample.imageX, sample.imageY, 0);
    Point Pcamera;
    m_RasterToCamera.TransformPoint(Pras, &Pcamera);

//	Pcamera.x=0;
	//Pcamera.y=0;

    *ray = Ray(Point(0.0f, 0.0f, 0.0f), Normalize(Vec3(Pcamera.x, Pcamera.y, Pcamera.z)), 0.1f, max_inf);

    ray->SetTime(sample.time);
    m_CameraToWorld.TransformRay(*ray, ray);
    return 1.0f;
}
