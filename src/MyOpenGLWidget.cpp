
#include "MyOpenGLWidget.h"

#include <iostream>

#include <GL/glu.h>
#include <GL/gl.h>


MyOpenGLWidget::MyOpenGLWidget(QWidget *parent)
:
    QOpenGLWidget(parent)
{
}

MyOpenGLWidget::~MyOpenGLWidget()
{
}

void MyOpenGLWidget::initializeGL()
{
    std::clog << "MyOpenGLWidget::initializeGL()" << std::endl;

    glClearColor(0,0,0,1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);

    // Set up the rendering context, load shaders and other resources, etc.:
    // QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    // f->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    // ...

    // initializeOpenGLFunctions();
    // glClearColor(...);

    // m_context->makeCurrent(this);
    // initializeOpenGLFunctions();
}

void MyOpenGLWidget::resizeGL(int w, int h)
{
    std::clog << "MyOpenGLWidget::resizeGL()" << std::endl;

    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w/h, 0.01, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,5,0,0,0,0,1,0);

    // Update projection matrix and other size related settings:
    // m_projection.setToIdentity();
    // m_projection.perspective(45.0f, w / float(h), 0.01f, 100.0f);
    // ...
}

void MyOpenGLWidget::paintGL()
{
    std::clog << "MyOpenGLWidget::paintGL()" << std::endl;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(-0.5, -0.5, 0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f( 0.5, -0.5, 0);
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f( 0.0,  0.5, 0);
    glEnd();

    // Clear color and depth buffer
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Draw the scene:
    // QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    // f->glClear(GL_COLOR_BUFFER_BIT);
    // ...

    // painter->setPen(Qt::NoPen);
    // painter->setBrush(Qt::black);
    // painter->drawEllipse(QRectF(-radius,-radius,radius*2,radius*2));




    // glBegin(GL_POLYGON);
    //     glColor3f(1, 0, 0); glVertex3f(-0.6, -0.75, 0.5);
    //     glColor3f(0, 1, 0); glVertex3f(0.6, -0.75, 0);
    //     glColor3f(0, 0, 1); glVertex3f(0, 0.75, 0);
    // glEnd();
  // Draw a white grid "floor" for the tetrahedron to sit on.
    // glColor3f(1.0, 1.0, 1.0);
    // glBegin(GL_LINES);
    // for (GLfloat i = -2.5; i <= 2.5; i += 0.25)
    // {
    //     glVertex3f(i, 0, 2.5); glVertex3f(i, 0, -2.5);
    //     glVertex3f(2.5, 0, i); glVertex3f(-2.5, 0, i);
    // }
    // glEnd();
}
