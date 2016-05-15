#ifndef SETGAME_H
#define SETGAME_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "drum.h"
#include "score.h"
#include "counter.h"
#include <QLabel>
#include <QPushButton>

class setGame: public QGraphicsView
{
    Q_OBJECT
public:
    setGame(QWidget * parent=0);

    QGraphicsScene *scene;
    Drum *drum;
    Score *score;
    Counter *count;
    QLabel *Result;
    QLabel *End;
    void GameStart();

public slots:
    void Ending();
    void quit();
    void reset();

private:
    QPushButton *exit;
    QPushButton *restart;
    QTimer *alltime;
    QTimer *timer;
};

#endif // SETGAME_H
