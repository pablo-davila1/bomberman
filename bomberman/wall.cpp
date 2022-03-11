#include "wall.h"

wall::wall()
{

}

wall::wall(int pos_x, int pos_y, int width_, int higth_)
{
    this->posx = pos_x;
    this->posy = pos_y;
    this->width=width_;
    this->higth = higth_;
    setPos(posx,posy);
}

QRectF wall::boundingRect() const
{
    return QRect(-width,-higth,width,higth);

}

void wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::gray);
    painter->drawRect(boundingRect());
}
