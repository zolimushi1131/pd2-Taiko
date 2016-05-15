#include "start.h"


start::start(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);

    setStyleSheet("background:transparent;");

    QLabel *backgnd = new QLabel(this);
    QMovie *bg = new QMovie(":/image/bg.gif");
    backgnd->setMovie(bg);
    bg->start();
    backgnd->lower();

    scene->addWidget(backgnd);
}
