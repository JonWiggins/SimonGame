/**
    CS 3505: A5
    Purpose: Implement the GameModel model for the Simon Game

    @author Conner Soule and Jonathan Wiggins
    @version 10/23/18
*/

#include "gamemodel.h"
#include <QTimer>

//Constructs the game model
GameModel::GameModel(){

    this->currentScore = 0;
}

//Deconstructs the Game Model
GameModel::~GameModel(){
    this->currentSeries.clear();
    this->correctSeries.clear();
}

//Generates a new move and adds it to the correctSeries vector
void GameModel::createNextMove(){
    int newNumber= rand() % 2;

    if(newNumber == 0){
        this->correctSeries.push_back("red");
    }else{
        this->correctSeries.push_back("blue");
    }
}

//handles a player move, ensures the move is correct, or ends the game, begins the computers turn if they are done
void GameModel::handlePlayersMove(std::string move){
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
        emit computerTurnSignal();
        computerTurn();
    }else{
        if(easyMode){
            if(getNextColor().compare("red") == 0){
                emit disableBlueSignal();
            }else{
                emit disableRedSignal();
            }
        }
    }
}

//Resets the state of this GameModel to defaults, zero score and no elements in either series
void GameModel::resetGame(){
    this->currentScore = 0;
    this->correctSeries.clear();
    this->currentSeries.clear();
}

//resets the currentSeries vector for the next round
void GameModel::resetRound(){
    this->currentSeries.clear();

}

//Does a turn for the computer, showing the correctSeries to the user though a series of button changing signals
void GameModel::computerTurn(){
    int time = (1000 - (75 * correctSeries.size()));

    if(time < 100)
        time = 100;

    int timeBuffer = 200;

    for(uint index = 0; index < correctSeries.size(); index++){
        if(correctSeries[index].compare("red") == 0){
            QTimer::singleShot((time * index) + (timeBuffer * index), this, &GameModel::pushRedSignal);
            QTimer::singleShot((time * index) + (timeBuffer * index) + time, this, &GameModel::unpushRedSignal);
        }else{
            QTimer::singleShot((time * index) + (timeBuffer * index), this, &GameModel::pushBlueSignal);
            QTimer::singleShot((time * index) + (timeBuffer * index) + time, this, &GameModel::unpushBlueSignal);
        }
    }
    QTimer::singleShot((correctSeries.size() * time) + (timeBuffer * correctSeries.size()) + 100, this, &GameModel::startPlayerTurnSignal);

    if(easyMode){
        if(getNextColor().compare("red") == 0){
            QTimer::singleShot((correctSeries.size() * time) + (timeBuffer * correctSeries.size()) + 100, this, &GameModel::disableBlueSignal);
        }else{
            QTimer::singleShot((correctSeries.size() * time) + (timeBuffer * correctSeries.size()) + 100, this, &GameModel::disableRedSignal);
        }
    }
}

//Starts a new game
void GameModel::startGame(bool easyModeBox){

    this->easyMode = easyModeBox;

    resetGame();
    createNextMove();
    computerTurn();
}

//Returns the user's progress on the current correctSeries as an integer percentage between 0 and 100
int GameModel::getCurrentProgress(){
    if(this->correctSeries.size() == 0)
        return 0;
    int result = (100 * currentSeries.size()) / (correctSeries.size());
    return result;
}

//Returns the user's current score
int GameModel::getCurrentScore(){
    return this->currentScore;
}

//fires signals to update the score and progressbar in the window
void GameModel::updateWindow(){
    emit setProgressSignal(getCurrentProgress());
    emit setScoreSignal(this->currentScore);
}

//Returns the next move the player should make to be correct, this is based off of the size of currentSeries and it's index in correctSeries
std::string GameModel::getNextColor(){
    if(currentSeries.size() == correctSeries.size())
        return nullptr;
    return this->correctSeries[this->currentSeries.size()];
}

//when the user quits the game, resets the game state
void GameModel::quitGame(){
    resetGame();
    emit GameOverSignal();
    return;
}
