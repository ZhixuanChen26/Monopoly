#ifndef ACTION_H
#define ACTION_H
#include "player.h"
class Action {
private:
    std::string name;
public:
    //constructors
    Action();
    Action(std::string inputName);
    //This class is abstract and cannot be compiled
    virtual void executeAction(Player* player1, Player* player2, int amount) = 0;
};
#endif

