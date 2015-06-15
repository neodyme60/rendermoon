#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_SERIALIZATION__
#define __RENDERMOON_CORE_SERIALIZATION__

#include "object.h"

class InstanceManager;
class Stream;

class SerializableObject : public Object
{
public:
    SerializableObject(Stream *stream, InstanceManager *manager);

    MTS_DECLARE_CLASS()
protected:
    /// Construct a serializable object
    inline SerializableObject() { }

    /// Virtual deconstructor
    virtual ~SerializableObject() { }
};


#endif
