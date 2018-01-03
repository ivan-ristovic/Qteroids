#include "include/game.h"
#include "include/player.h"
#include <QGraphicsPixmapItem>

Game::Game(QGraphicsView *parentGraphicsView) :
    _parent(parentGraphicsView)
{
    _bg.reset(new QGraphicsPixmapItem(QPixmap::fromImage(QImage("F:/Work/GitHub/asteroids/res/background.png"))));
    addItem(&(*_bg));
    _player.reset(new Player(width() / 2, height() / 2));
    addItem(&(*_player));
}
