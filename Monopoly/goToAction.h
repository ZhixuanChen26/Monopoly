#ifndef GOTOACTION_H
#define GOTOACTION_H

#include "action.h"
#include "player.h"

/**
 * @class GoToAction
 * @brief Represents an action that moves a player to a specific location on the game board.
 *
 * Inherits from Action and implements the executeAction method to move a player.
 * @author Adam Seif
 */
class GoToAction : public Action {

private:
    int spaceLocation; ///< The board space index to move the player to.

public:
    /**
     * @brief Default constructor for GoToAction.
     */
    GoToAction();
    /**
     * @brief Executes the move action on a player.
     *
     * Moves player1 to the specified board space, ignoring player2 and amount.
     * @param player1 Pointer to the player to move.
     * @param player2 Unused in this action.
     * @param amount Unused in this action.
     */
    void executeAction(Player* player1, Player* player2, int amount);

};
#endif // GOTOACTION_H



