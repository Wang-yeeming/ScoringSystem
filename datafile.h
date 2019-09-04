#ifndef DATAFILE_H
#define DATAFILE_H

#include <QString>
#include <QDebug>
#include <QFile>
#include <QList>
#include <QMap>

class DataFile: public QFile
{
private:
    void staScore();

public:
    int number;
    int arrSize;
    double **pScore;
    QList <QString*> pName;

    void initPtrScore();
    void inputScore(QString, int, int);
    void inputData(QString*, QString*, QString*);
    QString outputSta(int);
    QString outputData();

    DataFile();
    ~DataFile();
};

#endif // DATAFILE_H
