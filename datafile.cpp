#include "datafile.h"

DataFile::DataFile()
{
    number = 0;

    QFile file("./DataFile.txt");
    if(file.exists())
        file.remove();
}

DataFile::~DataFile()
{
    delete [] arrAverge;
    delete [] pScore;
    qDebug() << "数据文件类被析构";
}

//写入数据文件
void DataFile::inputData(QString *name, QString *sex, QString *age)
{
    arrName[number] = *name;
    number ++;
    arrSize = number;

    QFile *pFile = new QFile("./DataFile.txt");
    pFile -> open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    pFile -> write("-----------------\n"
                  "编号：");
    pFile -> putChar(char(number + '0'));
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

//读取数据文件
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
    pScore[j][i] = s.toDouble();
}

void DataFile::initPtrScore()
{
    pScore = new double *[unsigned(arrSize)];
    for (int i = 0; i < arrSize; i ++)
        pScore[i] = new double[10];
}

//分数统计
void DataFile::staScore()
{
    arrAverge = new double[unsigned(arrSize)];
    double max;
    double min;
    int *posMax = new int[unsigned(arrSize)];
    int *posMin = new int[unsigned(arrSize)];

    for (int i = 0; i < arrSize; i ++)                   //寻找最值
    {
        max = -1;
        min = 1000;
        for (int j = 0; j < 10; j ++)
        {
            if (max < pScore[i][j])
            {
                max = pScore[i][j];
                posMax[i] = j;
            }

            if (min > pScore[i][j])
            {
                min = pScore[i][j];
                posMin[i] = j;
            }

        }

    }

    for (int i = 0; i < arrSize; i ++)                   //求平均分
    {
        double sum = 0;

        for (int j = 0; j < 10; j ++)
        {
            if((j == posMax[i]) || (j == posMin[i]))
                continue;
            else
                sum += pScore[i][j];

        }

        arrAverge[i] = sum / 8;

    }

    double temp;
    QString qtemp;

    for (int i = 0; i < (arrSize - 1); i ++)                //排序
    {
        for (int j = 0; j < (arrSize - 1 - i); j ++)
        {
            if (arrAverge[j] < arrAverge[j + 1])
            {
                temp = arrAverge[j];
                arrAverge[j] = arrAverge[j + 1];
                arrAverge[j + 1] = temp;

                qtemp = arrName[j];
                arrName[j] = arrName[j + 1];
                arrName[j + 1] = qtemp;
            }
        }
    }

    delete [] posMax;
    delete [] posMin;
}
