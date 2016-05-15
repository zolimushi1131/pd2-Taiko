#include "drum.h"
#include "bits.h"
#include "bits2.h"
#include "setgame.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <typeinfo>
#include <stdlib.h>
#include <QList>
#include <QGraphicsRectItem>

extern setGame *game;
Drum::Drum(QGraphicsItem *parent): QGraphicsRectItem(parent){
    sound1= new QMediaPlayer();
    sound1->setMedia(QUrl("qrc:/sound/sound1.mp3"));
    sound2= new QMediaPlayer();
    sound2->setMedia(QUrl("qrc:/sound/sound2.mp3"));
}
void Drum::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_J)
    {
        //刪除音符1
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i)
        {
            if (typeid(*(colliding_items[i])) == typeid(Bits))
            {
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                game->score->increase();
                qDebug()<<"J";

                //播放消除音效
                if (sound1->state() == QMediaPlayer::PlayingState)
                {
                    sound1->setPosition(0);
                }
                else if (sound1->state() == QMediaPlayer::StoppedState)
                {
                    sound1->play();
                }
            }
        }
    }
    if(event->key()==Qt::Key_K)
    {
        qDebug()<<"K";
        //刪除音符2
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for (int i = 0, n = colliding_items.size(); i < n; ++i)
        {
            if (typeid(*(colliding_items[i])) == typeid(Bits2))
            {
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                game->score->increase();

                //播放消除音效
                if (sound2->state() == QMediaPlayer::PlayingState)
                {
                    sound2->setPosition(0);
                }
                else if (sound2->state() == QMediaPlayer::StoppedState)
                {
                    sound2->play();
                }
            }
        }
    }
}

void Drum::creator()
{
    if(game->count->counter>0)
    {
        int random=rand()%2;
        if(random==true)
        {
            qDebug()<<"bit1 out";
            Bits *bits = new Bits();
            scene()->addItem(bits);
            bits->setPos(800,50);
        }
        if(random==false)
        {
            qDebug()<<"bit2 out";
            Bits2 *bits2 = new Bits2();
            scene()->addItem(bits2);
            bits2->setPos(800,50);
        }
    }
}
