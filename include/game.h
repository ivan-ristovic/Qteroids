#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QBrush>
#include <QGraphicsView>
#include <QScopedPointer>
#include <QTimer>
#include <QVector>
#include "include/entity.h"
#include "include/player.h"
#include "include/asteroid.h"
#include "include/bullet.h"


class Game : public QGraphicsScene
{
    Q_OBJECT

public:
    Game(QGraphicsView *parentGraphicsView);

    // Deleted functions
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    ~Game();

    // Event overrides
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    void stop();

signals:
    void gameOver();

private slots:
    void tick();
    void deleteBullet(Bullet*);
    void deleteAsteroid(Asteroid*);

private:
    bool _gameOver;
    QGraphicsView *_parent;                     //!< Parent view representing the current scene (this)
    QScopedPointer<QGraphicsPixmapItem> _bg;    //!< Background image pointer
    QScopedPointer<Player> _player;             //!< Player pointer
    QScopedPointer<QTimer> _gameTicker;         //!< Game ticker
    QVector<Bullet *> _bullets;                 //!< Holds the bullets currently on the scene
    QVector<Asteroid *> _asteroids;             //!< Holds the asteroids currently on the scene
};

#endif // GAME_H
