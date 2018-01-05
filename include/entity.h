#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include <QPainter>
#include <QPainterPath>
#include <QGraphicsObject>


class Entity : public QGraphicsObject
{
    Q_OBJECT

public:
    Entity(qreal x, qreal y, qreal w, qreal h, qreal angle = -90, qreal vx = 0, qreal vy = 0);
    Entity(const Entity&);
    Entity& operator=(const Entity&);

    // Overrides from QGraphicsObject
    virtual QRectF boundingRect() const override;
    virtual QPainterPath shape() const override;
    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget) override;

    qreal h() const;
    qreal w() const;
    qreal centerX() const;
    qreal centerY() const;
    qreal angle() const;
    virtual void move();

protected:
    qreal _w;           //!< Width
    qreal _h;           //!< Height
    qreal _angle;       //!< Rotation angle
    qreal _vx;          //!< X-Axis speed
    qreal _vy;          //!< Y-Axis speed
};

#endif // ENTITY_H
