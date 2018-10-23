/**
    CS 3505: A5
    Purpose: Implement the GameWindow view for the Simon Game

    @author Conner Soule and Jonathan Wiggins
    @version 10/23/18
*/

#include "gamewindow.h"
#include "ui_gamewindow.h"

//Creates a new GameWindow, from the given QWidget window it is in
GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    ui->RedButton->setStyleSheet(QString("QPushButton {background-color: rgb(200,50,50);} QPushButton:pressed {background-color: rgb(255,150,150);}"));
    ui->BlueButton->setStyleSheet(QString("QPushButton {background-color: rgb(50,50,200);} QPushButton:pressed {background-color: rgb(150,150,255);}"));

    ui->BlueButton->setEnabled(false);
    ui->RedButton->setEnabled(false);
    ui->StartButton->setEnabled(true);
    ui->EasyModeBox->setEnabled(true);
    ui->QuitButton->setEnabled(false);

    setScore(0);
    setProgressBar(0);
}

//Deconstructs this GameWindow
GameWindow::~GameWindow()
{
    delete ui;
}

//Sets the score to the given int
void GameWindow::setScore(int score){
    ui->ScoreValue->setText(QString::number(score));
}

//Sets the progress bar to the given int
void GameWindow::setProgressBar(int value){
    ui->progressBar->setRange(0, 100);
    ui->progressBar->setValue(value);
}

//Changes the style of the red button so it appears pressed
void GameWindow::pushRed(){
    ui->RedButton->setStyleSheet(QString("QPushButton {background-color: rgb(75,50,50);} QPushButton:pressed {background-color: rgb(255,150,150);}"));
}

//Resets the style of the red button
void GameWindow::unpushRed(){
    ui->RedButton->setStyleSheet(QString("QPushButton {background-color: rgb(200,50,50);} QPushButton:pressed {background-color: rgb(255,150,150);}"));
}

//Changes the style of the blue button so it appears pressed
void GameWindow::pushBlue(){
    ui->BlueButton->setStyleSheet(QString("QPushButton {background-color: rgb(50,50,75);} QPushButton:pressed {background-color: rgb(150,150,255);}"));
}

//Resets the style of the blue button
void GameWindow::unpushBlue(){
    ui->BlueButton->setStyleSheet(QString("QPushButton {background-color: rgb(50,50,200);} QPushButton:pressed {background-color: rgb(150,150,255);}"));
}

//Disables the blue button so the user cannot press it, this is used for easy mode
void GameWindow::disableBlue(){
    ui->BlueButton->setEnabled(false);
}

//Disables the red button so the user cannot press it, this is used for easy mode
void GameWindow::disableRed(){
    ui->RedButton->setEnabled(false);
}

//Disables the buttons so the computer can do its turn
void GameWindow::startComputerTurn(){
    ui->BlueButton->setEnabled(false);
    ui->RedButton->setEnabled(false);
    ui->StartButton->setEnabled(false);
    ui->QuitButton->setEnabled(false);
}

//Sets the buttons for a player to begin their turn
void GameWindow::startPlayerTurn(){
    ui->BlueButton->setEnabled(true);
    ui->RedButton->setEnabled(true);
    ui->StartButton->setEnabled(false);
    ui->QuitButton->setEnabled(true);
}

//Resets the game buttons and displays the game over message
void GameWindow::gameOver(){
    ui->BlueButton->setEnabled(false);
    ui->RedButton->setEnabled(false);
    ui->StartButton->setEnabled(true);
    ui->EasyModeBox->setEnabled(true);

    setProgressBar(0);
    ui->GameOverLabel->setText("Game Over.");

}

//Handles the user pressing the start button
void GameWindow::on_StartButton_clicked(){    
    ui->BlueButton->setEnabled(false);
    ui->BlueButton->setEnabled(false);
    ui->StartButton->setEnabled(false);

    ui->GameOverLabel->setText(QString(""));
    ui->EasyModeBox->setEnabled(false);

    emit updateWindow();
    emit startGameSignal(ui->EasyModeBox->isChecked());
}

//Handles the user pressing the Red Button
void GameWindow::on_RedButton_clicked(){
    ui->BlueButton->setEnabled(true);
    emit playerPlaySignal("red");
}

//Handles the user pressing the blue button
void GameWindow::on_BlueButton_clicked(){
    ui->RedButton->setEnabled(true);
    emit playerPlaySignal("blue");
}

//Handles the quit button being pressed
void GameWindow::on_QuitButton_clicked()
{
    emit quitGameSignal();
}
