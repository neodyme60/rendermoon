#include "rendermoon_core.h"

Emitter::Emitter(const Properties &props) : AbstractEmitter(props) {
    m_lightToWorld = props.FindOneTransform("lightToWorld", Transform());
    m_worldToLight = m_lightToWorld.GetInverse();
    m_samplesCount = props.FindOneInt("samples", 1);
}

Emitter::Emitter(Stream *stream, InstanceManager *manager) : AbstractEmitter(stream, manager) {
}

Emitter::~Emitter()
{

}

Spectrum Emitter::Le(const Ray &r) const
{
    return Spectrum(0.0);
}

MTS_IMPLEMENT_CLASS(Emitter, false, AbstractEmitter)