#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_TRANSFORMED_PRIMITIVE__
#define __RENDERMOON_CORE_TRANSFORMED_PRIMITIVE__

#include <core/primitive.h>

class TransformedPrimitive
{
public:
    TransformedPrimitive(const Transform& t, Primitive* p) : m_transform(t), m_primitive(p)
    {}


protected:
    Transform m_transform;
    Primitive* m_primitive;
};

#endif
