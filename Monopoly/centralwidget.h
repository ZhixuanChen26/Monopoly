#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>
#include <QLabel>
#include "player.h"

/**
 * @class CentralWidget
 * @brief Represents the central game area in the UI.
 *
 * This class manages the game board, dice, player icons, and game cards.
 * @author Zhixuan Chen
 */
class CentralWidget : public QWidget {
    Q_OBJECT

private:
    QLabel* chanceCover; ///< Cover for the chance card pile.
    QLabel* communityCover; ///< Cover for the community chest card pile.
    QLabel* boardLabel; ///< Label displaying the game board.
    QLabel* dice1; ///< First dice image.
    QLabel* dice2; ///< Second dice image.
    QLabel** playerIcons; ///< Array of player icons on the board.
    int numPlayers; ///< Number of players in the game.
    QLabel** communityCards; ///< Community chest cards displayed.
    QLabel** chanceCards; ///< Chance cards displayed.
private slots:
    void drawCard(); ///< Slot to handle drawing a card action.

public:
    /**
     * @brief Constructor for initializing the game board.
     * @param tempNum Number of players.
     * @param tempPlayers Array of players.
     */
    explicit CentralWidget(int tempNum, Player* tempPlayers);
    /**
     * @brief Changes the images of the dice.
     * @param rollNum1 Value of the first dice.
     * @param rollNum2 Value of the second dice.
     */
    void changeDiceImg(int rollNum1, int rollNum2);
    /**
     * @brief Moves player pieces on the board.
     * @param playerNum Index of the player to move.
     * @param tempCoordinates New coordinates for the player piece.
     */
    void movePieces(int playerNum,Coordinates tempCoordinates);
    /**
     * @brief Hides a player's piece from the board.
     * @param playerNum Index of the player whose piece to hide.
     */
    void hidePiece(int playerNum);
    /**
     * @brief Displays a community chest card.
     * @param cardNum Index of the card to display.
     */
    void showCommunity(int cardNum);
    /**
     * @brief Resets the display of a community chest card to its cover.
     * @param cardNum Index of the card to reset.
     */
    void resetCommunity(int cardNum);
    /**
     * @brief Displays a chance card.
     * @param cardNum Index of the card to display.
     */
    void showChance(int cardNum);
    /**
     * @brief Resets the display of a chance card to its cover.
     * @param cardNum Index of the card to reset.
     */
    void resetChance(int cardNum);
    /**
     * @brief Initializes the game cards.
     * @param tempArray Array indicating the sequence of card initialization.
     */
    void initializingCards(int tempArray[]);
};

#endif //CENTRALWIDGET_H
