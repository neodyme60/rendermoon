#include <rendermoon.h>

DifferentialGeometry::DifferentialGeometry()
{
    m_Shape = NULL;
}


DifferentialGeometry::DifferentialGeometry(const Shape *shape) : m_Shape(shape)
{

}

DifferentialGeometry::DifferentialGeometry(const Point& p, const Normal& n, const Shape * s)
{
    m_Point = p;
    m_Normal = n;
    m_Shape = s;
}

