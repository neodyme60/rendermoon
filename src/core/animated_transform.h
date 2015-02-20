#if defined(_MSC_VER)
#pragma once
#endif


#ifndef __RENDERMOON_ANIMATED_TRANSFORM__
#define __RENDERMOON_ANIMATED_TRANSFORM__

class Transform;
class Point;
class Vec3;
class Ray;

class AnimatedTransform
{
public:
    AnimatedTransform(const Transform transform1, float time1, const Transform transform2, float time2)
            : startTime(time1), endTime(time2), startTransform(transform1), endTransform(transform2)
    {}
    virtual ~AnimatedTransform() {}
/*
    void operator()(const Ray &r, Ray *tr) const;
    Point operator()(float time, const Point &p) const;
    Vec3 operator()(float time, const Vec3 &v) const;
    Ray operator()(const Ray &r) const;
*/
//    const bool actuallyAnimated;
    float startTime, endTime;
    Transform startTransform, endTransform;
};

#endif
