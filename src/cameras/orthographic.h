#if defined(_MSC_VER)
#pragma once
#endif


#ifndef __RENDERMOON_CAMERA__ORTHOGRAPHIC__
#define __RENDERMOON_CAMERA__ORTHOGRAPHIC__

#include <core/projective_camera.h>

class AnimatedTransform;
class Film;

class OrthographicCamera : public ProjectiveCamera
{
public:
    OrthographicCamera(const Transform &cam2world, const float screenWindow[4], Film *film);
    float GenerateRay(const CameraSample &sample, Ray *) const;

//	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

private:
    Vec3 dxCamera, dyCamera;
};

#endif
