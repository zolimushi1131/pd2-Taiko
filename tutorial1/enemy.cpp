#include "enemy.h"
#include <QTimer>
#include <QGraphicsItem>
#include <QList>
#include <stdlib.h>
#include "enemy.h"

Enemy::Enemy():QObject(),QGraphicsRectItem()
{
    int random_number = rand()%700;
    setPos(random_number,0);

    setRect(0,0,100,100);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    setPos(x(),y()+5);
    if(pos().y()+rect().height()<0)
    {
        scene->removeItem(this);
        delete this;
    }
}
