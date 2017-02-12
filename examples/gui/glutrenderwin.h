#ifndef GLUTRENDERWIN_H
#define GLUTRENDERWIN_H

#include <string>
#include <functional>
#include <GL/glut.h>

class IRenderer;
class IKeyboardHandler;

class GlutRenderWin {
public:
    static void Create(int argc, char** argv,
                       int w, int h,
                       std::string title,
                       std::function<void()> idleFunc,
                       IRenderer* renderer = nullptr,
                       IKeyboardHandler* handler = nullptr);
    static void SetRenderer(IRenderer* renderer);
    static void SetKeyboardHandler(IKeyboardHandler* handler);

private:
    static IRenderer* s_renderSystem;
    static IKeyboardHandler* s_keyboardHandler;
    static std::function<void()> s_idleFunc;
    static int s_width;
    static int s_height;

    static void Display();
    static void Idle();
    static void Reshape(int w, int h);
    static void Keyboard(unsigned char ch, int x, int y);
    static void SpecialKeyboard(int key, int x, int y);

};
#endif // GLUTRENDERWIN_H
