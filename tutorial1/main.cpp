#include <QGraphicsScene>
#include <QGraphicsView>
#include <QApplication>
#include <QGraphicsRectItem>
#include "drum.h"
#include "setgame.h"
#include <QTimer>
#include <stdlib.h>
#include <QPushButton>

setGame *game;
int main(int argc,char *argv[])
{
    QApplication a(argc,argv);

    game = new setGame();
    game->show();

    /*QPushButton exit("Quit");
    exit.setParent(game);
    exit.setGeometry(400,0,100,100);
    QObject::connect(&exit,SIGNAL(clicked()),&a,SLOT(quit()));
    exit.show();*/

    return a.exec();
}
