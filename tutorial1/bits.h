#ifndef BITS_H
#define BITS_H
#include <QObject>
#include <QGraphicsPixmapItem>

class Bits: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bits(QGraphicsItem *parent = 0);
public slots:
    void move();
};


#endif // BITS_H
