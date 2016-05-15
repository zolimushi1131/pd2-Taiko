#ifndef TIMER_H
#define TIMER_H

#include <QGraphicsTextItem>

class Time: public QGraphicsTextItem
{
public:
    Time(QGraphicsTextItem *parent =0);
    int getTime();
public slots:
    void count();

private:
    int time;
};

#endif // TIMER_H
