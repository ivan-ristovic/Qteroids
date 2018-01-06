#include "include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
    setFixedSize(width(), height());
    connectSignalsToSlots();
}

MainWindow::~MainWindow()
{
    delete _ui;
}


void MainWindow::connectSignalsToSlots()
{
    connect(_ui->pbStartGame, SIGNAL(clicked(bool)), this, SLOT(startGame()));
    connect(_ui->pbExitGame, SIGNAL(clicked(bool)), this, SLOT(close()));
}

void MainWindow::initializeGameWindow()
{
    _ui->gvScene->setScene(&(*_game));
    _ui->gvScene->raise();
    _ui->gvScene->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _ui->gvScene->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void MainWindow::startGame()
{
    _ui->frMainMenu->hide();
    _ui->gvScene->setFocus();
    _game.reset(new Game(_ui->gvScene));
    initializeGameWindow();
    connect(&(*_game), SIGNAL(gameOver()), this, SLOT(stopGame()));
}

void MainWindow::stopGame()
{
    _ui->frMainMenu->show();
    _ui->frMainMenu->raise();
    _ui->frMainMenu->setFocus();
}
