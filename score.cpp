#include "score.h"
#include <QFont>

int score::getScore() const
{
    return Score;
}

//score::score()
//{

//}

score::score(QGraphicsItem * parent): QGraphicsTextItem(parent)
{
    Score=0;

    setPlainText(QString("Score: ") + QString::number(Score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));

}
void score::increase(){
    Score++;
    setPlainText(QString("Score: ") + QString::number(Score));
}
