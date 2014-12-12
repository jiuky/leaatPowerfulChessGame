#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <random>
#include <chrono>
#include <QTimer>
#include <QPushButton>
#include <iostream>



#include <QRadioButton>

class GameBoard;
class readMe;

class MainWindow : public QMainWindow
{
    Q_OBJECT

 public slots:

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    void setGameBoard(GameBoard* game_board);
    void callAbout(readMe* read_me);
    void closeEvent(QCloseEvent *e);

    QPushButton* quit;
private:

    GameBoard* board;
    readMe* rm;


    QLabel* hihihi;

    QPushButton* letsStart;
    QPushButton* aboutGame;


    QVBoxLayout* menu;
    QVBoxLayout* atLast;
    QWidget* central;

};

#endif // MAINWINDOW_H
