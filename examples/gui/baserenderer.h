#ifndef BASERENDERER_H
#define BASERENDERER_H

#include "irenderer.h"

class BaseRenderer : public IRenderer
{
public:
    BaseRenderer() {}
    virtual ~BaseRenderer() {}

    virtual void Idle();
    virtual void Display(void);
    virtual void Reshape(int w, int h);
};

#endif // BASERENDERER_H
