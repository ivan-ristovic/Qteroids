#ifndef ASTEROID_H
#define ASTEROID_H

#include <QObject>
#include "include/entity.h"

class Asteroid : public Entity
{
    Q_OBJECT

public:
    const static int ASTEROID_SIZE_X = 40;
    const static int ASTEROID_SIZE_Y = 50;
    const static int MAX_ASTEROID_SPEED = 10;

    Asteroid(qreal x, qreal y, qreal vx, qreal vy, qreal anglemod);

    // Overrides from Entity
    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget) override;
    virtual void move() override;

signals:
    void outOfBounds(Asteroid *);

private:
    qreal _angleModifier;       //!< How much the angle changes per tick
};

#endif // ASTEROID_H
