#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>

class score : public QGraphicsTextItem
{
private:
    int Score;
public:
    //score();
    score(QGraphicsItem * parent = 0);
    void increase();

    int getScore() const;

};

#endif // SCORE_H
