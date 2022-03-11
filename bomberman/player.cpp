#include "player.h"

player::player()
{

}

player::player(int pos_x, int pos_y, int width_, int higth_)
{
    this->posx = pos_x;
    this->posy = pos_y;
    this->width=width_;
    this->higth = higth_;
    setPos(posx,posy);
}

QRectF player::boundingRect() const
{
    return QRect(-width,-higth,width,higth);
}

void player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    //painter->drawEllipse(boundingRect());

    painter->drawRect(boundingRect());
}

void player::move_lef()
{
    posx-=5;
    setPos(posx,posy);

}

void player::move_rith()
{
    posx+=5;
    setPos(posx,posy);
}

void player::move_up()
{
    posy-=5;
    setPos(posx,posy);
}

void player::move_down()
{
    posy+=5;
    setPos(posx,posy);
}

int player::getPosx() const
{
    return posx;
}

int player::getPosy() const
{
    return posy;
}
