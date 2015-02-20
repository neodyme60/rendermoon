#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_DIFFERENTIAL_GEOMETRY__
#define __RENDERMOON_CORE_DIFFERENTIAL_GEOMETRY__

class Shape;

class DifferentialGeometry
{
public:
    DifferentialGeometry();
    DifferentialGeometry(const Point& p, const Normal& n, const Shape * s);
    DifferentialGeometry(const Shape *shape);
    Point           m_Point;
    Normal          m_Normal;
    const Shape*    m_Shape;
};


#endif

