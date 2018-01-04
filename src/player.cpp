#include "include/player.h"
#include <QtMath>

Player::Player(qreal x, qreal y) :
    Entity::Entity(x - 20, y - 20, 40, 40),
    _angleModifier(0)
{

}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    setRotation(_angle);
    Entity::paint(painter, option, widget);
}

void Player::move()
{
    Entity::move();
    _angle += _angleModifier;
    if (_angle > 360)
        _angle -= 360;
    else if (_angle < -360)
        _angle += 360;
}

void Player::accelerate()
{
    _vx = 5 * cos(_angle * M_PI / 180);
    _vy = 5 * sin(_angle * M_PI / 180);
    _angleModifier = 0;
}

void Player::decelerate()
{
    _vx /= 2;
    _vy /= 2;
    if (_vx < 1)
        _vx = 0;
    if (_vy < 1)
        _vy = 0;
}

void Player::setAngleModifier(const qreal &angleModifier)
{
    _angleModifier = angleModifier;
}
