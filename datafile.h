#ifndef DATAFILE_H
#define DATAFILE_H

#include <QString>
#include <QDebug>
#include <QFile>
#include <QList>

class DataFile: public QFile
{
private:
    void arrSort();

public:
    int *arr;
    int number;
    int arrSize;
    QList <QString**> pScore;
    QList <QString*> pName;

    void scoring(QString, int, int);
    void inputData(QString*, QString*, QString*);
    QString outputData();

    DataFile();
    ~DataFile();
};

#endif // DATAFILE_H
