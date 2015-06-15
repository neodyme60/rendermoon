#ifndef PROJECT_INSTANCE_MANAGER_H
#define PROJECT_INSTANCE_MANAGER_H

#include <vector>
#include <map>
#include "object.h"
class Stream;
class SerializableObject;

class InstanceManager : public Object {
    friend class SerializableObject;
public:
    /// \brief Construct a new instance manager
    InstanceManager();

    /// Retrieve an instance from the given stream
    SerializableObject *getInstance(Stream *stream);

    /// Store an instance to the given stream
    void serialize(Stream *stream, const SerializableObject *inst);

    MTS_DECLARE_CLASS()
private:
    /// Virtual destructor
    virtual ~InstanceManager();

    /// Called from the unserialization constructor of SerializableObject
    void registerInstance(SerializableObject *object);
private:
    unsigned int m_counter, m_lastID;
    std::vector<SerializableObject *> m_fullyAllocated;
    std::map<unsigned int, SerializableObject *> m_idToObj;
    std::map<const SerializableObject *, unsigned int> m_objToId;
};


#endif //PROJECT_INSTANCE_MANAGER_H
