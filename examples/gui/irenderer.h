#ifndef IRENDERER_H
#define IRENDERER_H


class IRenderer {
public:
    virtual void Display() = 0;
    virtual void Idle() = 0;
    virtual void Reshape(int, int) = 0;
};


#endif // IRENDERER_H
