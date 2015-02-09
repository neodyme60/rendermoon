#include <rendermoon.h>

OrthographicCamera::OrthographicCamera(const Transform &cam2world, const float screenWindow[4], Film *film)
        : ProjectiveCamera(cam2world, Transform::CreateOrthographic(1e-2f, 1000.f), screenWindow, film)
{
    // Compute differential changes in origin for ortho camera rays
    dxCamera = Vec3(m_RasterToCamera.TransformPoint(Point(1, 0, 0)));
    dyCamera = Vec3(m_RasterToCamera.TransformPoint(Point(0, 1, 0)));
}

float OrthographicCamera::GenerateRay(const CameraSample &sample, Ray *ray) const
{
    // Generate raster and camera samples
    Point Pras(sample.imageX, sample.imageY, 0);
    Point Pcamera;
    m_RasterToCamera.TransformPoint(Pras, &Pcamera);
    *ray = Ray(Pcamera, Vec3(0,0,1), 0.f, max_inf);
    ray->SetTime(sample.time);
    m_CameraToWorld.TransformRay(*ray, ray);
    return 1.0f;
}
