#include "include/game.h"
#include "include/player.h"
#include "include/asteroid.h"
#include <QGraphicsPixmapItem>
#include <QKeyEvent>


Game::Game(QGraphicsView *parentGraphicsView) :
    _gameOver(false),
    _parent(parentGraphicsView)
{
    setSceneRect(0, 0, _parent->width(), _parent->height());

    // Add background image to the scene
    _bg.reset(new QGraphicsPixmapItem(QPixmap::fromImage(QImage(":/res/background.png"))));
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

Game::~Game()
{
    foreach (auto b, _bullets)
        delete b;
    foreach (auto a, _asteroids)
        delete a;
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if (_gameOver)
        return;

    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A)
        _player->setAngleModifier(-5);
    else if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D)
        _player->setAngleModifier(5);
    else if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W)
        _player->setThrust(true);
    else if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S)
        _player->setThrust(false);
    else if (event->key() == Qt::Key_Space) {
        Bullet *b = new Bullet(_player->centerX(), _player->centerY(), _player->angle());
        _bullets.push_back(b);
        addItem(b);
        connect(b, SIGNAL(outOfBounds(Bullet*)), this, SLOT(deleteBullet(Bullet*)));
    }
}

void Game::keyReleaseEvent(QKeyEvent *event)
{
    if (_gameOver)
        return;

    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A || event->key() == Qt::Key_Right || event->key() == Qt::Key_D)
        _player->setAngleModifier(0);
    else if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W)
        _player->setThrust(false);
}

void Game::tick()
{
    if (_gameOver)
        return;

    _player->move();
    foreach (auto bullet, _bullets) {
        bullet->move();
    }
    foreach (auto asteroid, _asteroids) {
        if (asteroid->collidesWithItem(&(*_player))) {
            _gameOver = true;
            emit gameOver();
            break;
        }

        bool destroyed = false;
        foreach (auto bullet, _bullets) {
            if (asteroid->collidesWithItem(&(*bullet))) {
                deleteBullet(bullet);
                deleteAsteroid(asteroid);
                destroyed = true;
                break;
            }
        }

        if (!destroyed)
            asteroid->move();
    }

    if (_asteroids.length() < 10) {
        Asteroid *a;
        qreal x = qrand() % (int)width();
        qreal y = qrand() % (int)height();
        qreal speed_x = qrand() % Asteroid::MAX_ASTEROID_SPEED + 1;
        qreal speed_y = qrand() % Asteroid::MAX_ASTEROID_SPEED + 1;
        qreal anglemod = qrand() % 10;
        if (qrand() % 2 == 0)
            a = new Asteroid(0, y, speed_x, speed_y, anglemod);
        else
            a = new Asteroid(x, 0, speed_x, speed_y, anglemod);
        _asteroids.push_back(a);
        connect(a, SIGNAL(outOfBounds(Asteroid*)), this, SLOT(deleteAsteroid(Asteroid*)));
        addItem(a);
    }
}

void Game::deleteBullet(Bullet *b)
{
    _bullets.removeAll(b);
    delete b;
}

void Game::deleteAsteroid(Asteroid *a)
{
    _asteroids.removeAll(a);
    disconnect(a, SIGNAL(outOfBounds(Asteroid*)), this, SLOT(deleteAsteroid(Asteroid*)));
    delete a;
}
