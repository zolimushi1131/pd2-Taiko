#include "timer.h"
#include <QFont>
#include <QTimer>
#include <QDebug>

Time::Time(QGraphicsTextItem *parent)
{
    time=30;

    setPlainText(QString("Time:")+QString::number(time));
    setDefaultTextColor(Qt::gray);
    setFont(QFont("times",16));//這啥
}

void Time::count()
{
    time--;
    setPlainText(QString("Time:")+QString::number(time));
    qDebug()<<time;
}


int Time::getTime()
{
    return time;
}
