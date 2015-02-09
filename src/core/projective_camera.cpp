#include <rendermoon.h>


ProjectiveCamera::ProjectiveCamera(const Transform &cam2world, const Transform &proj, const float screenWindow[4], Film *film) : Camera(cam2world, film)
{
    // Compute projective camera transformations
    m_CameraToScreen = proj;

    // Compute projective camera screen transformations
    m_ScreenToRaster =
			Transform::CreateScale((float)m_film->GetWidth(), (float)m_film->GetHeight(), 1.0f) *
			Transform::CreateScale(1.0f / (screenWindow[1] - screenWindow[0]), 1.0f / (screenWindow[2] - screenWindow[3]), 1.0f) *
			Transform::CreateTranslate(Vec3(-screenWindow[0], -screenWindow[3], 0.0f));

    m_RasterToScreen = m_ScreenToRaster.GetInverse();
    m_RasterToCamera = m_CameraToScreen.GetInverse() * m_RasterToScreen;
}
