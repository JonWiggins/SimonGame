#include "gamemodel.h"
#include <iostream>

GameModel::GameModel(){

    this->currentScore = 0;
}

std::vector<std::string> GameModel::getMoves(){
    return this->correctSeries;
}

void GameModel::createNextMove(){
    int newNumber= rand() % 2;

    //debug
    std::cout << "New Number is: " << newNumber << std::endl;

    if(newNumber == 0){
        this->correctSeries.push_back("red");
    }else{
        this->correctSeries.push_back("blue");
    }
}

void GameModel::handlePlayersMove(std::string move){

    currentSeries.push_back(move);

    for(uint index = 0; index < currentSeries.size(); index++){
        if(this->currentSeries[index].compare(this->correctSeries[index]) != 0 ){
            emit GameOverSignal();
        }
    }

    this->currentScore++;

    if(this->correctSeries.size() == this->currentSeries.size()){
        resetRound();
        createNextMove();
        emit computerTurnSignal(this->currentSeries);
    }
}

void GameModel::resetGame(){
    this->currentScore = 0;
    this->correctSeries.clear();
    this->currentSeries.clear();
}

void GameModel::resetRound(){
    this->currentSeries.clear();

}

void GameModel::startGame(){
    createNextMove();
    resetGame();
    emit computerTurnSignal(this->currentSeries);
}

int GameModel::getCurrentProgress(){
    if(this->correctSeries.size() == 0)
        return 0;

    return (100 * (currentSeries.size() / correctSeries.size()));
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
