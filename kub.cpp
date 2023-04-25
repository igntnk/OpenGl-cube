#include "kub.h"
#include <QOpenGLFunctions>
#include <QMouseEvent>

kub::kub()
{

}

void kub::initializeGL()
{
    glClearColor(0.7,0.7,0.7,0.7);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glShadeModel(GL_FLAT);
    glEnable(GL_CULL_FACE);
}

void kub::resizeGL(int w, int h)
{
    glOrtho(-2.0,3,-2.0,3,-50.0,50.0);
    glViewport(0,0,(GLint)w,(GLint)h);

    currentWidth=w;
    currentHeight=h;
}

void kub::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(yAxisRotation,0.0,0.3,0.0);
    glRotatef(xAxisRotation,0.3,0.0,0.0);

    GLfloat vertex[8][3];
    GLfloat color[8][3];
    GLubyte painting[6][4];

    vertex[0][0]=0.0;
    vertex[0][1]=0.0;
    vertex[0][2]=0.5;
    vertex[1][0]=0.0;
    vertex[1][1]=0.5;
    vertex[1][2]=0.5;
    vertex[2][0]=0.5;
    vertex[2][1]=0.5;
    vertex[2][2]=0.5;
    vertex[3][0]=0.5;
    vertex[3][1]=0.0;
    vertex[3][2]=0.5;
    vertex[4][0]=0.0;
    vertex[4][1]=0.0;
    vertex[4][2]=0.0;
    vertex[5][0]=0.0;
    vertex[5][1]=0.5;
    vertex[5][2]=0.0;
    vertex[6][0]=0.5;
    vertex[6][1]=0.5;
    vertex[6][2]=0.0;
    vertex[7][0]=0.5;
    vertex[7][1]=0.0;
    vertex[7][2]=0.0;

    color[0][0]=0.0;
    color[0][1]=1.0;
    color[0][2]=0.5;
    color[1][0]=0.0;
    color[1][1]=0.88;
    color[1][2]=1.6;
    color[2][0]=0.0;
    color[2][1]=1.36;
    color[2][2]=0.8;
    color[3][0]=0.0;
    color[3][1]=0.36;
    color[3][2]=1.68;
    color[4][0]=0.0;
    color[4][1]=1.17;
    color[4][2]=0.99;
    color[5][0]=0.0;
    color[5][1]=0.13;
    color[5][2]=1.56;
    color[6][0]=0.0;
    color[6][1]=1.57;
    color[6][2]=0.89;
    color[7][0]=0.0;
    color[7][1]=1.27;
    color[7][2]=1.0;

    painting[0][0]=0;
    painting[0][1]=3;
    painting[0][2]=2;
    painting[0][3]=1;
    painting[1][0]=0;
    painting[1][1]=1;
    painting[1][2]=5;
    painting[1][3]=4;
    painting[2][0]=7;
    painting[2][1]=4;
    painting[2][2]=5;
    painting[2][3]=6;
    painting[3][0]=3;
    painting[3][1]=7;
    painting[3][2]=6;
    painting[3][3]=2;
    painting[4][0]=1;
    painting[4][1]=2;
    painting[4][2]=6;
    painting[4][3]=5;
    painting[5][0]=0;
    painting[5][1]=4;
    painting[5][2]=7;
    painting[5][3]=3;

    glVertexPointer(3, GL_FLOAT, 0, vertex);
    glColorPointer(3, GL_FLOAT, 0, color);
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, painting);
}

void kub::mouseMoveEvent(QMouseEvent *event)
{
    xAxisRotation += (180* ((GLfloat)event->y()-(GLfloat)pressPosition.y()))/(currentHeight);
    yAxisRotation += (180* ((GLfloat)event->x()-(GLfloat)pressPosition.x()))/(currentWidth);
    pressPosition=event->pos();
    update();
}










