#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include "centralwidget.h"
#include "bottomBar.h"
#include "guiplayers.h"
#include <QPlainTextEdit>
#include "player.h"
#include "space.h"



class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    GUIPlayers* guiPlayers[4];
    CentralWidget* centralWidget;
    BottomBar* bottomBar;
    int playerTurn;
    int totalPlayers;
    Player* players;
    Coordinates boardSpace[40];
    Space** spaces;

public:
    MainWindow(int numPlayers);
    MainWindow();
    void nextTurn();
    int getPlayerTurn();
    void setGamePiece(int playerNum, std::string pieceName);
    void windowSetUp();
    std::string getGamePiece(int playerNum);
    void setPlayerLocation(int playerNum, int spaceNum);
    int getPlayerLocation(int playerNum);
    Coordinates getPlayerPixels(int playerNum);
    int getSpaceOwnership(int spaceIndex);
    std::string spaceType(int inputIndex);
    Player* getPlayer(int num);
    std::string getPlayerName(int playerNum);
    int getSpaceRent(int spaceIndex);
    int getPlayerMoney(int playerNum);
    int getSpacePropertyCost(int spaceIndex);
    void setSpaceOwnership(int spaceIndex, int playerNum);
    void playerLost(int playerNum);
    bool isPlayerAlive(int playerNum);
    int getSpaceTax(int spaceIndex);
    std::string getSpaceName(int spaceIndex, int index);
    Space** getAllSpaces();
};

#endif


