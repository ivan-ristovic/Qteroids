#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QScopedPointer>
#include "include/entity.h"


class Player : public Entity
{
    Q_OBJECT

public:
    /**
     * @brief       Player constructor
     * @param x     X position of the player in the scene
     * @param y     Y position of the player in the scene
     */
    Player(qreal x = 0, qreal y = 0);

    // Overrides from Entity
    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget) override;

    /**
     * @brief   Accelerates the player in the direction he is facing
     */
    void accelerate();

    /**
     * @brief   Slows the player down
     */
    void decelerate();

private:
    qreal _v;                           //!< Player speed
};

#endif // PLAYER_H
