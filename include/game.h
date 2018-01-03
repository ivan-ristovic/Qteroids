#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsView>
#include <QScopedPointer>
#include "include/player.h"

/**
 * @brief The Asteroids Game class.
 */
class Game : public QGraphicsScene
{
    Q_OBJECT

public:
    Game(QGraphicsView *parentGraphicsView);

    // Deleted functions
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

private:
    QGraphicsView *_parent;                     //!< Parent view representing the current scene (this).
    QScopedPointer<QGraphicsPixmapItem> _bg;    //!< Background image pointer.
    QScopedPointer<Player> _player;             //!< Player pointer.
};

#endif // GAME_H
