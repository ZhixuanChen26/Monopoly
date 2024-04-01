#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "space.h"
#include "move_action.h"
#include "player.h"

class Game_Board {

private:
    Space spaces[40];
    Player* players;
    MoveAction movement;

public:
    //constructor
    Game_Board(); //initialize all 40 game spaces

    //methods called by user
    void displayHorizontal(int firstSpace, int lastSpace, int numPlayers);
    void displayVertical(int firstSpace, int lastSpace, int numPlayers);
    void createPlayers(int numPlayers);
    void setPlayerName(int playerNum, std::string inputName);
    void setGamePiece(int playerNum, std::string inputPiece);

    std::string getPlayerName(int playerNum);
    std::string getGamePiece(int playerNum);

    void move(int numPlayer, int amountMove);
    Player* getPlayer(int num);
    int getPlayerLocation(int playerNum);
    int getPlayerMoney(int playerNum);
    std::string spaceType(int inputIndex);
    int getSpaceOwnership(int spaceIndex);
    int getSpacePropertyCost(int spaceIndex);
    void setSpaceOwnership(int spaceIndex, int playerNum);
    int getSpaceRent(int spaceIndex);
    int getSpaceTax(int spaceIndex);
    int getSpaceFreeParking(int spaceIndex);
    std::string getSpaceName(int spaceIndex, int index);
    void upgradeSpace(int spaceNum);
    bool isPlayerAlive(int playerNum);
    void playerLost(int playerNum);

};
#endif
