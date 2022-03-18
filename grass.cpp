#include "grass.h"

grass::grass()
{

}

grass::grass(int pos_x, int pos_y, int width_, int higth_)
{
    this->posx = pos_x;
    this->posy = pos_y;
    this->width=width_;
    this->higth = higth_;
    setPos(posx,posy);
}

QRectF grass::boundingRect() const
{
    return QRect(-width,-higth,width,higth);

}

void grass::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   // painter->setBrush(Qt::green);
    //painter->drawRect(boundingRect());
    QPixmap pxmap(":/pisito/piso.png");
    painter->drawPixmap(boundingRect(),pxmap,pxmap.rect());
}
