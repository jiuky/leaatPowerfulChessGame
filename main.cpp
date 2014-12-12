/*
Created by Kaiyi Zhu.
For Programing in computing 10C project.
Bascially a easy implement of chess game, could be modified to other kind of chessboard based game.
 * */


#include "mainwindow.h"
#include "readme.h"
#include "gameboard.h"
#include <QWidget>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QGridLayout>
#include <random>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    MainWindow* w = new MainWindow;
    GameBoard* b = new GameBoard;
    readMe* r = new readMe;

    w->setGameBoard(b);
    w->callAbout(r);
    b->setMainWindow(w);
    r->setMainWindow(w);

    w->show();

    QObject::connect(w->quit, SIGNAL(clicked()), &a, SLOT(quit()));

    return a.exec();
}
