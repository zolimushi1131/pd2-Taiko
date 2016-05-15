#include "score.h"
#include <QFont>
#include "setgame.h"

extern setGame *game;

Score::Score(QGraphicsItem *parent)
{
    score = 0;

    setPlainText(QString("Score:")+QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Score::increase()
{
    if(game->count->counter>0)
    {
        score+=10;
        setPlainText(QString("Score:")+QString::number(score));

    }
}

int Score::getscore()
{
    return score;
}
