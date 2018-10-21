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

bool GameModel::isCurrentSeriesValid(){
    for(uint index = 0; index < this->currentSeries.size(); index++){
        if(this->currentSeries[index].compare(this->correctSeries[index]) != 0){
            return false;
        }
    }
    return true;
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
    currentSeries.push_back(move);

    if(isCurrentSeriesValid()){
        this->currentScore++;
        return true;
    }else{
        return false;
    }
}

void GameModel::resetGame(){
    this->currentScore = 0;
    this->currentSeries.clear();
    this->correctSeries.clear();
}

int GameModel::getCurrentProgress(){
    if(this->correctSeries.size() == 0)
        return 0;
    if(this->currentSeries.size() == 0)
        return 0;

    return (100 * (currentSeries.size() / correctSeries.size()));
}

int GameModel::getCurrentScore(){
    return this->currentScore;
}

std::string GameModel::getNextColor(){
    if(this->currentScore == 0)
        return nullptr;
    return this->correctSeries[this->currentScore];
}
