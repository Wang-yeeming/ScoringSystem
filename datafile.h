#ifndef DATAFILE_H
#define DATAFILE_H

#include <QString>
#include <QDebug>
#include <QFile>

class DataFile: public QFile
{
private:


public:
    int number;
    int arrSize;
    double **pScore;
    QString arrName[500];

    void staScore();
    void initPtrScore();
    void inputScore(QString, int, int);
    void inputData(QString*, QString*, QString*);
    QString outputSta(int);
    QString outputData();

    DataFile();
    ~DataFile();
};

#endif // DATAFILE_H
