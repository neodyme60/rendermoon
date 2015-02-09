#ifndef __RENDERMOON_DIFFUSE_MATERIAL__
#define __RENDERMOON_DIFFUSE_MATERIAL__

#include <core/primitive.h>

class DiffuseMaterial : public Material
{
public:

	DiffuseMaterial(const Vec3& color) { m_color = color;}
    virtual ~DiffuseMaterial() {}


};

#endif