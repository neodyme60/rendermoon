#ifndef __RENDERMOON_CORE_PRIMITIVE__
#define __RENDERMOON_CORE_PRIMITIVE__

class Transform;
struct Intersection;
class Ray;
class Normal;
class Spectrum;
class Material;
class Point;

class Primitive
{
public:
	Primitive();
	Primitive(const Transform& o2w, const Transform& w2o);
    virtual ~Primitive(){}

    virtual bool GetIntersection(const Ray &r, Intersection&)  const = 0;
    virtual bool IsIntersected(const Ray &r) const=0;

	virtual void GetRandomSample(Normal& n, Point& p) const {}

	virtual float area() { return 0.0f;}

	virtual     Spectrum L(Intersection& i, Point& light_point, Normal& light_nornal) { return Spectrum(); }

	Material*	m_material;
	Transform	m_objectToWorld, m_worldToObject;
	bool		isemiter;
	std::string	name;
	Vec3		pos;
};

#endif

