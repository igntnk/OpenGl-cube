#ifndef KUB_H
#define KUB_H

#include <QOpenGLWindow>
#include <QWidget>
//#include <QGLWidget>

class kub : public QOpenGLWindow
{
public:
    kub();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void mouseMoveEvent(QMouseEvent *event);

private:
    QPoint pressPosition;
    GLfloat xAxisRotation;
    GLfloat yAxisRotation;
    GLfloat currentWidth;
    GLfloat currentHeight;

};

#endif // KUB_H
