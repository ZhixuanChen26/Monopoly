#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "space.h"
#include "move_action.h"
#include "player.h"

/**
 * @class Game_Board
 * @brief Manages the game board including spaces, players, and actions.
 *
 * This class holds the game logic for managing spaces on the board,
 * tracking player positions, and executing actions like moving players or managing properties.
 * @author Jingwen Liu
 */
class Game_Board {

private:
    Space spaces[40]; ///< Array of 40 spaces on the board.
    Player* players; ///< Pointer to an array of players.
    MoveAction movement; ///< MoveAction object to handle player movements.

public:
    /**
     * @brief Constructs and initializes the game board with 40 spaces.
     */
    Game_Board(); //initialize 40 game spaces

    /**
     * @brief Displays the board horizontally between two spaces.
     * @param firstSpace Index of the first space to display.
     * @param lastSpace Index of the last space to display.
     * @param numPlayers Number of players to consider in the display.
     */
    void displayHorizontal(int firstSpace, int lastSpace, int numPlayers);
    /**
     * @brief Displays the board vertically between two spaces.
     * @param firstSpace Index of the first space to display.
     * @param lastSpace Index of the last space to display.
     * @param numPlayers Number of players to consider in the display.
     */
    void displayVertical(int firstSpace, int lastSpace, int numPlayers);
    /**
     * @brief Creates and initializes players for the game.
     * @param numPlayers Number of players in the game.
     */
    void createPlayers(int numPlayers);
    /**
     * @brief Sets the name for a specific player.
     * @param playerNum Index of the player.
     * @param inputName Name to set for the player.
     */
    void setPlayerName(int playerNum, std::string inputName);
    /**
     * @brief Sets the game piece for a specific player.
     * @param playerNum Index of the player.
     * @param inputPiece Game piece to set for the player.
     */
    void setGamePiece(int playerNum, std::string inputPiece);

    /**
     * @brief Retrieves the name of a specific player.
     * @param playerNum Index of the player.
     * @return Name of the player.
     */
    std::string getPlayerName(int playerNum);
    /**
     * @brief Retrieves the game piece of a specific player.
     * @param playerNum Index of the player.
     * @return Game piece of the player.
     */
    std::string getGamePiece(int playerNum);

    /**
     * @brief Moves a player a specific number of spaces on the board.
     * @param numPlayer Index of the player to move.
     * @param amountMove Number of spaces to move the player.
     */
    void move(int numPlayer, int amountMove);

    Player* getPlayer(int num);
    /**
     * @brief Retrieves the current location of a player.
     * @param playerNum Index of the player.
     * @return The board space index where the player is currently located.
     */
    int getPlayerLocation(int playerNum);
    /**
     * @brief Retrieves the current money amount of a player.
     * @param playerNum Index of the player.
     * @return Amount of money the player has.
     */
    int getPlayerMoney(int playerNum);
    /**
     * @brief Gets the type of a space on the board by its index.
     * @param inputIndex Index of the space.
     * @return The type of the space as a string.
     */
    std::string spaceType(int inputIndex);
    /**
     * @brief Checks the ownership status of a board space.
     * @param spaceIndex Index of the space.
     * @return The player index who owns the space, or -1 if unowned.
     */
    int getSpaceOwnership(int spaceIndex);
    /**
     * @brief Gets the purchase cost of a property space.
     * @param spaceIndex Index of the space.
     * @return Cost of the property.
     */
    int getSpacePropertyCost(int spaceIndex);
    /**
     * @brief Assigns ownership of a space to a player.
     * @param spaceIndex Index of the space.
     * @param playerNum Index of the player.
     */
    void setSpaceOwnership(int spaceIndex, int playerNum);
    /**
     * @brief Retrieves the rent cost of a property space.
     * @param spaceIndex Index of the space.
     * @return Rent cost of the property.
     */
    int getSpaceRent(int spaceIndex);
    /**
     * @brief Retrieves the tax amount for a tax space.
     * @param spaceIndex Index of the space.
     * @return Tax amount.
     */
    int getSpaceTax(int spaceIndex);
    /**
     * @brief Gets the amount collected when landing on Free Parking.
     * @param spaceIndex Index of the Free Parking space.
     * @return Amount of money collected from Free Parking.
     */
    int getSpaceFreeParking(int spaceIndex);
    /**
     * @brief Retrieves the name of a space.
     * @param spaceIndex Index of the space.
     * @param index Used if space has multiple names.
     * @return Name of the space.
     */
    std::string getSpaceName(int spaceIndex, int index);
    /**
     * @brief Upgrades a property space by adding houses or hotels.
     * @param spaceNum Index of the space to upgrade.
     */
    void upgradeSpace(int spaceNum);
    /**
     * @brief Checks if a player is still in the game.
     * @param playerNum Index of the player.
     * @return True if the player is alive, false otherwise.
     */
    bool isPlayerAlive(int playerNum);
    /**
     * @brief Removes a player from the game after losing.
     * @param playerNum Index of the player.
     */
    void playerLost(int playerNum);

};
#endif // GAME_BOARD_H
