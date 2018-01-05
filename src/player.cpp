#include "include/player.h"
#include <QtMath>

Player::Player(qreal x, qreal y) :
    Entity::Entity(x - 20, y - 20, 40, 40),
    _angleModifier(0),
    _thrust(false)
{

}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    setRotation(_angle);
    Entity::paint(painter, option, widget);
}

void Player::move()
{
    _angle += _angleModifier;
    if (_angle > 360)
        _angle -= 360;
    else if (_angle < -360)
        _angle += 360;

    if (_thrust) {
        _vx = 5 * cos(_angle * M_PI / 180);
        _vy = 5 * sin(_angle * M_PI / 180);
    } else {
        _vx *= 0.99;
        _vy *= 0.99;
    }

    if (std::abs(_vx) < 0.001)
        _vx = 0;
    if (std::abs(_vy) < 0.001)
        _vy = 0;

    Entity::move();
}

void Player::setAngleModifier(const qreal &angleModifier)
{
    _angleModifier = angleModifier;
}

void Player::setThrust(bool thrust)
{
    _thrust = thrust;
}
