#ifndef GAMEMODEL_H
#define GAMEMODEL_H
#include <vector>
#include <string>


class GameModel
{
    int currentScore;
    std::vector<std::string> correctSeries;
    std::vector<std::string> currentSeries;
    bool isCurrentSeriesValid();

public:
    GameModel();
    std::vector<std::string> getMoves();
    void createNextMove();
    bool handlePlayersMove(std::string move);
    void resetGame();

};

#endif // GAMEMODEL_H
