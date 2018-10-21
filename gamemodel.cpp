#include "gamemodel.h"
#include <iostream>

GameModel::GameModel()
{
    this->currentScore = 0;
    this->currentProgress = 0;
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

bool GameModel::handlePlayersMove(std::string move){
    if(this->correctSeries[this->currentScore].compare(move) == 0){
        this->currentScore++;
        return true;
    }else{
        return false;
    }
}

void GameModel::resetGame(){
    this->currentScore = 0;
    this->correctSeries.clear();
}

int GameModel::getCurrentProgress(){
    if(this->correctSeries.size() == 0)
        return 0;

    return (100 * (currentScore / correctSeries.size()));
}

int GameModel::getCurrentScore(){
    return this->currentScore;
}

std::string GameModel::getNextColor(){
    if(this->currentScore == 0)
        return nullptr;
    return this->correctSeries[this->currentScore];
}
