#include "brick.h"

brick::brick()
{

}

brick::brick(int pos_x, int pos_y, int width_, int higth_)
{
    this->posx=pos_x;
    this->posy=pos_y;
    this->width=width_;
    this->higth=higth_;
    setPos(posx, posy);
}

QRectF brick::boundingRect() const
{
    return QRect(-width,-higth,width,higth);
}

void brick::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::red);
    //painter->drawRect(boundingRect());
    QPixmap pxmap(":/walls/pared.png");
    painter->drawPixmap(boundingRect(),pxmap,pxmap.rect());
}

int brick::getPosx() const
{
    return posx;
}

int brick::getPosy() const
{
    return posy;
}
