#ifndef __RENDERMOON_CORE_SHAPE__
#define __RENDERMOON_CORE_SHAPE__


class Shape 
{
public:
    Shape(Transform *o2w, Transform *w2o);
    virtual ~Shape();
    virtual BBox ObjectBound() const = 0;
    virtual BBox WorldBound() const;
    virtual bool CanIntersect() const;
    virtual bool GetIntersection(const Ray &ray, float *tHit, float *rayEpsilon, Intersection&) const;
    virtual bool IsIntersected(const Ray &ray) const;
    virtual float Area() const;
    virtual Point Sample(float u1, float u2, Normal *Ns) const 
	{
        return Point();
    }
    virtual Point Sample(const Point &P, float u1, float u2, Normal *Ns) const 
	{
        return Sample(u1, u2, Ns);
    }

    // Shape Public Data
    Transform *m_objectToWorld, *m_worldToObject;
};

#endif
