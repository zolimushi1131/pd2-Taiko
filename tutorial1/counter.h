#ifndef COUNTER_H
#define COUNTER_H

#include <QGraphicsTextItem>

class Counter: public QGraphicsTextItem
{
    Q_OBJECT
public:
    Counter(QGraphicsItem *parent = 0);

    int counter;
public slots:
    void decrease();
};
#endif // COUNTER_H
