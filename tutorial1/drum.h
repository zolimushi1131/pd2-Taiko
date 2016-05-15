#ifndef DRUM_H
#define DRUM_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QMediaPlayer>

class Drum: public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    Drum(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent *event);
    int score=0;
public slots:
    void creator();
private:
    QMediaPlayer *sound1;
    QMediaPlayer *sound2;
};


#endif // DRUM_H

