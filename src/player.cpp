#include "include/player.h"

Player::Player(qreal x, qreal y) :
    Entity::Entity(x - 20, y - 20, 40, 40),
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
    return x() + 20;
}

qreal Player::centerY() const
{
    return y() + 20;
}

void Player::move()
{

}

#include <QDebug>
void Player::accelerate()
{
    qDebug() << "accelerating";
}

void Player::decelerate()
{
    qDebug() << "decelerating";
}
