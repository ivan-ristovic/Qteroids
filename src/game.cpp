#include "include/game.h"
#include "include/player.h"
#include <QGraphicsPixmapItem>
#include <QKeyEvent>


Game::Game(QGraphicsView *parentGraphicsView) :
    _parent(parentGraphicsView)
{
    // Add background image to the scene
    _bg.reset(new QGraphicsPixmapItem(QPixmap::fromImage(QImage("F:/Work/GitHub/asteroids/res/background.png"))));
    addItem(&(*_bg));

    // Create a new player
    _player.reset(new Player(width() / 2, height() / 2));
    addItem(&(*_player));

    // Start a new game ticker
    _gameTicker.reset(new QTimer());
    connect(&(*_gameTicker), SIGNAL(timeout()), this, SLOT(tick()));
    _gameTicker->setInterval(20);
    _gameTicker->start();
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A)
        _player->changeAngleBy(-5);
    else if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D)
        _player->changeAngleBy(5);
    else if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W)
        _player->accelerate();
    else if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S)
        _player->decelerate();
}

void Game::tick()
{
    _player->move();
}
