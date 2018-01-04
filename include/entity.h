#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include <QGraphicsObject>

/**
 * @brief Provides a drawing base for all objects.
 */
class Entity : public QGraphicsObject
{
    Q_OBJECT

public:
    /**
     * @brief               Constructor
     * @param x             X position of the item in scene
     * @param y             Y position of the item in scene
     * @param w             Width
     * @param h             Height
     */
    Entity(qreal x, qreal y, qreal w, qreal h, qreal angle = -90, qreal vx = 0, qreal vy = 0);

    Entity(const Entity&);
    Entity& operator=(const Entity&);

    // Overrides from QGraphicsObject
    virtual QRectF boundingRect() const override;
    virtual QPainterPath shape() const override;
    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget) override;

    /**
     * @brief   Get entity height
     * @return  Entity height
     */
    qreal h() const;

    /**
     * @brief   Get entity width
     * @return  Entity width
     */
    qreal w() const;

    /**
     * @brief   Get entity rotation angle
     * @return  Entity rotation angle
     */
    qreal angle() const;

    /**
     * @brief   Entity move function
     */
    void move();


protected:
    qreal _w;           //!< Width
    qreal _h;           //!< Height
    qreal _angle;       //!< Rotation angle
    qreal _vx;          //!< X-Axis speed
    qreal _vy;          //!< Y-Axis speed
};

#endif // ENTITY_H
