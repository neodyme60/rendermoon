cmake_minimum_required (VERSION 2.6)
project(procedural)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/external)

set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)


set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

include_directories("src")
include_directories("external/eigen")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
                src/rendermoon.cpp
                src/main.cpp
                src/core/memory.cpp
                src/core/monte_carlo.cpp
                src/core/parallel.cpp
                src/core/math.cpp
                src/core/light.cpp
                src/core/differential_geometry.cpp
                src/core/filter.cpp
                src/core/bsdf.cpp
                src/core/bxdf.cpp
                src/core/lambertian_bxdf.cpp
                src/core/specular_reflection_bxdf.cpp
                src/core/glossy_reflection_bxdf.cpp
                src/core/accelerator.cpp
                src/core/ray.cpp
                src/core/renderer.cpp
                src/core/primitive.cpp
                src/core/scene.cpp
                src/core/camera.cpp
                src/core/projective_camera.cpp
                src/core/integrator.cpp
                src/core/film.cpp
                src/core/transform.cpp
                src/core/spectrum.cpp
                src/core/transformed_primitive.cpp
                src/core/intersection.cpp
                src/core/aggregate.cpp
                src/core/animated_transform.cpp
                src/core/area_light.cpp
                src/core/bbox.cpp
                src/core/geometric_primitive.cpp
                src/core/material.cpp
                src/core/shape.cpp
                src/core/volume_integrator.cpp
                src/core/surface_integrator.cpp
                src/core/paramset.cpp
                src/core/visibility_tester.cpp
                src/core/shape_set.cpp

                src/materials/diffuse.cpp
                src/materials/phong.cpp
                src/materials/mirror.cpp

                src/shapes/sphere.cpp
                src/shapes/trianglemesh.cpp

                src/lights/directional.cpp
                src/lights/point.cpp
                src/lights/infinite_area.cpp

                src/cameras/perspective.cpp
                src/cameras/orthographic.cpp

                src/film/image.cpp
                src/accelerator/dummy_accelerator.cpp
                src/accelerator/bvh.cpp
                src/renderer/sampler.cpp

                src/integrators/direct_lighting.cpp
                src/integrators/ambient_occlusion.cpp
                src/integrators/pathtracing.cpp

                src/lights/diffuse_area.cpp

                src/parser/obj_mesh.cpp
)

add_executable(procedural ${SOURCE_FILES})

