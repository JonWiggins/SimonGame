#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    ui->RedButton->setStyleSheet( QString("QPushButton {background-color: rgb(200,50,50);} QPushButton:pressed {background-color: rgb(255,150,150);}"));
    ui->BlueButton->setStyleSheet(QString("QPushButton {background-color: rgb(50,50,200);} QPushButton:pressed {background-color: rgb(150,150,255);}"));
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::setScore(int score){
    ui->ScoreValue->setText(QString::number(score));
}

void GameWindow::setStartButton(bool active){
    ui->StartButton->setEnabled(active);
}

void GameWindow::setBlueButton(bool active){
    ui->BlueButton->setEnabled(active);
}

void GameWindow::setRedButton(bool active){
    ui->RedButton->setEnabled(active);
}

void GameWindow::setProgressBar(int value){
    ui->progressBar->setValue(value);
}

bool GameWindow::isEasyModeChecked(){
    return ui->EasyModeBox->checkState();
}
