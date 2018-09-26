#include "include/player.h"
#include <QGraphicsScene>
#include <QtMath>

Player::Player(qreal x, qreal y) :
    Entity::Entity(x - PLAYER_SIZE/2, y - PLAYER_SIZE/2, PLAYER_SIZE, PLAYER_SIZE),
    _angleModifier(0),
    _thrust(false)
{

}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    setRotation(_angle);
    painter->fillRect(0, 0, _w, _h, QBrush(QPixmap("F:/Work/GitHub/asteroids/res/spaceship_cut.png")));
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

    if (std::abs(_vx) < 0.01)
        _vx = 0;
    if (std::abs(_vy) < 0.01)
        _vy = 0;

    Entity::move();

    if (x() + _w < 0)
        setX(scene()->width());
    if (x() > scene()->width())
        setX(0);
    if (y() + _h < 0)
        setY(scene()->height());
    if (y() > scene()->height())
        setY(0);
}

void Player::setAngleModifier(const qreal &angleModifier)
{
    _angleModifier = angleModifier;
}

void Player::setThrust(bool thrust)
{
    _thrust = thrust;
}
