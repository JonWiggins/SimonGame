#include "gamemodel.h"
#include <iostream>
#include <QTimer>

GameModel::GameModel(){

    this->currentScore = 0;
}

GameModel::~GameModel(){
    this->currentSeries.clear();
    this->correctSeries.clear();
}

std::vector<std::string> GameModel::getMoves(){
    return this->correctSeries;
}

void GameModel::createNextMove(){
    int newNumber= rand() % 2;

    //debug

    if(newNumber == 0){
        std::cout << "New move is: red"<< std::endl;
        this->correctSeries.push_back("red");
    }else{
        std::cout << "New move is: blue"<< std::endl;
        this->correctSeries.push_back("blue");
    }
}

void GameModel::handlePlayersMove(std::string move){
    std::cout << "Handling move " << move << std::endl;
    currentSeries.push_back(move);

    for(uint index = 0; index < currentSeries.size(); index++){
        if(this->currentSeries[index].compare(this->correctSeries[index]) != 0 ){
            resetGame();
            emit GameOverSignal();
            return;
        }

    }
    updateWindow();

    if(this->correctSeries.size() == this->currentSeries.size()){
        this->currentScore++;
        resetRound();
        createNextMove();
        updateWindow();
        computerTurn();
    }
}

void GameModel::resetGame(){
    std::cout << "reseting game" << std::endl;
    this->currentScore = 0;
    this->correctSeries.clear();
    this->currentSeries.clear();
}

void GameModel::resetRound(){
    this->currentSeries.clear();

}

void GameModel::computerTurn(){
    for(std::string move : correctSeries){
        if(move.compare("red") == 0){
            emit pushRedSignal(); //TODO change based on length
            QTimer::singleShot(100, this, &GameModel::unpushRedSignal);
        }else{
            emit pushBlueSignal();
            QTimer::singleShot(100, this, &GameModel::unpushBlueSignal);
        }
    }

}

void GameModel::startGame(){
    std::cout << "starting game" << std::endl;
    resetGame();
    createNextMove();
    computerTurn();
}

int GameModel::getCurrentProgress(){
    if(this->correctSeries.size() == 0)
        return 0;

    std::cout << "current series size " << currentSeries.size() << std::endl;
    std::cout << "correct series size " << correctSeries.size() << std::endl;
    int result = (100 * currentSeries.size()) / (correctSeries.size());
    std::cout << "result " << result << std::endl;
    return result;
}

int GameModel::getCurrentScore(){
    return this->currentScore;
}

void GameModel::updateWindow(){
    emit setProgressSignal(getCurrentProgress());
    emit setScoreSignal(this->currentScore);
}

std::string GameModel::getNextColor(){
    if(this->currentScore == 0)
        return nullptr;
    return this->correctSeries[this->currentSeries.size()];
}
