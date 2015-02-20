#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CAMERA__PERSPECTIVE__
#define __RENDERMOON_CAMERA__PERSPECTIVE__

#include <core/projective_camera.h>

class AnimatedTransform;

class PerspectiveCamera: public ProjectiveCamera
{
public:
    // PerspectiveCamera Public Methods
    PerspectiveCamera(const Transform &cam2world, const float screenWindow[4], float fov, Film *film);
    float GenerateRay(const CameraSample &sample, Ray *) const;

	//EIGEN_MAKE_ALIGNED_OPERATOR_NEW
private:
    // PerspectiveCamera Private Data
    Vec3 dxCamera, dyCamera;

};

#endif

