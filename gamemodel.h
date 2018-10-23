/**
    CS 3505: A5
    Purpose: Outlines the GameModel model for the Simon Game

    @author Conner Soule and Jonathan Wiggins
    @version 10/23/18
*/

#ifndef GAMEMODEL_H
#define GAMEMODEL_H
#include <vector>
#include <string>
#include <QObject>


class GameModel : public QObject
{
    Q_OBJECT

    //denotes the current score of the game
    int currentScore;

    //denotes the correct series of the game, given by strings of "red" and "blue"
    std::vector<std::string> correctSeries;

    //denotes the user's input series as strings of "red" and "blue"
    std::vector<std::string> currentSeries;

    //this flag is set when a user starts a game, denoting if the game is in easy mode or not
    bool easyMode;

public:
    //Constructs the game model
    GameModel();

    //Deconstructs the Game Model
    ~GameModel();

    //Generates a new move and adds it to the correctSeries vector
    void createNextMove();

    //Resets the state of this GameModel to defaults, zero score and no elements in either series
    void resetGame();

    //Returns the user's progress on the current correctSeries as an integer percentage between 0 and 100
    int getCurrentProgress();

    //Returns the user's current score
    int getCurrentScore();

    //Returns the next move the player should make to be correct, this is based off of the size of currentSeries and it's index in correctSeries
    std::string getNextColor();

    //resets the currentSeries vector for the next round
    void resetRound();

    //Does a turn for the computer, showing the correctSeries to the user though a series of button changing signals
    void computerTurn();

public slots:

    //fires signals to update the score and progressbar in the window
    void updateWindow();

    //Starts a new game
    void startGame(bool easyModeBox);

    //handles a player move, ensures the move is correct, or ends the game, begins the computers turn if they are done
    void handlePlayersMove(std::string move);

    //when the user quits the game, resets the game state
    void quitGame();

signals:

    //sets the progressbar to the given int between 0 and 100
    void setProgressSignal(int currentProgress);

    //sets the score to the given int
    void setScoreSignal(int score);

    //tells the window that the computer's turn is beginning
    void computerTurnSignal();

    //tells the window that the game is over, display the message "Game Over" and reset buttons
    void GameOverSignal();

    //tells the window the change the style of the red button so it appears to be pressed
    void pushRedSignal();

    //tells the window to change the style of the blue button so it appears to be pressed
    void pushBlueSignal();

    //tells the window to change the style of the red button so it appears to be unpressed
    void unpushRedSignal();

    //tells the window to change the style of the blue button so it appears to be unpressed
    void unpushBlueSignal();

    //tells the window to enable the buttons so that the player can complete their turn
    void startPlayerTurnSignal();

    //tells the window to disable the users ability to press the red button, used for easy mode
    void disableRedSignal();

    //tells the window to disable the users ability to press the blue button, used for easy mode
    void disableBlueSignal();

};

#endif // GAMEMODEL_H
