#include "hellowindow.h"

HelloWindow::HelloWindow()
{
    this -> initUI();
    this -> initSlots();
}

HelloWindow::~HelloWindow()
{
    qDebug() << QString("欢迎窗口被析构");
}

void HelloWindow::initUI()
{
    btnEnter = new QPushButton(QString("确定"));
    labHello = new QLabel(QString("欢迎您进入本系统！"));
    QVBoxLayout *vLay = new QVBoxLayout;
    QHBoxLayout *hLay1 = new QHBoxLayout;
    QHBoxLayout *hLay2 = new QHBoxLayout;

    this -> resize(270, 100);
    this -> setWindowTitle(QString("大赛计分系统"));
    this -> setWindowFlags(Qt::WindowCloseButtonHint);
    hLay1 -> addStretch();
    hLay1 -> addWidget(labHello);
    hLay1 -> addStretch();
    hLay2 -> addStretch();
    hLay2 -> addWidget(btnEnter);
    hLay2 -> addStretch();
    vLay -> addLayout(hLay1);
    vLay -> addLayout(hLay2);
    this -> setLayout(vLay);
}

void HelloWindow::initSlots()
{
    this -> connect(btnEnter, &QPushButton::clicked, this, &HelloWindow::pressButton);
}

void HelloWindow::pressButton()
{
    this -> hide();
    this -> func.show();
}
