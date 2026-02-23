#ifndef CARD_MOVE_H
#define CARD_MOVE_H
#include "card.h"
/**
 * @class CardMove
 * @brief Represents a card that moves a player to a specific location on the board.
 *
 * Inherits from Card and manages the actions for cards that require a player
 * to move to a different board space.
 * @author Adam Seif
 */
    class CardMove : public Card {
private:
    std::string cardText; ///< Description of the card.
    int locationNum = 0; ///< Board location number to move to.
public:
    /** @brief Default constructor for CardMove. */
    CardMove();
    /**
     * @brief Sets the movement amount, typically the location number.
     * @param num The board location to move to.
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
     * Moves the player to a specified location on the board.
     * @param bank1 Reference to the bank (unused in this context).
     * @param player1 Reference to the player affected by the card.
     */
    void cardAction(Bank* bank1, Player* player1);
    /**
     * @brief Gets the card's text description.
     * @param num Optionally specify which part of the text to get, if applicable.
     * @return The description of the card.
     */
    std::string getCardText(int num);
};
#endif // CARD_MOVE_H
