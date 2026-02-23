#ifndef ACTION_H
#define ACTION_H
#include "player.h"
/** @class Action
 *  @brief Abstract class for game actions.
 *
 *  Derive from this to implement specific actions.
 *  @author Jingwen Liu
 */
class Action {
private:
    std::string name;
public:
    /** @brief Default constructor. */
    Action();
    /** @brief Constructor with name.
     *  @param inputName Name of the action.
     */
    Action(std::string inputName);
    /** @brief Execute the action.
     *  @param player1 First player.
     *  @param player2 Second player (null if not needed).
     *  @param amount Amount affected.
     */
    virtual void executeAction(Player* player1, Player* player2, int amount) = 0;
};
#endif // ACTION_H

