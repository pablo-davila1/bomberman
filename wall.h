#ifndef WALL_H
#define WALL_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>


class wall : public QGraphicsItem
{
    int posx,posy,width,higth;

public:
    wall();
    wall(int pos_x, int pos_y,int width_,int higth_);

    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) ;
};

#endif // WALL_H
