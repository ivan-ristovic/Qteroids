#include "include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(width(), height());
    this->connectSignalsToSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::connectSignalsToSlots()
{
    connect(ui->pbStartGame, SIGNAL(clicked(bool)), this, SLOT(startGame()));
    connect(ui->pbExitGame, SIGNAL(clicked(bool)), this, SLOT(close()));
}

#include <QDebug>
void MainWindow::startGame()
{
    qDebug() << "started";
}
