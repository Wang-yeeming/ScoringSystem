#include "datafile.h"

DataFile::DataFile()
{
    number = 0;
    arr = new int;

    QFile file("./DataFile.txt");
    if(file.exists())
        file.remove();
}

DataFile::~DataFile()
{
    delete [] arr;
    qDeleteAll(pName);
    qDebug() << "数据文件类被析构";
}

void DataFile::inputData(QString *name, QString *sex, QString *age)
{
    pName << new QString;
    *pName[number] = *name;
    arr[number] = number + 1;
    number ++;
    arrSize = number;

    QFile *pFile = new QFile("./DataFile.txt");
    pFile -> open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    pFile -> write("-----------------\n"
                  "编号：");
    pFile -> putChar(char(number));
    pFile -> write("\n姓名：");
    pFile -> write(name -> toUtf8());
    pFile -> write("\n性别：");
    pFile -> write(sex -> toUtf8());
    pFile -> write("\n年龄：");
    pFile -> write(age -> toUtf8());
    pFile -> write("\n");
    ;
    pFile -> close();
}

QString DataFile::outputData()
{
    QFile *pFile = new QFile("./DataFile.txt");
    pFile -> open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray *data = new QByteArray;
    *data = pFile -> readAll();
    pFile -> close();
    return *data;
}

void DataFile::inputScore(QString s, int i, int j)
{
    pScore[i][j] = s.toDouble();
}

void DataFile::initPtrScore()
{
    pScore = new double *[10];
    for (int i = 0; i < 10; i ++)
        pScore[i] = new double[unsigned(arrSize)];
}

void DataFile::staScore()
{
    double *arrAdverge = new double[10];
    double max = 0;
    double min = 0;
    int posMax = 0;
    int posMin = 0;

    for (int i = 0; i < 10; i ++)
    {
        for (int j = 0; j < arrSize; j ++)
        {
            if (max < pScore[i][j])
            {
                max = pScore[i][j];
                posMax = j;
            }

            if (min > pScore[i][j])
            {
                min = pScore[i][j];
                posMin = j;
            }

        }

        double sum = 0;

        for (int j = 0; j < arrSize; j ++)
        {
            if((j == posMax) || (j == posMin))
                continue;
            else
                sum += pScore[i][j];

        }

        arrAdverge[i] = sum / 10;

    }

    double temp;
    QString *qtemp = new QString;

    for (int i = 0; i < 9; i ++)
    {
        for (int j = 0; j < 9 - i; j ++)
        {
            if(arrAdverge[j] < arrAdverge[j + 1])
            {
                temp = arrAdverge[j];
                arrAdverge[j] = arrAdverge[j + 1];
                arrAdverge[j + 1] = temp;

                qtemp = pName[j];
                pName[j] = pName[j + 1];
                pName[j + 1] = qtemp;
            }
        }
    }

    delete [] arrAdverge;
    delete qtemp;
}
