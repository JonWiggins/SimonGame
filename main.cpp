#include "gamewindow.h"
#include "gamemodel.h"
#include <QApplication>
#include <vector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameModel gameModel;

    GameWindow window;

    //TODO add all connections between view and model
    //QObject::connect(ui->penWidthSpinBox, (void (QSpinBox::*)(int))&QSpinBox::valueChanged, this, &DrawingDemo::valuesChanged);
    QObject::connect(&window, (void (GameWindow::*)(void))&GameWindow::updateWindow, &gameModel, &GameModel::updateWindow);
    QObject::connect(&window, (void (GameWindow::*)(void))&GameWindow::startGameSignal, &gameModel, &GameModel::startGame);
    QObject::connect(&gameModel, (void (GameModel::*)(int))&GameModel::setScoreSignal, &window, &GameWindow::setScore);
    QObject::connect(&gameModel, (void (GameModel::*)(int))&GameModel::setProgressSignal, &window, &GameWindow::setProgressBar);
    QObject::connect(&gameModel, (void (GameModel::*)(std::vector<std::string>))&GameModel::computerTurnSignal, &window, &GameWindow::startComputerTurn);
    QObject::connect(&gameModel, (void (GameModel::*)(void))&GameModel::GameOverSignal, &window, &GameWindow::gameOver);
    QObject::connect(&window, (void (GameWindow::*)(std::string))&GameWindow::playerPlaySignal, &gameModel, &GameModel::handlePlayersMove);
    QObject::connect(&gameModel, (void (GameModel::*)(void))&GameModel::pushRedSignal, &window, &GameWindow::pushRed);
    QObject::connect(&gameModel, (void (GameModel::*)(void))&GameModel::unpushRedSignal, &window, &GameWindow::unpushRed);
    QObject::connect(&gameModel, (void (GameModel::*)(void))&GameModel::pushBlueSignal, &window, &GameWindow::pushBlue);
    QObject::connect(&gameModel, (void (GameModel::*)(void))&GameModel::unpushBlueSignal, &window, &GameWindow::unpushBlue);
    QObject::connect(&gameModel, (void (GameModel::*)(void))&GameModel::startPlayerTurnSignal, &window, &GameWindow::startPlayerTurn);

    window.show();
    return a.exec();
}


void startGame(){

}
