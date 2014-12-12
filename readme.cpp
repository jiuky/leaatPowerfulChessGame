#include "readme.h"
/*
 The readme portion which teaches how to play, nothing special.
*/
readMe::readMe(QWidget *parent) :
  QWidget(parent)
{
    temp1 = new QLabel("Press X to select piece, press X again to set the selected piece. Press C to cancel any selection.");
    temp2 = new QVBoxLayout;
    //temp2->setFixedSize(400,400);
    temp2->addWidget(temp1);
    this->setLayout(temp2);

}

void readMe::setMainWindow(MainWindow* main_window) {
    mW = main_window;
}

readMe::~readMe(){


}
