#ifndef FUNCTIONWINDOW_H
#define FUNCTIONWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QImage>
#include <QPixmap>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QList>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "datafile.h"

class FunctionWindow: public QMainWindow
{
    Q_OBJECT
private:
    bool flag;
    QMenu *menu;
    QAction *pHelp;
    QAction *pAbout;
    QPushButton *btnInputData;
    QPushButton *btnScoring;
    QPushButton *btnSort;
    QPushButton *btnCheck;
    QPushButton *btnQuit;
    DataFile *file;
    QString *name;
    QString *sex;
    QString *age;

    void initUI();
    void initSlots();

private slots:


public:
    FunctionWindow();
    ~FunctionWindow();
};

#endif // FUNCTIONWINDOW_H
