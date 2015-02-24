#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_SHAPESET__
#define __RENDERMOON_CORE_SHAPESET__

#include <core/memory.h>
class Shape;
struct Distribution1D;

class ShapeSet
{
public:
    // ShapeSet Public Methods
    ShapeSet(const Reference<Shape> &s);
    float Area() const;
    ~ShapeSet();
    Point Sample(const Point &p, float u1, float u2, Normal *Ns) const;
    Point Sample(Normal *Ns, float u1, float u2) const;
    float Pdf(const Point &p, const Vec3 &wi) const;
    float Pdf(const Point &p) const;
private:
    // ShapeSet Private Data
    vector<Reference<Shape> > shapes;
    float sumArea;
    vector<float> areas;
    Distribution1D *areaDistribution;
};

#endif
