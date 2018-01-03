#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScopedPointer>
#include "include/game.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void startGame();

private:
    void MainWindow::connectSignalsToSlots();
    void MainWindow::initializeGameWindow();

    Ui::MainWindow *_ui;
    QScopedPointer<Game> _game;
};

#endif // MAINWINDOW_H
