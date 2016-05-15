#include "bits.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <typeinfo>
#include "setgame.h"

extern setGame *game;

Bits::Bits(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    //從畫面中間產生音符
    setPixmap(QPixmap(":/image/bits1.png"));
    //產生一移動之音符
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(30);
}

void Bits::move()
{
    setPos(x()-5,y());
    if (pos().y() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
