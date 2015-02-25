#include <rendermoon.h>


ShapeSet::ShapeSet(const Reference<Shape> &s)
{
    vector<Reference<Shape> > todo;
    todo.push_back(s);
    while (todo.size())
    {
        Reference<Shape> sh = todo.back();
        todo.pop_back();
        if (sh->CanIntersect())
            shapes.push_back(sh);
        else
            sh->Refine(todo);
    }
//    if (shapes.size() > 64)
//        Warning("Area light geometry turned into %d shapes; may be very inefficient.", (int)shapes.size());

    sumArea = 0.0f;
    for (uint32_t i = 0; i < shapes.size(); ++i)
    {
        float a = shapes[i]->Area();
        areas.push_back(a);
        sumArea += a;
    }
    areaDistribution = new Distribution1D(areas);
}


ShapeSet::~ShapeSet()
{
    delete areaDistribution;
}


Point ShapeSet::Sample(const Point &p, float u1, float u2, Normal *Ns) const
{
    int sn = areaDistribution->SampleDiscrete(GetRandom(), 0);
	Point pt = shapes[sn]->SamplingByRespectToSolidAngle(p, u1, u2, Ns);

    Ray r(p, pt-p, 1e-3f, INFINITY);
    float thit = 1.f;
    bool anyHit = false;
    DifferentialGeometry dg;
    for (uint32_t i = 0; i < shapes.size(); ++i)
        anyHit |= shapes[i]->GetIntersection(r, &thit, dg);
    if (anyHit) *Ns = dg.m_Normal;
    return r.GetAt(thit);
}


Point ShapeSet::Sample(Normal *Ns, float u1, float u2) const
{
    int sn = areaDistribution->SampleDiscrete(GetRandom(), NULL);
    return shapes[sn]->SamplingUniformlyByRespectToArea(u1, u2, Ns);
}


float ShapeSet::Pdf(const Point &p, const Vec3 &wi) const
{
    float pdf = 0.0f;
    for (uint32_t i = 0; i < shapes.size(); ++i)
        pdf += areas[i] * shapes[i]->Pdf(p, wi);
    return pdf / sumArea;
}


float ShapeSet::Pdf(const Point &p) const
{
    float pdf = 0.f;
    for (uint32_t i = 0; i < shapes.size(); ++i)
        pdf += areas[i] * shapes[i]->Pdf(p);
    return pdf / sumArea;
}


float ShapeSet::Area() const
{
    return sumArea;
}
