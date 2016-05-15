#include <QGraphicsScene>
#include "test.h"
#include "Bullet.h"
#include "MyRect.h"
#include <QTimer>

create::create()
{
    QTimer *cre = new QTimer();
    connect(cre,SIGNAL(timeout()),this,SLOT(randpmbits()));

    cre->start(1000);
}

create::randombits()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int a= qrand();
    if(a%2==true)
    {
        Bullet *bullet = new  Bullet();
        bullet->setPos(x()+50,y()+50);
        scene()->addItem(bullet);
    }
}
