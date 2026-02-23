#ifndef CARD_MONEY_H
#define CARD_MONEY_H
#include "card.h"
/**
 * @class CardMoney
 * @brief Represents a card that involves a money transaction in the game.
 *
 * This class inherits from the Card class and is used for cards that affect
 * the player's balance by giving or taking money.
 * @author Adam Seif
 */
    class CardMoney : public Card {
private:
    std::string cardText; ///< Description of the card.
    int moneyAmount; ///< The amount of money to give or take.
public:
    /** @brief Constructor for CardMoney. */
    CardMoney();
    /**
     * @brief Sets the money amount for the card.
     * @param num Amount of money.
     */
    void setAmount(int num);
    /**
     * @brief Sets the text description of the card.
     * @param text1 Description text.
     */
    void setCardText(std::string text1);
    /**
     * @brief Executes the action defined by the card.
     *
     * This can include giving or taking money from the player's balance.
     * @param bank1 Reference to the bank.
     * @param player1 Reference to the player affected by the card.
     */
    void cardAction(Bank* bank1, Player* player1);
    /**
     * @brief Gets the card's text description.
     * @param num Not used. Consider removing this parameter if it's unnecessary.
     * @return Description of the card.
     */
    std::string getCardText(int num);
};
#endif // CARD_MONEY_H

