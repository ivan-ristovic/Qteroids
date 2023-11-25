#include "include/asteroid.h"
#include <QGraphicsScene>


Asteroid::Asteroid(qreal x, qreal y, qreal vx, qreal vy, qreal anglemod) :
    Entity(x, y, ASTEROID_SIZE_X, ASTEROID_SIZE_Y, 0, vx, vy),
    _angleModifier(anglemod)
{

}

void Asteroid::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    setRotation(_angle);
    painter->fillRect(0, 0, _w, _h, QBrush(QPixmap(":/res/rock_cut.png")));
}

void Asteroid::move()
{
    _angle += _angleModifier;
    if (_angle > 360)
        _angle -= 360;
    else if (_angle < -360)
        _angle += 360;

    Entity::move();

    if (x() + _w < 0 || x() > scene()->width() || y() + _h < 0 || y() > scene()->height())
        emit outOfBounds(this);
}
