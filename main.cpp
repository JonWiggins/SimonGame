/**
    CS 3505: A5
    Purpose: Construct the Simon Game, create a view and Model and connect them using Signals and Slots

    @author Conner Soule and Jonathan Wiggins
    @version 10/23/18
*/

#include "gamewindow.h"
#include "gamemodel.h"
#include <QApplication>
#include <vector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameModel gameModel;

    GameWindow window;

    //All the connections needed to connect the slots and signals of the view and the model
    QObject::connect(&window, (void (GameWindow::*)(void))&GameWindow::updateWindow, &gameModel, &GameModel::updateWindow);
    QObject::connect(&window, (void (GameWindow::*)(bool))&GameWindow::startGameSignal, &gameModel, &GameModel::startGame);
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
    QObject::connect(&gameModel, (void (GameModel::*)(void))&GameModel::disableBlueSignal, &window, &GameWindow::disableBlue);
    QObject::connect(&gameModel, (void (GameModel::*)(void))&GameModel::disableRedSignal, &window, &GameWindow::disableRed);
    QObject::connect(&window, (void (GameWindow::*)(void))&GameWindow::quitGameSignal, &gameModel, &GameModel::quitGame);

    window.show();
    return a.exec();
}


void startGame(){

}
