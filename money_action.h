#ifndef MONEY_ACTION_H
#define MONEY_ACTION_H

#include "player.h"
#include "bank.h"
#include "action.h"

/**
 * @brief Represents an action related to money transactions between players and/or the bank.
 *
 * Inherits from the Action class and implements functionality for handling
 * monetary transactions, including paying money to another player, the bank,
 * and executing generic money-related actions.
 * @author Rafic
 */
class MoneyAction : public Action {

private:
    int money;

public:
    /**
     * @brief Constructs a MoneyAction with a name and an amount of money.
     * @param nameChoice The name of the action.
     * @param moneyInput The initial amount of money for the action.
     */
    MoneyAction(std::string nameChoice, int moneyInput);
    /**
     * @brief Constructs a MoneyAction with a name. The money amount defaults to 0.
     * @param nameChoice The name of the action.
     */
    MoneyAction(std::string nameChoice);
    /**
     * @brief Default constructor. Sets the name to an empty string and money to 0.
     */
    MoneyAction();
    /**
     * @brief Transfers money from one player to another.
     * @param player1 Pointer to the paying player.
     * @param player2 Pointer to the recipient player.
     * @param amount The amount of money to transfer.
     */
    void pay_money(Player* player1, Player* player2, int amount);
    /**
     * @brief Gets the amount of money involved in the action.
     * @return The amount of money.
     */
    int get_money();
    /**
     * @brief Sets the players involved in the action.
     * @param player1 Pointer to the first player.
     * @param player2 Pointer to the second player.
     */
    void setPlayers(Player* player1, Player* player2);
    /**
     * @brief Executes the money action between two players.
     * @param player1 Pointer to the first player involved in the action.
     * @param player2 Pointer to the second player involved in the action.
     * @param amount The amount of money to be transferred or manipulated.
     */
    void executeAction(Player* player1, Player* player2, int amount);
    /**
     * @brief Gives money from a player to the bank.
     * @param player1 Pointer to the player giving money.
     * @param bank1 Pointer to the bank receiving money.
     * @param amount The amount of money to give.
     */
    void giveBank(Player* player1, Bank* bank1, int amount);
    /**
     * @brief Takes money from the bank to give to a player.
     * @param player1 Pointer to the player receiving money.
     * @param bank1 Pointer to the bank giving money.
     * @param amount The amount of money to take.
     */
    void takeBank(Player* player1, Bank* bank1, int amount);

};
#endif //MONEY_ACTION_H
