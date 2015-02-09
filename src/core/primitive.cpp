#include <rendermoon.h>

Primitive::Primitive()
{
	isemiter= false;
}

Primitive::Primitive(const Transform& o2w, const Transform& w2o) : m_objectToWorld(o2w), m_worldToObject(w2o)
{
	isemiter= false;
}
