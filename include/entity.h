#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>

/**
 * @brief Provides a drawing base for all objects.
 */
class Entity : public QGraphicsItem
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
    Entity(qreal x, qreal y, qreal w, qreal h, qreal angle = 0);

    // Overrides from QGraphicsObject
    virtual void hide();
    virtual void show();
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
     * @brief   Get X coordinate of the center in parent coordinate system
     * @return  X coordinate of the center
     */
    virtual qreal centerX() const;

    /**
     * @brief   Get Y coordinate of the center in parent coordinate system
     * @return  Y coordinate of the center
     */
    virtual qreal centerY() const;


protected:
    qreal _w;           //!< Width
    qreal _h;           //!< Height
    qreal _angle;       //!< Rotation angle
};

#endif // ENTITY_H
