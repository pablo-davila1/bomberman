#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QPainter>


class player  : public QGraphicsItem
{
    int posx,posy,width,higth;
public:
    player();
    player(int pos_x, int pos_y,int width_,int higth_);

    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) ;
    void move_lef();
    void move_rith();
    void move_up();
    void move_down();


    int getPosx() const;
    int getPosy() const;
};

#endif // PLAYER_H
