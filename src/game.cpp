#include "include/game.h"
#include <QGraphicsPixmapItem>
#include <QDebug>

Game::Game(QGraphicsView *parentGraphicsView) :
    _parent(parentGraphicsView)
{
    _bg.reset(new QGraphicsPixmapItem(QPixmap::fromImage(QImage("F:/Work/GitHub/asteroids/res/background.png"))));
    addItem(&(*_bg));
}
