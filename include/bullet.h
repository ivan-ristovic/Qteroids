#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include "include/entity.h"


class Bullet : public Entity
{
    Q_OBJECT

public:
    const static int BULLET_SIZE_X = 64;
    const static int BULLET_SIZE_Y = 32;

    Bullet(qreal centerX, qreal centerY, qreal angle);

    // Overrides from Entity
    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget) override;
    virtual void move() override;

signals:
    void outOfBounds(Bullet *);
};

#endif // BULLET_H
