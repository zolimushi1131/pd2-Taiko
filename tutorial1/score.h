#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem
{
public:
    Score(QGraphicsItem *parent = 0);
    void increase();
    int getscore();
    int score;
private:

};

#endif // SCORE_H
