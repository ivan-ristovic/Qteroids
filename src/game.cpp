#include "include/game.h"
#include "include/player.h"
#include <QGraphicsPixmapItem>


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

void Game::tick()
{
    _player->move();
}
