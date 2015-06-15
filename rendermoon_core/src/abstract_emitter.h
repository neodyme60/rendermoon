#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_ABSTRACT_EMITTER__
#define __RENDERMOON_CORE_ABSTRACT_EMITTER__

#include "configurable_object.h"

class AbstractEmitter : public ConfigurableObject
{

public:
    AbstractEmitter(const Properties &props);
    AbstractEmitter(Stream *stream, InstanceManager *manager);
    MTS_DECLARE_CLASS()

    Transform m_worldTransform;
};


#endif
