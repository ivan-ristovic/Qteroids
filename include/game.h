#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsView>
#include <QScopedPointer>
#include <QTimer>
#include <QVector>
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

    // Event overrides
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void tick();

private:
    QGraphicsView *_parent;                     //!< Parent view representing the current scene (this)
    QScopedPointer<QGraphicsPixmapItem> _bg;    //!< Background image pointer
    QScopedPointer<Player> _player;             //!< Player pointer
    QScopedPointer<QTimer> _gameTicker;         //!< Game ticker
};

#endif // GAME_H
