#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_SHAPE_MESH__
#define __RENDERMOON_SHAPE_MESH__

#include <map>
using std::map;

class TriangleMesh : public Shape
{
public:
    TriangleMesh(const Transform *o2w, const Transform *w2o, bool ro, int ntris, int nverts, const int *vptr, const Point *P, const Normal *N, const Vec3 *S, const float *uv);
    ~TriangleMesh();
    BBox ObjectBound() const;
    BBox WorldBound() const;

    bool CanIntersect() const { return false; }
    void Refine(vector<Reference<Shape> > &refined) const;
    friend class Triangle;
protected:

    int ntris, nverts;
    int *vertexIndex;
    Point *p;
    Normal *n;
    Vec3 *s;
    float *uvs;
};


class Triangle : public Shape
{
public:
    Triangle(const Transform *o2w, const Transform *w2o, bool ro, TriangleMesh *m, int n);
    BBox ObjectBound() const;
    BBox WorldBound() const;
    bool GetIntersection(const Ray &ray, float *tHit, DifferentialGeometry& dg) const;
    bool IsIntersected(const Ray &ray) const;
    float Area() const;
    Point SampleUniform(float u1, float u2, Normal *Ns) const;
private:
    Reference<TriangleMesh> m_Mesh;
    int *v;
};

#endif
