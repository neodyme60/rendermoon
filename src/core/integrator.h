#ifndef __RENDERMOON_CORE_INTEGRATOR__
#define __RENDERMOON_CORE_INTEGRATOR__

class Integrator
{
public:
    Integrator() {}

    virtual void PreProcess() {}
    virtual void PostProcess() {}

    virtual ~Integrator() {}
};

#endif
