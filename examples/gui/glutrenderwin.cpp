#include "glutrenderwin.h"
#include "irenderer.h"
#include "ikeyboardhandler.h"
#include <GL/glut.h>

#include <cassert>

IRenderer* GlutRenderWin::s_renderSystem = nullptr;
IKeyboardHandler* GlutRenderWin::s_keyboardHandler = nullptr;
std::function<void()> GlutRenderWin::s_idleFunc;
int GlutRenderWin::s_width = 0;
int GlutRenderWin::s_height = 0;

void GlutRenderWin::Create(int argc, char** argv,
                           int w, int h,
                           std::string title,
                           std::function<void()> idleFunc,
                           IRenderer* renderer,
                           IKeyboardHandler* handler)
{
    s_renderSystem = renderer;
    s_keyboardHandler = handler;
    s_idleFunc = idleFunc;
    s_width = w;
    s_height = h;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(s_width, s_height);
    glutCreateWindow(title.c_str());
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glutDisplayFunc(&GlutRenderWin::Display);
    glutReshapeFunc(&GlutRenderWin::Reshape);
    glutIdleFunc(&GlutRenderWin::Idle);
    glutKeyboardFunc(&GlutRenderWin::Keyboard);
    glutSpecialFunc(&GlutRenderWin::SpecialKeyboard);
    glutMainLoop();
}

void GlutRenderWin::SetRenderer(IRenderer *renderer)
{
    assert(renderer != nullptr);
    s_renderSystem = renderer;

    // call reshape to initialize the renderer to current window dims
    renderer->Reshape(s_width, s_height);
}

void GlutRenderWin::SetKeyboardHandler(IKeyboardHandler* handler)
{
    s_keyboardHandler = handler;
}

void GlutRenderWin::Display()
{
    if(s_renderSystem != nullptr) { s_renderSystem->Display(); }
}

void GlutRenderWin::Idle()
{
    s_idleFunc();
}

void GlutRenderWin::Reshape(int w, int h)
{
    if(s_renderSystem != nullptr) { s_renderSystem->Reshape(w,h); }
}

void GlutRenderWin::Keyboard(unsigned char ch, int x, int y)
{
    if(s_keyboardHandler != nullptr) { s_keyboardHandler->HandleKeyboard(ch, x, y); }
}


void GlutRenderWin::SpecialKeyboard(int key, int x, int y)
{
    if(s_keyboardHandler != nullptr) { s_keyboardHandler->HandleSpecialKeyboard(key, x, y); }
}
