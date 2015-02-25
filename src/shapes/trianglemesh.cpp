#include <rendermoon.h>

TriangleMesh::TriangleMesh(const Transform *o2w, const Transform *w2o, bool ro, int nt, int nv, const int *vi, const Point *P, const Normal *N, const Vec3 *S, const float *uv) : Shape(o2w, w2o, ro)
{
    ntris = nt;
    nverts = nv;
    vertexIndex = new int[3 * ntris];
    memcpy(vertexIndex, vi, 3 * ntris * sizeof(int));

    if (uv)
    {
        uvs = new float[2*nverts];
        memcpy(uvs, uv, 2*nverts*sizeof(float));
    }
    else
        uvs = NULL;

    p = new Point[nverts];

    if (N)
    {
        n = new Normal[nverts];
        memcpy(n, N, nverts*sizeof(Normal));
    }
    else
        n = NULL;

    if (S)
    {
        s = new Vec3[nverts];
        memcpy(s, S, nverts*sizeof(Vec3));
    }
    else
        s = NULL;

    // Transform mesh vertices to world space
    for (int i = 0; i < nverts; ++i)
        p[i] = m_ObjectToWorld->TransformPoint(P[i]);
}

bool TriangleMesh::CanIntersect() const
{
    return false;
}

TriangleMesh::~TriangleMesh()
{
    delete[] vertexIndex;
    delete[] p;
    delete[] s;
    delete[] n;
    delete[] uvs;
}


BBox TriangleMesh::ObjectBound() const
{
    BBox objectBounds;
    for (int i = 0; i < nverts; i++)
        objectBounds = Union(objectBounds, m_WorldToObject->TransformPoint(p[i]));
    return objectBounds;
}


BBox TriangleMesh::WorldBound() const
{
    BBox worldBounds;
    for (int i = 0; i < nverts; i++)
        worldBounds = Union(worldBounds, p[i]);
    return worldBounds;
}

void TriangleMesh::Refine(vector<Reference<Shape> > &refined) const
{
    for (int i = 0; i < ntris; ++i)
        refined.push_back(new Triangle(m_ObjectToWorld, m_WorldToObject, m_ReverseOrientation, (TriangleMesh *)this, i));
}

Triangle::Triangle(const Transform *o2w, const Transform *w2o, bool ro, TriangleMesh *m, int n) : Shape(o2w, w2o, ro)
{
    m_Mesh = m;
    v = &m_Mesh->vertexIndex[3*n];
}

BBox Triangle::ObjectBound() const
{
    const Point &p1 = m_Mesh->p[v[0]];
    const Point &p2 = m_Mesh->p[v[1]];
    const Point &p3 = m_Mesh->p[v[2]];
    return Union(BBox(m_WorldToObject->TransformPoint(p1), m_WorldToObject->TransformPoint(p2)), m_WorldToObject->TransformPoint(p3));
}


BBox Triangle::WorldBound() const
{
    const Point &p1 = m_Mesh->p[v[0]];
    const Point &p2 = m_Mesh->p[v[1]];
    const Point &p3 = m_Mesh->p[v[2]];
    return Union(BBox(p1, p2), p3);
}


bool Triangle::GetIntersection(const Ray &ray, float *tHit, DifferentialGeometry& dg) const
{
    const Point &p1 = m_Mesh->p[v[0]];
    const Point &p2 = m_Mesh->p[v[1]];
    const Point &p3 = m_Mesh->p[v[2]];
    Vec3 e1 = p2 - p1;
    Vec3 e2 = p3 - p1;
    Vec3 s1 = Cross(ray.m_direction, e2);
    float divisor = Dot(s1, e1);
    
    if (divisor == 0.0f)
        return false;
    float invDivisor = 1.0f / divisor;

    // Compute first barycentric coordinate
    Vec3 s = ray.m_origin - p1;
    float b1 = Dot(s, s1) * invDivisor;
    if (b1 < 0.0f || b1 > 1.0f)
        return false;

    // Compute second barycentric coordinate
    Vec3 s2 = Cross(s, e1);
    float b2 = Dot(ray.m_direction, s2) * invDivisor;
    if (b2 < 0. || b1 + b2 > 1.)
        return false;

    // Compute _t_ to intersection point
    float t = Dot(e2, s2) * invDivisor;
    if (t < ray.mint || t > ray.maxt)
        return false;

    // Fill in _DifferentialGeometry_ from triangle hit
    Normal n = Normalize(Normal(Cross(e1, e2)));
    dg = DifferentialGeometry(ray.GetAt(t), n, this);
    *tHit = t;
    return true;
}


bool Triangle::IsIntersected(const Ray &ray) const
{
    const Point &p1 = m_Mesh->p[v[0]];
    const Point &p2 = m_Mesh->p[v[1]];
    const Point &p3 = m_Mesh->p[v[2]];
    Vec3 e1 = p2 - p1;
    Vec3 e2 = p3 - p1;
    Vec3 s1 = Cross(ray.m_direction, e2);
    float divisor = Dot(s1, e1);
    
    if (divisor == 0.)
        return false;
    float invDivisor = 1.f / divisor;

    // Compute first barycentric coordinate
    Vec3 d = ray.m_origin - p1;
    float b1 = Dot(d, s1) * invDivisor;
    if (b1 < 0. || b1 > 1.)
        return false;

    // Compute second barycentric coordinate
    Vec3 s2 = Cross(d, e1);
    float b2 = Dot(ray.m_direction, s2) * invDivisor;
    if (b2 < 0. || b1 + b2 > 1.)
        return false;

    // Compute _t_ to intersection point
    float t = Dot(e2, s2) * invDivisor;
    if (t < ray.mint || t > ray.maxt)
        return false;

    return true;
}

float Triangle::Area() const
{
    const Point &p1 = m_Mesh->p[v[0]];
    const Point &p2 = m_Mesh->p[v[1]];
    const Point &p3 = m_Mesh->p[v[2]];
    return 0.5f * Cross(p2-p1, p3-p1).Length();
}

Point Triangle::SampleUniform(float u1, float u2, Normal *Ns) const
{
    float b1, b2;
    UniformSampleTriangle(u1, u2, &b1, &b2);

    const Point &p1 = m_Mesh->p[v[0]];
    const Point &p2 = m_Mesh->p[v[1]];
    const Point &p3 = m_Mesh->p[v[2]];
    Point p = b1 * p1 + b2 * p2 + (1.f - b1 - b2) * p3;
    Normal n = Normal(Cross(p2-p1, p3-p1));
    *Ns = Normalize(n);
    if (m_ReverseOrientation)
        *Ns *= -1.f;
    return p;
}


