#include "rendermoon_core.h"

ConfigurableObject::ConfigurableObject(const Properties &props){
    m_properties = props;
}

ConfigurableObject::ConfigurableObject(Stream *stream, InstanceManager *manager){

}

void ConfigurableObject::setParent(ConfigurableObject *parent) {
}


void ConfigurableObject::addChild(const std::string &name, ConfigurableObject *child)
{
 //   SLog(EError, "ConfigurableObject::addChild(\"%s\", %s) not implemented in \"%s\"",
   //      name.c_str(), child->toString().c_str(), toString().c_str());
}

MTS_IMPLEMENT_CLASS(ConfigurableObject, true, SerializableObject)