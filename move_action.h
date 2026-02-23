#ifndef MOVE_ACTION_H
#define MOVE_ACTION_H

#include "player.h"
#include "action.h"

/**
 * @brief Represents an action to move a player a certain amount on the game board.
 *
 * Inherits from the Action class and implements functionality to move a player
 * by a specified amount, which can be positive (forward) or negative (backward).
 * @author Rafic
 */
class MoveAction : public Action {

private:
    int amount;

public:
    /**
     * @brief Constructs a MoveAction with a name and an amount to move.
     * @param nameChoice The name of the action.
     * @param amountInput The amount to move the player.
     */
    MoveAction(std::string, int amountInput);
    /**
     * @brief Constructs a MoveAction with a name. The move amount defaults to 0.
     * @param nameChoice The name of the action.
     */
    MoveAction(std::string nameChoice);
    /**
     * @brief Default constructor. Sets the name to an empty string and amount to 0.
     */
    MoveAction();
    /**
     * @brief Sets the amount to move the player.
     * @param amountInput The amount to move the player.
     */
    void set_amount(int amountInput);
    /**
     * @brief Moves the player by the specified amount.
     * @param player Pointer to the Player object to move.
     * @param amountInput The amount to move the player.
     */
    void move_amount(Player* player, int amountInput);
    /**
     * @brief Gets the amount associated with the move action.
     * @return The amount to move the player.
     */
    int get_amount();
    /**
     * @brief Executes the move action, moving player1 by the specified amount and potentially affecting player2.
     * @param player1 Pointer to the first player to move.
     * @param player2 Pointer to the second player who could be affected.
     * @param amount The amount to move player1.
     */
    void executeAction(Player* player1, Player* player2, int amount);
};
#endif //MOVE_ACTION_H
