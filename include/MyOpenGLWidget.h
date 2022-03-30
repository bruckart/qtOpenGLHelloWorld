
#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>

class MyOpenGLWidget : public QOpenGLWidget
{
public:
    MyOpenGLWidget(QWidget *parent = 0);
    ~MyOpenGLWidget();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
};

#endif // MYOPENGLWIDGET_H

