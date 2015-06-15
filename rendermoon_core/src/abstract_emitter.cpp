#include "rendermoon_core.h"

AbstractEmitter::AbstractEmitter(const Properties &props) : ConfigurableObject(props) {
}

AbstractEmitter::AbstractEmitter(Stream *stream, InstanceManager *manager) : ConfigurableObject(stream, manager) {
}

MTS_IMPLEMENT_CLASS(AbstractEmitter, true, ConfigurableObject)