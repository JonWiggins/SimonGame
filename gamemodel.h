#ifndef GAMEMODEL_H
#define GAMEMODEL_H
#include <vector>
#include <string>
#include <QObject>


class GameModel
{
    int currentScore;
    std::vector<std::string> correctSeries;
    std::vector<std::string> currentSeries;

public:
    GameModel();
    std::vector<std::string> getMoves();
    void createNextMove();
    void resetGame();
    int getCurrentProgress();
    int getCurrentScore();
    std::string getNextColor();
    void resetRound();

public slots:
    void updateWindow();
    void startGame();
    void handlePlayersMove(std::string move);

signals:
    void setProgressSignal(int currentProgress);
    void setScoreSignal(int score);
    void computerTurnSignal(std::vector<std::string> turns);
    void GameOverSignal();

};

#endif // GAMEMODEL_H
