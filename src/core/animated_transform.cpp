#include <rendermoon.h>

/*
void AnimatedTransform::operator()(const Ray &r, Ray *tr) const
{
    if (!actuallyAnimated || r.time <= startTime)
        (*startTransform)(r, tr);
    else if (r.time >= endTime)
        (*endTransform)(r, tr);
    else {
        Transform t;
        Interpolate(r.time, &t);
        t(r, tr);
    }
    tr->time = r.time;
}

Point AnimatedTransform::operator()(float time, const Point &p) const
{
    if (!actuallyAnimated || time <= startTime)
        return (*startTransform)(p);
    else if (time >= endTime)
        return (*endTransform)(p);
    Transform t;
    Interpolate(time, &t);
    return t(p);
}

Vec3 AnimatedTransform::operator()(float time, const Vec3 &v) const
{
    if (!actuallyAnimated || time <= startTime)
        return (*startTransform)(v);
    else if (time >= endTime)
        return (*endTransform)(v);
    Transform t;
    Interpolate(time, &t);
    return t(v);
}


Ray AnimatedTransform::operator()(const Ray &r) const
{
    Ray ret;
    (*this)(r, &ret);
    return ret;
}*/