#ifndef BITS2_H
#define BITS2_H
#include <QObject>
#include <QGraphicsPixmapItem>

class Bits2: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bits2(QGraphicsItem *parent = 0);
public slots:
    void move();
};


#endif // BITS2_H
