#include <QApplication>
#include "hellowindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    HelloWindow hello;

    hello.show();

    return app.exec();
}
