#include "rendermoon_core.h"


InstanceManager::InstanceManager() : m_counter(0) {
//#ifdef DEBUG_SERIALIZATION
//	Log(EDebug, "Creating an instance manger");
//#endif
}

InstanceManager::~InstanceManager() {
//#ifdef DEBUG_SERIALIZATION
//	Log(EDebug, "Destroying an instance manager");
//#endif
    for (std::vector<SerializableObject *>::iterator it = m_fullyAllocated.begin();
         it!= m_fullyAllocated.end(); ++it) {
//        (*it)->decRef();
    }
}

SerializableObject *InstanceManager::getInstance(Stream *stream) {
//todo
/*
    m_lastID = stream->readUInt();
    if (m_lastID == 0) {
        return NULL;
    } else if (m_idToObj.find(m_lastID) != m_idToObj.end()) {
        return m_idToObj[m_lastID];
    } else {
        SerializableObject *object = NULL;
        std::string className = stream->readString();
#ifdef DEBUG_SERIALIZATION
		Log(EDebug, "Unserializing a class of type '%s'", className.c_str());
#endif
        const Class *theClass = Class::forName(className);
        if (theClass == NULL)
            Log(EError, "Class with name '%s' not found!", className.c_str());
        try {
            object = static_cast<SerializableObject *>
            (theClass->unserialize(stream, this));
        } catch (std::exception &e) {
            Log(EError, "Encountered an exception while unserializing an "
                    "instance of \"%s\": \"%s\"!", className.c_str(), e.what());
        }
        m_fullyAllocated.push_back(object);
        object->incRef();
        return object;
    }
*/
    return NULL;
}

void InstanceManager::registerInstance(SerializableObject *object) {
    m_idToObj[m_lastID] = object;
}

void InstanceManager::serialize(Stream *stream, const SerializableObject *inst) {
    //todo
    /*
    if (inst == NULL) {
        stream->writeUInt(0);
    } else if (m_objToId.find(inst) != m_objToId.end()) {
        stream->writeUInt(m_objToId[inst]);
    } else {
#ifdef DEBUG_SERIALIZATION
		Log(EDebug, "Serializing a class of type '%s'", inst->getClass()->getName().c_str());
#endif
        stream->writeUInt(++m_counter);
        stream->writeString(inst->getClass()->getName());
        m_objToId[inst]=m_counter;
        inst->serialize(stream, this);
    }*/
}

MTS_IMPLEMENT_CLASS(InstanceManager, false, Object)