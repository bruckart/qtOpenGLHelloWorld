#include <QApplication>

#include "MyOpenGLWidget.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("");
    // app.setApplicationName("qtOpenGLHelloWorld");
    app.setApplicationVersion("1.0.0");

    MyOpenGLWidget w;
    w.setFixedWidth(800);
    w.setFixedHeight(600);
    w.show();

    return app.exec();
}
