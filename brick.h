#ifndef BRICK_H
#define BRICK_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class brick: public QGraphicsItem
{
    int posx,posy,width,higth;

public:
    brick();
    brick(int pos_x, int pos_y,int width_,int higth_);

    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    int getPosx() const;
    int getPosy() const;
};

#endif // BRICK_H
