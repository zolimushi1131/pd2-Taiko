#include "bits2.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <typeinfo>

Bits2::Bits2(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem()
{
    //從畫面中間產生音符
    setPixmap(QPixmap(":/image/bits2.png"));
    //產生一移動之音符
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(30);
}

void Bits2::move()
{
    setPos(x()-5,y());
    if (pos().y()< 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
