#ifndef START_H
#define START_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>

class start: public QGraphicsView
{
public:
    start(QWidget * parent=0);
    QGraphicsScene *scene = new QGraphicsScene();
};

#endif // START_H
