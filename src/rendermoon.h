#ifndef __RAYMOON_HEADER__
#define __RAYMOON_HEADER__
/*
#include <Eigen/Geometry>
typedef Eigen::Matrix4f Mat4;
typedef Eigen::Matrix3f Mat3;
typedef Eigen::Vector2f Vec2;
typedef Eigen::Vector3f Vec3;
typedef Eigen::Vector4f Vec4;
typedef Eigen::Vector3f Point;
typedef Eigen::Vector3f Normal;
*/

using namespace std;

struct CameraSample
{
public:
    int imageX;
    int imageY;
    float time;
};

#define DEG2RAD 3.1416 / 180.0
#define max_inf 10e5

#ifndef nullPtr
#define nullPtr 0
#endif

#define isnan _isnan
#define isinf(f) (!_finite((f)))

#ifdef M_PI
#undef M_PI
#endif
#define M_PI       3.14159265358979323846f
#define INV_PI     0.31830988618379067154f
#define INV_TWOPI  0.15915494309189533577f
#define INV_FOURPI 0.07957747154594766788f

#include <iostream>
#include <list>
#include <limits>
#include <algorithm>    // std::swap
#include <string.h> //memcpy
#include <stdlib.h> //realloc
#include <stdio.h> //file open..

#define rm_infintiy numeric_limits<float>::infinity( )

inline float Clamp(float val, float low, float high) {
    if (val < low) return low;
    else if (val > high) return high;
    else return val;
}


inline int Clamp(int val, int low, int high) {
    if (val < low) return low;
    else if (val > high) return high;
    else return val;
}

inline float Radians(float deg) {
    return ((float)M_PI/180.f) * deg;
}


inline float Degrees(float rad) {
    return (180.f/(float)M_PI) * rad;
}


#include <core/math.h>
#include <core/ray.h>
#include <core/transform.h>
#include <core/bbox.h>
#include <core/area_light.h>


#include <core/scene.h>

#include <core/integrator.h>
#include <core/surface_integrator.h>
#include <core/volume_integrator.h>
#include <core/spectrum.h>
#include <core/material.h>
#include <core/light.h>

#include <core/shape.h>
#include <core/geometric_primitive.h>
#include <core/transformed_primitive.h>

#include <core/primitive.h>

#include <core/renderer.h>
#include <core/camera.h>
#include <core/projective_camera.h>
#include <core/accelerator.h>
#include <core/filter.h>
#include <core/film.h>
#include <core/animated_transform.h>
#include <core/intersection.h>

#include <cameras/orthographic.h>
#include <cameras/perspective.h>
#include <lights/diffuse.h>
#include <lights/point.h>
#include <lights/directional.h>
#include <shapes/sphere.h>
#include <film/image.h>
#include <accelerator/dummy_accelerator.h>
#include <renderer/sampler.h>
#include <integrators/direct_lighting.h>
#include <materials/diffuse.h>

#endif