#ifndef GAMEMODEL_H
#define GAMEMODEL_H
#include <vector>
#include <string>


class GameModel
{
    int currentScore;
    std::vector<std::string> correctSeries;
    int currentProgress;

public:
    GameModel();
    std::vector<std::string> getMoves();
    void createNextMove();
    bool handlePlayersMove(std::string move);
    void resetGame();
    int getCurrentProgress();
    int getCurrentScore();
    std::string getNextColor();

};

#endif // GAMEMODEL_H
