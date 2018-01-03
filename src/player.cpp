#include "include/player.h"

Player::Player(qreal x, qreal y) :
    Entity::Entity(x, y, 40, 40),
    _v(0)
{

}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    setRotation(_angle);
    Entity::paint(painter, option, widget);
}

qreal Player::centerX() const
{
    return x() + _w/2;
}

qreal Player::centerY() const
{
    return y() + _h/2;
}
