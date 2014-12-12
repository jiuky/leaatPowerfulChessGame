/*
 * This is the starting window
 * Containing 3 buttons, start, about, and quit.
 * */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "readme.h"
#include "gameboard.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    hihihi = new QLabel("This is the world least powerful chess game");

    letsStart = new QPushButton("Start");
    aboutGame = new QPushButton("About");
    quit = new QPushButton("Quit");

    menu = new QVBoxLayout;
    menu->addWidget(hihihi);
    menu->addWidget(letsStart);
    menu->addWidget(aboutGame);
    menu->addWidget(quit);

    central = new QWidget;
    central->setLayout(menu);

    this->setCentralWidget(central);


}

MainWindow::~MainWindow()
{

}

void MainWindow::callAbout(readMe* read_me){
    rm = read_me;
    QObject::connect(aboutGame, SIGNAL(clicked()), rm, SLOT(show()));

}

void MainWindow::setGameBoard(GameBoard* game_board) {
    board = game_board;
    QObject::connect(letsStart, SIGNAL(clicked()), board, SLOT(show()));
}


void MainWindow::closeEvent(QCloseEvent *e) {
    e->accept();
}



