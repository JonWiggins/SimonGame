#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <iostream>

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    ui->RedButton->setStyleSheet(QString("QPushButton {background-color: rgb(200,50,50);} QPushButton:pressed {background-color: rgb(255,150,150);}"));
    ui->BlueButton->setStyleSheet(QString("QPushButton {background-color: rgb(50,50,200);} QPushButton:pressed {background-color: rgb(150,150,255);}"));

    setBlueButton(false);
    setRedButton(false);
    setStartButton(true);
    setScore(0);
    setProgressBar(0);
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
    ui->progressBar->setRange(0, 100);
    std::cout << "set percentage: " << value << std::endl;
    ui->progressBar->setValue(value);
}

bool GameWindow::isEasyModeChecked(){
    return ui->EasyModeBox->checkState();
}

void GameWindow::pushRed(){
    ui->RedButton->setStyleSheet(QString("QPushButton {background-color: rgb(75,50,50);} QPushButton:pressed {background-color: rgb(255,150,150);}"));
}

void GameWindow::unpushRed(){
    ui->RedButton->setStyleSheet(QString("QPushButton {background-color: rgb(200,50,50);} QPushButton:pressed {background-color: rgb(255,150,150);}"));
}

void GameWindow::pushBlue(){
    ui->BlueButton->setStyleSheet(QString("QPushButton {background-color: rgb(50,50,75);} QPushButton:pressed {background-color: rgb(150,150,255);}"));
}

void GameWindow::unpushBlue(){
    ui->BlueButton->setStyleSheet(QString("QPushButton {background-color: rgb(50,50,200);} QPushButton:pressed {background-color: rgb(150,150,255);}"));
}

void GameWindow::startComputerTurn(){
    std::cout << "computer turn" << std::endl;

    setBlueButton(false);
    setRedButton(false);
    setStartButton(false);
}

void GameWindow::startPlayerTurn(){
    setBlueButton(true);
    setRedButton(true);
    setStartButton(false);
}

void GameWindow::gameOver(){
    std::cout << "game over" << std::endl;
    setBlueButton(false);
    setRedButton(false);
    setStartButton(true);
    setScore(0);
    setProgressBar(0);
    ui->GameOverLabel->setText("Game Over.");

}

void GameWindow::on_StartButton_clicked(){
    setBlueButton(false);
    setRedButton(false);
    setStartButton(false);
    ui->GameOverLabel->setText(QString(""));

    emit updateWindow();
    emit startGameSignal();
}

void GameWindow::on_RedButton_clicked(){
    emit playerPlaySignal("red");
}

void GameWindow::on_BlueButton_clicked(){
    emit playerPlaySignal("blue");
}
