#ifndef HELLOWINDOW_H
#define HELLOWINDOW_H

#include "functionwindow.h"

class HelloWindow: public QDialog
{
    Q_OBJECT
private:
    QPushButton *btnEnter;
    QLabel *labHello;
    FunctionWindow func;

    void initUI();
    void initSlots();

private slots:
    void pressButton();

public:
    HelloWindow();
    ~HelloWindow();
};

#endif // HELLOWINDOW_H
