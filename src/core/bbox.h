#ifndef __RENDERMOON_CORE_BBOX__
#define __RENDERMOON_CORE_BBOX__

class Point;
class Vec3;

class BBox 
{
public:
    BBox()
	{
        pMin = Point( rm_infintiy,  rm_infintiy,  rm_infintiy);
        pMax = Point(-rm_infintiy, -rm_infintiy, -rm_infintiy);
    }
    BBox(const Point &p) : pMin(p), pMax(p) { }
    BBox(const Point &p1, const Point &p2) 
	{
        pMin = Point(std::min(p1.x, p2.x), min(p1.y, p2.y), min(p1.z, p2.z));
        pMax = Point(std::max(p1.x, p2.x), max(p1.y, p2.y), max(p1.z, p2.z));
    }
    friend BBox Union(const BBox &b, const Point &p);
    friend BBox Union(const BBox &b, const BBox &b2);
    bool Overlaps(const BBox &b) const 
	{
        bool x = (pMax.x >= b.pMin.x) && (pMin.x <= b.pMax.x);
        bool y = (pMax.y >= b.pMin.y) && (pMin.y <= b.pMax.y);
        bool z = (pMax.z >= b.pMin.z) && (pMin.z <= b.pMax.z);
        return (x && y && z);
    }
    bool Inside(const Point &pt) const 
	{
        return (pt.x >= pMin.x && pt.x <= pMax.x &&
                pt.y >= pMin.y && pt.y <= pMax.y &&
                pt.z >= pMin.z && pt.z <= pMax.z);
    }
    void Expand(float delta) 
	{
        pMin -= Vec3(delta, delta, delta);
        pMax += Vec3(delta, delta, delta);
    }
    float SurfaceArea() const 
	{
        Vec3 d = pMax - pMin;
        return 2.0f * (d.x * d.y + d.x * d.z + d.y * d.z);
    }
    float Volume() const 
	{
        Vec3 d = pMax - pMin;
        return d.x * d.y * d.z;
    }
    int MaximumExtent() const 
	{
        Vec3 diag = pMax - pMin;
        if (diag.x > diag.y && diag.x > diag.z)
            return 0;
        else if (diag.y > diag.z)
            return 1;
        else
            return 2;
    }
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

    bool operator==(const BBox &b) const 
	{
        return b.pMin == pMin && b.pMax == pMax;
    }

    bool operator!=(const BBox &b) const 
	{
        return b.pMin != pMin || b.pMax != pMax;
    }

    Point pMin, pMax;
};


#endif