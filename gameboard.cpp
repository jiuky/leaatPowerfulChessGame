/*
 * This is the main game process window, all game-related stuff are here.
 * The amount of code is small in my opinion, considering how much it does and achieves.
 * */

#include "gameboard.h"

GameBoard::GameBoard(QWidget *parent) :
    QWidget(parent), board_size(8)
{
    /*
     * Creates the basic board using QgridLayout
     *
     * */
    Board = new QWidget;
    labels = new QLabel*[board_size*board_size];

    QGridLayout *SquareGrid = new QGridLayout(Board);
    SquareGrid->setGeometry(QRect());
    SquareGrid->setSpacing(0);

    toggle = false;

    /* Create each label for the board
     * Allocate the pieces' names to corresponding slots.
     * One may improve the graphics by using images instead of strings.
     * */
    for(int i=0;i<board_size;i++) {
        for(int j=0;j<board_size;j++) {
            if ((i==0)&&(j==0||j==7))
            {
                labels[i*board_size+j] = new QLabel("bRook");
                //labels[i*j]->setPixmap(*cursorImage);
            }
            else if((i==7)&&(j==0||j==7)){
                labels[i*board_size+j] = new QLabel("wRook");
            }
            else if((i==1)){
                labels[i*board_size+j] = new QLabel("bPawn");
            }
            else if((i==6)){
                labels[i*board_size+j] = new QLabel("wPawn");
            }
            else if((i==0)&&(j==1||j==6)){
                labels[i*board_size+j] = new QLabel("bKnight");
            }
            else if((i==7)&&(j==1||j==6)){
                labels[i*board_size+j] = new QLabel("wKnight");
            }
            else if((i==0)&&(j==2||j==5)){
                labels[i*board_size+j] = new QLabel("bBishop");
            }
            else if((i==7)&&(j==2||j==5)){
                labels[i*board_size+j] = new QLabel("wBishop");
            }
            else if((i==0)&&(j==3)){
                labels[i*board_size+j] = new QLabel("bKing");
            }
            else if((i==7)&&(j==3)){
                labels[i*board_size+j] = new QLabel("wKing");
            }
            else if((i==0)&&(j==4)){
                labels[i*board_size+j] = new QLabel("bQueen");
            }
            else if((i==7)&&(j==4)){
                labels[i*board_size+j] = new QLabel("wQueen");
            }
            else
            {
                labels[i*board_size+j]=new QLabel();
                labels[i*board_size+j]->setStyleSheet("QLabel { background-color : black; color : white; }");
            }

            labels[i*board_size+j]->setScaledContents(true);
            labels[i*board_size+j]->setMinimumSize(60,60);
            labels[i*board_size+j]->setMaximumSize(60,60);
            labels[i*board_size+j]->setAlignment(Qt::AlignCenter);
            labels[i*board_size+j]->setFrameStyle(3);

            // Add label to the layout
            SquareGrid -> addWidget(labels[i*board_size+j] ,i,j);
        }
    }
    cursorPosition = new QPoint(0,0);

    this->setLayout(SquareGrid);
}
/*
 * Keypressevent that receives input from keyboard and interacts accordingly.
 * */
void GameBoard::keyPressEvent(QKeyEvent *event){

    int x = cursorPosition->rx();
    int y = cursorPosition->ry();

    if(event->key()==(Qt::Key_Left)){
        if(cursorPosition->rx() != 0)
            moveCursor(x, y, x-1, y);
    }
    else if (event->key()==Qt::Key_Right){
        if(cursorPosition->rx() != board_size-1)
            moveCursor(x, y, x+1, y);
    }
    else if (event->key()==Qt::Key_Up){
        if(cursorPosition->ry() != 0)
            moveCursor(x, y, x, y-1);
    }
    else if (event->key()==Qt::Key_Down){
        if(cursorPosition->ry() != board_size-1)
            moveCursor(x, y, x, y+1);
    }
    else if (event->key()==Qt::Key_C){
        toggleStatus(0);
    }
    else if ((toggle == false)&&(event->key()==Qt::Key_X)){
        toggleStatus(1);
        selectedPiece = getCoordinates(x,y);
    }
    else if ((toggle == true)&&(event->key()==Qt::Key_X)){
        targetedCoordinate = getCoordinates(x,y);
        movePiece(selectedPiece, targetedCoordinate);
        toggleStatus(0);
    }
    else{
        QWidget::keyPressEvent(event);
    }

    return;
}

/*
 * The below three functions mimic the cursor implementing.
 * Took me sometime to figure it out.
 * */
void GameBoard::paintEvent(QPaintEvent *e) {

    int x = cursorPosition->rx();
    int y = cursorPosition->ry();

    labels[y*board_size+x]->setStyleSheet("QLabel { background-color : orange; color : white; }");
    labels[y*board_size+x]->setScaledContents(true);

}

void GameBoard::moveCursor(int i, int j, int nx, int ny) {

    QString str = labels[j*board_size+i]->text();
    labels[j*board_size+i]->setText(str);
    labels[j*board_size+i]->setStyleSheet("QLabel { background-color : black; color : white; }");

    cursorPosition->setX(nx);
    cursorPosition->setY(ny);
    repaint();
}

void GameBoard::movePiece(QPoint *sP, QPoint *tC){
    int sPx = sP->rx();
    int sPy = sP->ry();

    int tCx = tC->rx();
    int tCy = tC->ry();

    QString str = labels[sPy*board_size+sPx]->text();

    labels[tCy*board_size+tCx]->clear();
    labels[tCy*board_size+tCx]->setText(str);
    labels[sPy*board_size+sPx]->clear();
}
/*
 * Some supporting functions.
 * */
QPoint* GameBoard::getCoordinates(int i, int j){
    QPoint* qp = new QPoint(i , j);
    return qp;
}
/*
 * The toggle function is kind of important for the cursor's features.
 * */

void GameBoard::toggleStatus(int n){
    if (n==1){
        toggle = true;}
    else if (n==0){
        toggle = false;}
}

GameBoard::~GameBoard() {
    //delete labels[];
   }

void GameBoard::setMainWindow(MainWindow* main_window) {
    mw = main_window;

}


