#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_CONFIGURABLE_OBJECT__
#define __RENDERMOON_CORE_CONFIGURABLE_OBJECT__

#include <string>
#include "reference.h"
#include "properties.h"
#include "serialization.h"

using namespace std;

class ConfigurableObject : public SerializableObject
{
public:

    ConfigurableObject(const Properties &props);

    ConfigurableObject(Stream *stream, InstanceManager *manager);

    virtual void setParent(ConfigurableObject *parent);

    virtual void addChild(const string &name, ConfigurableObject *child);

    const Properties &getProperties() const { return m_properties; }

    MTS_DECLARE_CLASS()

protected:
    Properties m_properties;
};

#endif
