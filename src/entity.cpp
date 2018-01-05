#include "include/entity.h"
#include <QGraphicsObject>
#include <QPainter>
#include <QPainterPath>
#include <QRectF>


Entity::Entity(qreal x, qreal y, qreal w, qreal h, qreal angle, qreal vx, qreal vy) :
    _w(w),
    _h(h),
    _angle(angle),
    _vx(vx),
    _vy(vy)
{
    setPos(x, y);
    setTransformOriginPoint(_w/2, _h/2);
    setRotation(angle);
}

Entity::Entity(const Entity &e) :
    _w(e.w()),
    _h(e.h()),
    _angle(e.angle())
{
    setPos(e.x(), e.y());
}

Entity &Entity::operator=(const Entity &e)
{
    Entity temp(e);
    std::swap(*this, temp);
    return *this;
}

QRectF Entity::boundingRect() const
{
    return QRectF(0, 0, _w, _h);
}

QPainterPath Entity::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, _w, _h);
    return path;
}

void Entity::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->fillRect(0, 0, _w, _h, Qt::white);
}

qreal Entity::h() const
{
    return _h;
}

qreal Entity::w() const
{
    return _w;
}

qreal Entity::centerX() const
{
    return x() + _w/2;
}

qreal Entity::centerY() const
{
    return y() + _h/2;
}

qreal Entity::angle() const
{
    return _angle;
}

void Entity::move()
{
    setX(x() + _vx);
    setY(y() + _vy);
}
