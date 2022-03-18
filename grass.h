#ifndef GRASS_H
#define GRASS_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>


class grass : public QGraphicsItem
{
    int posx,posy,width,higth;
public:
    grass();
    grass(int pos_x, int pos_y,int width_,int higth_);

    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) ;
};

#endif // GRASS_H
