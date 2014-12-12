#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include "mainwindow.h"
#include <QMainWindow>
#include <QKeyEvent>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <iostream>

class GameBoard : public QWidget
{
    Q_OBJECT


public:
    explicit GameBoard(QWidget *parent = 0);
    ~GameBoard();

    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *event);
    void moveCursor(int py, int px, int nx, int ny);
    void toggleStatus(int n);
    QPoint* getCoordinates(int i, int j);
    void movePiece(QPoint *sP, QPoint *tC);

    void setMainWindow(MainWindow* main_window);

private:

   QPoint *cursorPosition;
   QPoint* selectedPiece;
   QPoint* targetedCoordinate;
   QPixmap* cursorImage;
   QLabel* globalTemp;
   bool toggle;

   // Board Variables
   QWidget *Board;
   int board_size;
   QLabel** labels;
   int* values;


   MainWindow* mw;
};

#endif // GAMEBOARD_H
