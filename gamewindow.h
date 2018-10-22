#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "gamemodel.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
    void setStartButton(bool active);
    void setBlueButton(bool active);
    void setRedButton(bool active);
    bool isEasyModeChecked();
    void displayMoveSeries(std::vector<std::string>);
    void startPressed();
    void startPlayerTurn();

signals:
    void updateWindow();
    void startGameSignal();
    void playerTurn();
    void playerPlaySignal(std::string move);

public slots:
    void on_RedButton_clicked();
    void setProgressBar(int value);
    void setScore(int score);
    void on_BlueButton_clicked();
    void on_StartButton_clicked();
    void computerTurn(std::vector<std::string> moves);

private:
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
