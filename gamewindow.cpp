#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    ui->RedButton->setStyleSheet(QString("QPushButton {background-color: rgb(200,50,50);} QPushButton:pressed {background-color: rgb(255,150,150);}"));
    ui->BlueButton->setStyleSheet(QString("QPushButton {background-color: rgb(50,50,200);} QPushButton:pressed {background-color: rgb(150,150,255);}"));

    //QObject::connect(ui->penWidthSpinBox, (void (QSpinBox::*)(int))&QSpinBox::valueChanged, this, &DrawingDemo::valuesChanged);

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

void GameWindow::displayMoveSeries(std::vector<std::string> moveSeries){
    for(std::string move : moveSeries){
        if(move.compare("red") == 0){
            //TODO change this number as the score gets higher to make it harder
            ui->RedButton->animateClick(100);
        }else{
            ui->BlueButton->animateClick(100);
        }
    }
}

void GameWindow::computerTurn(std::vector<std::string> turnList){
    setBlueButton(false);
    setRedButton(false);
    setStartButton(false);

    displayMoveSeries(turnList);

    startPlayerTurn();
}

void GameWindow::startPlayerTurn(){
    setBlueButton(true);
    setRedButton(true);
    setStartButton(false);
}


void GameWindow::on_StartButton_clicked(){
    setBlueButton(false);
    setRedButton(false);
    setStartButton(false);

    emit updateWindow();
    emit startGameSignal();
}

void GameWindow::on_RedButton_clicked(){
    emit playerPlaySignal("red");
}

void GameWindow::on_BlueButton_clicked(){
    emit playerPlaySignal("blue");
}
