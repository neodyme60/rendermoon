#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_VISIBILITY_TESTER__
#define __RENDERMOON_CORE_VISIBILITY_TESTER__

struct VisibilityTester
{
    void SetSegment(const Point &p1, float eps1, const Point &p2, float eps2, float time);
    void SetRay(const Point &p, float eps, const Vec3 &w, float time);
    bool Unoccluded(const Scene &scene) const;

//    Spectrum Transmittance(const Scene *scene, const Renderer *renderer, const Sample *sample, RNG &rng, MemoryArena &arena) const;
    Ray r;
};

#endif
