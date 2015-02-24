#ifndef __RAYMOON_HEADER__
#define __RAYMOON_HEADER__

#if defined(_MSC_VER)
#pragma message("Compiling precompiled headers.")
#endif

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


#ifndef PBRT_L1_CACHE_LINE_SIZE
#define PBRT_L1_CACHE_LINE_SIZE 64
#endif

#ifdef M_PI
#undef M_PI
#endif
#define M_PI       3.14159265358979323846f
#define INV_PI     0.31830988618379067154f
#define INV_TWOPI  0.15915494309189533577f
#define INV_FOURPI 0.07957747154594766788f


#if defined(_WIN32) || defined(_WIN64)
#define PBRT_IS_WINDOWS
#elif defined(__linux__)
#define PBRT_IS_LINUX
#elif defined(__APPLE__)
  #define PBRT_IS_APPLE
  #if !(defined(__i386__) || defined(__amd64__))
  #define PBRT_IS_APPLE_PPC
  #else
  #define PBRT_IS_APPLE_X86
  #endif
#elif defined(__OpenBSD__)
#define PBRT_IS_OPENBSD
#endif

// Platform-specific definitions
#if defined(PBRT_IS_WINDOWS)
#include <float.h>
//#define isnan _isnan
//#define isinf(f) (!_finite((f)))
#if _MSC_VER >= 1600
#include <stdint.h>
#else
typedef signed __int8 int8_t;
typedef unsigned __int8 uint8_t;
typedef signed __int16 int16_t;
typedef unsigned __int16 uint16_t;
typedef signed __int32 int32_t;
typedef unsigned __int32 uint32_t;
typedef signed __int64 int64_t;
typedef unsigned __int64 uint64_t;
#endif // _MSC_VER >= 1600
#pragma warning (disable : 4305) // double constant assigned to float
#pragma warning (disable : 4244) // int -> float conversion
#pragma warning (disable : 4267) // size_t -> unsigned int conversion
#endif

#if defined(PBRT_IS_LINUX) || defined(PBRT_IS_APPLE)
#include <stdint.h>
#endif // PBRT_IS_LINUX || PBRT_IS_APPLE
#if defined(PBRT_IS_WINDOWS)
//#define isnan _isnan
//#define isinf(f) (!_finite((f)))
#endif

#include <iostream>
#include <list>
#include <limits>
#include <algorithm>    // std::swap
#include <string.h> //memcpy
#include <stdlib.h> //realloc
#include <stdio.h> //file open..

//#define rm_infintiy numeric_limits<float>::infinity( )

static unsigned int g_seed=98156273;

inline float GetRandom()
{
	float r;
	do
	{
		g_seed = (214013*g_seed+25310011);
		r = float((g_seed>>16)&0x7fff)/float(0x7fff);
//		r = (float)rand() / RAND_MAX;
	} while (r == 1.0f);
	return r;
}

#include <core/memory.h>
#include <core/parallel.h>
#include <core/paramset.h>
#include <core/paramset_item.h>
#include <core/math.h>
#include <core/ray.h>
#include <core/transform.h>
#include <core/bbox.h>
#include <core/area_light.h>

#include <core/aggregate.h>

#include <core/scene.h>

#include <core/bxdf.h>
#include <core/bsdf.h>

#include <core/differential_geometry.h>

#include <core/lambertian_bxdf.h>
#include <core/specular_reflection_bxdf.h>
#include <core/glossy_reflection_bxdf.h>

#include <core/integrator.h>
#include <core/surface_integrator.h>
#include <core/volume_integrator.h>
#include <core/spectrum.h>
#include <core/material.h>
#include <core/light.h>

#include <core/shape.h>
#include <core/geometric_primitive.h>
#include <core/transformed_primitive.h>
#include <core/monte_carlo.h>
#include <core/primitive.h>

#include <core/renderer.h>
#include <core/camera.h>
#include <core/projective_camera.h>
#include <core/accelerator.h>
#include <core/filter.h>
#include <core/film.h>
#include <core/animated_transform.h>
#include <core/intersection.h>
#include <core/visibility_tester.h>
#include <core/shape_set.h>
#include <core/distribution1D.h>


#include <cameras/orthographic.h>
#include <cameras/perspective.h>
#include <lights/diffuse_area.h>
#include <lights/point.h>
#include <lights/directional.h>
#include <shapes/sphere.h>
#include <shapes/trianglemesh.h>
#include <film/image.h>
#include <accelerator/dummy_accelerator.h>
#include <accelerator/bvh.h>
#include <renderer/sampler.h>

#include <integrators/direct_lighting.h>
#include <integrators/ambient_occlusion.h>
#include <integrators/pathtracing.h>

#include <materials/diffuse.h>
#include <materials/phong.h>
#include <materials/mirror.h>

#include <parser/obj_mesh.h>

#endif