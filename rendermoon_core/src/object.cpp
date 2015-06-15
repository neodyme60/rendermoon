#include <sstream>
#include "rendermoon_core.h"

Object::Object() : ReferenceCounted(){
//#if DEBUG_REFCOUNTS == 1
//	if (__ref_tracker)
//		__ref_tracker->add(this);
//#endif
}

Object::~Object() {
}

void Object::staticShutdown() {
}

std::string Object::toString() const {
    std::ostringstream oss;
    oss << getClass()->getName();
    oss << "[unknown]";
    return oss.str();
}

void Object::staticInitialization() {
//#if DEBUG_REFCOUNTS == 1
//	if (!__ref_tracker)
//		__ref_tracker = new RefCountTracker();
//#endif
}

const Class *Object::getClass() const {
    return m_theClass;
}
