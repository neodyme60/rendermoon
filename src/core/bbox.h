#if defined(_MSC_VER)
#pragma once
#endif


#ifndef __RENDERMOON_CORE_BBOX__
#define __RENDERMOON_CORE_BBOX__

class Point;
class Vec3;

class BBox 
{
public:
    BBox();
    BBox(const Point &p);
    BBox(const Point &p1, const Point &p2);

    friend BBox Union(const BBox &b, const Point &p);
    friend BBox Union(const BBox &b, const BBox &b2);
    bool Overlaps(const BBox &b) const;
    bool Inside(const Point &pt) const;
    void Expand(float delta);
    float SurfaceArea() const;
    float Volume() const;
    int MaximumExtent() const;
    const Point &operator[](int i) const;
    Point &operator[](int i);
/*
    Point Lerp(float tx, float ty, float tz) const 
	{
        return Point(::Lerp(tx, pMin.x, pMax.x), ::Lerp(ty, pMin.y, pMax.y), ::Lerp(tz, pMin.z, pMax.z));
    }

    Vec3 Offset(const Point &p) const {
        return Vec3((p.x - pMin.x) / (pMax.x - pMin.x),
                      (p.y - pMin.y) / (pMax.y - pMin.y),
                      (p.z - pMin.z) / (pMax.z - pMin.z));
    }
*/
    void BoundingSphere(Point *c, float *rad) const;
    bool IntersectP(const Ray &ray, float *hitt0 = NULL, float *hitt1 = NULL) const;

    bool operator==(const BBox &b) const;
    bool operator!=(const BBox &b) const;

    Point pMin, pMax;
};


#endif