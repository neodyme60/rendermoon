#include "rendermoon_core.h"

SerializableObject::SerializableObject(Stream *stream, InstanceManager *manager) {
    //todo
    //  manager->registerInstance(this);
}

MTS_IMPLEMENT_CLASS(SerializableObject, true, Object)