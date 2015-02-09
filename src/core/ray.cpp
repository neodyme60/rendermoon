#include <rendermoon.h>

Point& Ray::GetOrigin()
{
    return m_origin;
}

Vec3& Ray::GetDirection()
{
    return m_direction;
}

Point Ray::GetOrigin() const
{
    return m_origin;
}

Vec3 Ray::GetDirection() const
{
    return m_direction;
}

Point Ray::GetAt(float t) const
{
    return Point(m_origin.x + t* m_direction.x, m_origin.y + t* m_direction.y, m_origin.z + t* m_direction.z);
}

void Ray::SetDirection(Vec3 d)
{
    m_direction = d;
}

void Ray::SetOrigin(Point o)
{
    m_origin = o;
}

float Ray::GetTime()  const
{
    return m_time;
}

void Ray::SetTime(float t)
{
    m_time = t;

}

float Ray::GetMaxt()  const
{
    return maxt;
}

void Ray::SetMaxt(float t)
{
    maxt = t;
}

float Ray::GetMint()  const
{
    return mint;
}

void Ray::SetMint(float t)
{
    mint = t;
}

int Ray::GetDepth()  const
{
    return m_depth;
}
void Ray::SetDepth(int d)
{
    m_depth = d;
}

ostream& operator<<(ostream& os, const Ray& r)
{
    os << "Ray => " << "o: (" << r.m_origin.x << " " << r.m_origin.y << " " << r.m_origin.z << ") d: (" << r.m_direction.x 
		<< " " << r.m_direction.y << " " << r.m_direction.z << ")" << std::endl;
    return os;
}
