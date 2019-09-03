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

void DataFile::scoring(QString s, int i, int j)
{
    pScore << new QString*;
    *pScore[i][j] = s;
}
