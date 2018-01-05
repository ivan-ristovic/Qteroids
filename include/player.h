#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QScopedPointer>
#include "include/entity.h"


class Player : public Entity
{
    Q_OBJECT

public:
    Player(qreal x = 0, qreal y = 0);

    // Overrides from Entity
    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget) override;
    virtual void move() override;

    void setAngleModifier(const qreal &angleModifier);
    void setThrust(bool thrust);

private:
    qreal _angleModifier;       //!< How much the angle changes per tick
    bool _thrust;               //!< Determines whether the thrust is applied
};

#endif // PLAYER_H
