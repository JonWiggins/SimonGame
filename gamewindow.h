/**
    CS 3505: A5
    Purpose: Outlines the GameWindow view for the Simon Game

    @author Conner Soule and Jonathan Wiggins
    @version 10/23/18
*/

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:

    //Creates a new GameWindow, from the given QWidget window it is in
    explicit GameWindow(QWidget *parent = nullptr);

    //Deconstructs this GameWindow
    ~GameWindow();

public slots:

    //Sets the buttons for a player to begin their turn
    void startPlayerTurn();

    //Handles the user pressing the Red Button
    void on_RedButton_clicked();

    //Sets the progress bar to the given int
    void setProgressBar(int value);

    //Sets the score to the given int
    void setScore(int score);

    //Handles the user pressing the blue button
    void on_BlueButton_clicked();

    //Handles the user pressing the start button
    void on_StartButton_clicked();

    //Disables the buttons so the computer can do its turn
    void startComputerTurn();

    //Resets the game buttons and displays the game over message
    void gameOver();

    //Changes the style of the red button so it appears pressed
    void pushRed();

    //Resets the style of the red button
    void unpushRed();

    //Changes the style of the blue button so it appears pressed
    void pushBlue();

    //Resets the style of the blue button
    void unpushBlue();

    //Disables the blue button so the user cannot press it, this is used for easy mode
    void disableBlue();

    //Disables the red button so the user cannot press it, this is used for easy mode
    void disableRed();

    //Handles the quit button being pressed
    void on_QuitButton_clicked();

signals:

    //sends a request to the model to update itself
    void updateWindow();

    //tells the model that the game is starting
    void startGameSignal(bool easyModeBox);

    //tells the model that the player is playing
    void playerTurn();

    //tells the model what button the player pressed
    void playerPlaySignal(std::string move);

    //tells the model that the user quit the game
    void quitGameSignal();

private:
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
