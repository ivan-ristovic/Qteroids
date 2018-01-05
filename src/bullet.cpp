#include "include/bullet.h"
#include <QtMath>
#include <QGraphicsScene>


Bullet::Bullet(qreal centerX, qreal centerY, qreal angle) :
    Entity(centerX - BULLET_SIZE_X / 2, centerY - BULLET_SIZE_Y / 2, BULLET_SIZE_X, BULLET_SIZE_Y, angle)
{
    _vx = 10 * cos(_angle * M_PI / 180);
    _vy = 10 * sin(_angle * M_PI / 180);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    setRotation(_angle);
    painter->fillRect(0, 0, _w, _h, QBrush(QPixmap("F:/Work/GitHub/asteroids/res/fire_blue.png")));
}

void Bullet::move()
{
    Entity::move();

    if (x() + _w < 0 || x() > scene()->width() || y() + _h < 0 || y() > scene()->height())
        emit outOfBounds(this);
}

