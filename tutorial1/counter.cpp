#include "counter.h"
#include <QFont>
#include <QTimer>
#include <QDebug>

Counter::Counter(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    counter = 30;

    setPlainText(QString("Time:")+QString::number(counter));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(decrease()));
    timer->start(1000);
}

void Counter::decrease()
{
    if(counter>0)
    {
        counter--;
        setPlainText(QString("Time:")+QString::number(counter));
    }
}

