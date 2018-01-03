#include "include/entity.h"
#include <QGraphicsObject>
#include <QPainterPath>
#include <QRectF>


Entity::Entity(qreal x, qreal y, qreal w, qreal h, qreal angle = 0) :
    _w(w),
    _h(h),
    _angle(angle)
{
    setPos(x, y);
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
    painter->drawRect(0, 0, _w, _h);
}

void Entity::hide()
{
    QGraphicsObject::hide();
}

void Entity::show()
{
    QGraphicsObject::show();
}

qreal Entity::h() const
{
    return _h;
}

qreal Entity::w() const
{
    return _w;
}

qreal Entity::angle() const
{
    return _angle;
}

qreal Entity::centerX() const
{
    return x();
}

qreal Entity::centerY() const
{
    return y();
}
