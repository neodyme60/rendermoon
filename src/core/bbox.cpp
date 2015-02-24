#include <rendermoon.h>


bool BBox::operator==(const BBox &b) const
{
    return b.pMin == pMin && b.pMax == pMax;
}

bool BBox::operator!=(const BBox &b) const
{
    return b.pMin != pMin || b.pMax != pMax;
}

bool BBox::Overlaps(const BBox &b) const
{
    bool x = (pMax.x >= b.pMin.x) && (pMin.x <= b.pMax.x);
    bool y = (pMax.y >= b.pMin.y) && (pMin.y <= b.pMax.y);
    bool z = (pMax.z >= b.pMin.z) && (pMin.z <= b.pMax.z);
    return (x && y && z);
}

bool BBox::Inside(const Point &pt) const
{
    return (pt.x >= pMin.x && pt.x <= pMax.x &&
            pt.y >= pMin.y && pt.y <= pMax.y &&
            pt.z >= pMin.z && pt.z <= pMax.z);
}


const Point &BBox::operator[](int i) const
{
//    Assert(i == 0 || i == 1);
    return (&pMin)[i];
}


Point &BBox::operator[](int i)
{
//    Assert(i == 0 || i == 1);
    return (&pMin)[i];
}


void BBox::Expand(float delta)
{
    pMin -= Vec3(delta, delta, delta);
    pMax += Vec3(delta, delta, delta);
}

float BBox::SurfaceArea() const
{
    Vec3 d = pMax - pMin;
    return 2.0f * (d.x * d.y + d.x * d.z + d.y * d.z);
}

float BBox::Volume() const
{
    Vec3 d = pMax - pMin;
    return d.x * d.y * d.z;
}

int BBox::MaximumExtent() const
{
    Vec3 diag = pMax - pMin;
    if (diag.x > diag.y && diag.x > diag.z)
        return 0;
    else if (diag.y > diag.z)
        return 1;
    else
        return 2;
}

BBox::BBox()
{
    pMin = Point(INFINITY, INFINITY, INFINITY);
    pMax = Point(-INFINITY, -INFINITY, -INFINITY);
}

BBox::BBox(const Point &p) : pMin(p), pMax(p) { }

BBox::BBox(const Point &p1, const Point &p2)
{
    pMin = Point(min(p1.x, p2.x), min(p1.y, p2.y), min(p1.z, p2.z));
    pMax = Point(max(p1.x, p2.x), max(p1.y, p2.y), max(p1.z, p2.z));
}
