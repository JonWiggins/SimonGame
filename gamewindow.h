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
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
    void setScore(int score);
    void setStartButton(bool active);
    void setBlueButton(bool active);
    void setRedButton(bool active);
    void setProgressBar(int value);
    bool isEasyModeChecked();
    void displayMoveSeries(std::vector<std::string>);

private:
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
