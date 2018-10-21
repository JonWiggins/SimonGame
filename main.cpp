#include "gamewindow.h"
#include "gamemodel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWindow window;

    GameModel gameModel;

    window.setBlueButton(false);
    window.setRedButton(false);
    window.setStartButton(true);
    window.setProgressBar(gameModel.getCurrentProgress());
    window.setScore(gameModel.getCurrentScore());


    window.show();
    return a.exec();
}
