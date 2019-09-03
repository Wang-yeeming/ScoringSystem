#include "functionwindow.h"

FunctionWindow::FunctionWindow()
{
    file = new DataFile;
    this -> initUI();
    this -> initSlots();
}

FunctionWindow::~FunctionWindow()
{
    qDebug() << QString("主窗口被析构");
}

void FunctionWindow::initUI()
{
    this -> resize(340, 100);
    this -> setWindowTitle(QString("大赛计分系统"));
    this -> setWindowFlags(Qt::CustomizeWindowHint
                           | Qt::WindowMinimizeButtonHint
                           | Qt::WindowCloseButtonHint);

    QMenuBar *menuBar = new QMenuBar;
    menu = new QMenu(QString("菜单"));

    pHelp = menu -> addAction(QString("帮助"));
    menu -> addSeparator();
    pAbout = menu -> addAction(QString("关于"));
    menuBar -> addMenu(menu);
    this -> setMenuBar(menuBar);

    name = new QString;
    sex = new QString;
    age = new QString;

    btnInputData = new QPushButton(QString("录入数据"));
    btnScoring = new QPushButton(QString("打分"));
    btnCheck = new QPushButton(QString("查询数据"));
    btnSort = new QPushButton(QString("查看排名"));
    btnQuit = new QPushButton(QString("退出系统"));

    QHBoxLayout *hLay1 = new QHBoxLayout();
    hLay1 -> addStretch();
    hLay1 -> addWidget(btnInputData);
    hLay1 -> addStretch();

    QHBoxLayout *hLay2 = new QHBoxLayout();
    hLay2 -> addStretch();
    hLay2 -> addWidget(btnScoring);
    hLay2 -> addStretch();

    QHBoxLayout *hLay3 = new QHBoxLayout();
    hLay3 -> addStretch();
    hLay3 -> addWidget(btnCheck);
    hLay3 -> addStretch();

    QHBoxLayout *hLay4 = new QHBoxLayout();
    hLay4 -> addStretch();
    hLay4 -> addWidget(btnSort);
    hLay4 -> addStretch();

    QHBoxLayout *hLay5 = new QHBoxLayout();
    hLay5 -> addStretch();
    hLay5 -> addWidget(btnQuit);
    hLay5 -> addStretch();

    QVBoxLayout *vLay1 = new QVBoxLayout();
    //vLay1 -> addStretch();
    vLay1 -> addLayout(hLay1);
    vLay1 -> addLayout(hLay2);
    vLay1 -> addLayout(hLay3);
    vLay1 -> addLayout(hLay4);
    vLay1 -> addLayout(hLay5);
    //vLay1 -> addStretch();

    QImage *icon = new QImage("C:\\Users\\lenovo\\Desktop\\QtCode\\day03\\ScoringSystem\\icon.png");
    QImage *miniIcon = new QImage();
    *miniIcon = icon -> scaled(200, 200, Qt::KeepAspectRatio);
    QLabel *pIcon = new QLabel();
    pIcon -> resize(icon -> width(), icon -> height());
    pIcon -> setPixmap(QPixmap::fromImage(*miniIcon));
    QHBoxLayout *mLay1 = new QHBoxLayout();
    mLay1 -> addStretch();
    mLay1 -> addWidget(pIcon);
    mLay1 -> addStretch();
    mLay1 -> addLayout(vLay1);
    mLay1 -> addStretch();

    QWidget *myWidget = new QWidget(this);
    myWidget -> setLayout(mLay1);
    this -> setCentralWidget(myWidget);

}

void FunctionWindow::initSlots()
{
    //帮助信息弹窗槽函数
    connect(pHelp, &QAction::triggered,
            [this]()
            {
                QMessageBox::question(this, "帮助", "使用说明：\n"
                                                  "输入选手信息完成后，即可开始评分。",
                                      QMessageBox::Ok);
            }


            );

    //关于信息弹窗槽函数
    connect(pAbout, &QAction::triggered,
            [this]()
            {
                QMessageBox::about(this, "关于", "声明：\n"
                                               "作者：王一铭\n"
                                               "合肥工业大学物联网工程18-1班");
            }


            );

    //录入选手信息按钮槽函数
    connect(btnInputData, &QPushButton::pressed,
            [this]()
            {
                QDialog *dlgInputData = new QDialog;
                dlgInputData -> setAttribute(Qt::WA_DeleteOnClose);
                dlgInputData -> setWindowTitle(QString("录入选手数据"));
                dlgInputData -> setWindowFlags(Qt::WindowCloseButtonHint);
                dlgInputData -> resize(220, 150);

                QLineEdit *pName = new QLineEdit;
                pName -> setPlaceholderText(QString("姓名"));
                pName -> setAcceptDrops(1);

                QLineEdit *pSex = new QLineEdit;
                pSex -> setPlaceholderText(QString("性别"));
                pSex -> setAcceptDrops(1);

                QLineEdit *pAge = new QLineEdit;
                pAge -> setPlaceholderText(QString("年龄"));
                pAge -> setAcceptDrops(1);

                QPushButton *btnInput = new QPushButton(QString("录入"));
                connect(btnInput, &QPushButton::pressed,
                        [=]()
                        {
                            *name = pName -> text();
                            *sex = pSex -> text();
                            *age = pAge -> text();

                            if(name -> isEmpty()
                                    || sex -> isEmpty()
                                    || age -> isEmpty() )
                            {
                                QMessageBox::warning(dlgInputData, "警告", "输入的信息不能为空！");
                            }
                            else
                            {
                                file -> inputData(name, sex, age);
                                pName -> clear();
                                pSex -> clear();
                                pAge -> clear();
                            }
                        }


                        );


                QPushButton *btnFinished = new QPushButton(QString("完成"));
                connect(btnFinished, &QPushButton::pressed, dlgInputData, &FunctionWindow::close);

                QHBoxLayout *hLay1 = new QHBoxLayout;
                hLay1 -> addStretch();
                hLay1 -> addWidget(btnInput);
                hLay1 -> addStretch();
                hLay1 -> addWidget(btnFinished);
                hLay1 -> addStretch();

                QVBoxLayout *vLay1 = new QVBoxLayout;
                vLay1 -> addWidget(pName);
                vLay1 -> addWidget(pSex);
                vLay1 -> addWidget(pAge);
                vLay1 -> addLayout(hLay1);

                dlgInputData -> setLayout(vLay1);

                dlgInputData -> exec();
            }


            );

    //评分按钮槽函数
    connect(btnScoring, &QPushButton::pressed,
            [this]()
            {
                QList <QDialog*> listDlg;
                QList <QLabel*> content;
                QList <QHBoxLayout*> hLay1;
                QList <QHBoxLayout*> hLay2;
                QList <QVBoxLayout*> mLay;
                QList <QVBoxLayout*> vLay;
                QList <QLabel*> listLabel;
                QList <QLineEdit*> listLine;
                QList <QHBoxLayout*> listHLay;
                QList <QPushButton*> btnNext;

                for(int i = 0; i < 10; i ++)
                {
                    listDlg << new QDialog();
                    content << new QLabel(listDlg[i]);
                    hLay1 << new QHBoxLayout();
                    hLay2 << new QHBoxLayout();
                    mLay << new QVBoxLayout();
                    vLay << new QVBoxLayout();
                    btnNext << new QPushButton(QString("评分完毕"));
                    connect(btnNext[i], &QPushButton::pressed, listDlg[i], &FunctionWindow::close);

                    for(int j = 0; j < (file -> arrSize); j ++)
                    {
                        listLabel << new QLabel();
                        listLine << new QLineEdit();
                        listHLay << new QHBoxLayout();
                    }

                }

                for(int i = 0; i < 10; i ++)
                {
                    listDlg[i] -> setAttribute(Qt::WA_DeleteOnClose);
                    listDlg[i] -> setWindowTitle(QString("评分"));
                    listDlg[i] -> setWindowFlags(Qt::WindowCloseButtonHint);

                    content[i] -> setText("现在请第 " + QString::number(i + 1) + " 位评委评分！");

                    for(int j = 0; j < (file -> arrSize); j ++)
                    {
                        listLabel[j + i * (file -> arrSize)] -> setAlignment(Qt::AlignLeft);
                        listLabel[j + i * (file -> arrSize)] -> setText(*(file -> pName[j]) + "：");

                        listLine[j + i * (file -> arrSize)] -> setPlaceholderText(QString("分数"));
                        QString *score = new QString;
                        *score = listLine[j + i * (file -> arrSize)] -> text();
                        file -> scoring(*score, i, j);

                        listHLay[j + i * (file -> arrSize)] -> addStretch();
                        listHLay[j + i * (file -> arrSize)] -> addWidget(listLabel[j + i * (file -> arrSize)]);
                        listHLay[j + i * (file -> arrSize)] -> addStretch();
                        listHLay[j + i * (file -> arrSize)] -> addWidget(listLine[j + i * (file -> arrSize)]);
                        listHLay[j + i * (file -> arrSize)] -> addStretch();

                        vLay[i] -> addLayout(listHLay[j + i * (file -> arrSize)]);
                    }

                    hLay1[i] -> addStretch();
                    hLay1[i] -> addWidget(content[i]);
                    hLay1[i] -> addStretch();

                    hLay2[i] -> addStretch();
                    hLay2[i] -> addWidget(btnNext[i]);
                    hLay2[i] -> addStretch();

                    mLay[i] -> addLayout(hLay1[i]);
                    mLay[i] -> addLayout(vLay[i]);
                    mLay[i] -> addLayout(hLay2[i]);

                    listDlg[i] -> setLayout(mLay[i]);

                    listDlg[i] -> exec();

                }

                QMessageBox::about(this, "提示", "现在所有评委均已评分完毕！");
            }

            );

    //查看选手信息按钮槽函数
    connect(btnCheck, &QPushButton::pressed,
            [this]()
            {
                QDialog *self = new QDialog();
                self -> setAttribute(Qt::WA_DeleteOnClose);
                self -> setWindowTitle(QString("选手信息"));
                self -> setWindowFlags(Qt::WindowCloseButtonHint);
                self -> resize(200, 150);

                QTextEdit *text = new QTextEdit();
                if((file -> outputData()).isEmpty())
                    text -> setText(QString("尚未录入选手信息！"));
                else
                    text -> setPlainText(file -> outputData());
                text -> setReadOnly(1);

                QPushButton *btnBack = new QPushButton(QString("返回"));
                connect(btnBack, &QPushButton::pressed, self, &FunctionWindow::close);

                QHBoxLayout *hLay1 = new QHBoxLayout;
                hLay1 -> addStretch();
                hLay1 -> addWidget(btnBack);
                hLay1 -> addStretch();

                QVBoxLayout *vLay1 = new QVBoxLayout;
                vLay1 -> addWidget(text);
                vLay1 -> addLayout(hLay1);

                self -> setLayout(vLay1);

                self -> exec();
            }


            );

    //查看选手排名按钮槽函数
    //退出按钮槽函数
    connect(btnQuit, &QPushButton::pressed, this, &FunctionWindow::close);


}
