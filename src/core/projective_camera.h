#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_CAMERA_PROJECTIVE__
#define __RENDERMOON_CORE_CAMERA_PROJECTIVE__

#include <core/projective_camera.h>

class Film;
class Transform;

class ProjectiveCamera : public Camera
{
public:
    ProjectiveCamera(const Transform &cam2world, const Transform &proj, const float screenWindow[4], Film *film);

//	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

protected:

    // ProjectiveCamera Protected Data
    Transform m_CameraToScreen, m_RasterToCamera;
    Transform m_ScreenToRaster, m_RasterToScreen;
};

#endif
