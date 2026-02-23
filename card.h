#ifndef CARD_H
#define CARD_H

#include <string>
#include "bank.h"
#include "player.h"

/**
 * @class Card
 * @brief Abstract base class for game cards.
 *
 * Defines the common interface for all game cards, including actions
 * they can perform and their textual descriptions.
 * @author Zhixuan Chen
 */
class Card {

private:
    std::string name; ///< Name of the card.

public:
    /** @brief Default constructor. */
    Card();
    /**
     * @brief Set the amount associated with the card.
     * @param num The amount to set.
     */
    virtual void setAmount(int num) = 0;
    /**
     * @brief Set the card's text description.
     * @param text1 The text description of the card.
     */
    virtual void setCardText(std::string text1) = 0;
    /**
     * @brief Perform the action specified by the card.
     *
     * This could involve altering player's state or bank's resources.
     * @param bank1 Reference to the bank affected by the card (if any).
     * @param player1 Reference to the player affected by the card.
     */
    virtual void cardAction(Bank* bank1, Player* player1) = 0;
    /**
     * @brief Get the card's text description.
     * @param num Optionally specify which part of the text to retrieve.
     * @return The text description of the card.
     */
    virtual std::string getCardText(int num) = 0;

};
#endif // CARD_H
