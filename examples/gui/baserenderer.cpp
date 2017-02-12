#include "baserenderer.h"

#include <GL/glut.h>

void BaseRenderer::Idle()
{
    glutPostRedisplay();
}

void BaseRenderer::Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void BaseRenderer::Reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, h, 0);
    glMatrixMode(GL_MODELVIEW);
}
