#ifndef GAMEMODEL_H
#define GAMEMODEL_H
#include <vector>
#include <string>
#include <QObject>


class GameModel : public QObject
{
    Q_OBJECT

    int currentScore;
    std::vector<std::string> correctSeries;
    std::vector<std::string> currentSeries;

public:
    GameModel();
    ~GameModel();
    std::vector<std::string> getMoves();
    void createNextMove();
    void resetGame();
    int getCurrentProgress();
    int getCurrentScore();
    std::string getNextColor();
    void resetRound();
    void computerTurn();

public slots:
    void updateWindow();
    void startGame();
    void handlePlayersMove(std::string move);

signals:
    void setProgressSignal(int currentProgress);
    void setScoreSignal(int score);
    void computerTurnSignal(std::vector<std::string> turns);
    void GameOverSignal();
    void pushRedSignal();
    void pushBlueSignal();
    void unpushRedSignal();
    void unpushBlueSignal();


};

#endif // GAMEMODEL_H
