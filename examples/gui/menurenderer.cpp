#include "menurenderer.h"

#include <GL/glut.h>

using namespace std;

MenuRenderer::MenuRenderer() :
    m_font(GLUT_BITMAP_9_BY_15),
    m_selectedItem(0)
{
}

MenuRenderer::MenuRenderer(vector<string> menuItems) :
    MenuRenderer()
{
    m_menuItems = menuItems;
}

void MenuRenderer::Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // draw our menu items
    int yDelta = 25;
    int i = 0;
    for(auto item : m_menuItems){
        DrawString(10, 25 + (i++)*yDelta, item, (i == m_selectedItem ? Green : White));
    }
    glutSwapBuffers();
}


void MenuRenderer::SelectItem(int index)
{
    m_selectedItem = index;
}

void MenuRenderer::AddItem(std::string item)
{
    m_menuItems.push_back(item);
}

void MenuRenderer::DrawString(int x, int y, std::string str, Color color)
{
    glPushAttrib(GL_COLOR_BUFFER_BIT);
    SelectColor(color);

    glRasterPos2f(x, y);
    for (auto ch : str) {
        glutBitmapCharacter(m_font, ch);
    }

    glPopAttrib();
}

void MenuRenderer::SelectColor(Color color)
{
    switch (color) {
    case Green:   glColor3f(0.0, 1.0, 0.0); break;
    case Red: glColor3f(1.0, 0.0, 0.0); break;
    case White: glColor3f(1.0, 1.0, 1.0); break;
    }
    glutPostRedisplay();
}

