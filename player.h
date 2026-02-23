#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <sstream>
#include <QString>

/**
 * @struct Coordinates
 * @brief Holds the x and y coordinates for a location.
 * @author Zhixuan Chen
 */
struct Coordinates{
    int x;
    int y;
};

/**
 * @brief Class to represent a player in the game.
 *
 * This class stores information about a game player, including their name,
 * game piece, money amount, and other game-related properties.
 * @author Rafic
 */
class Player {

private:

    std::string playerName;
    char gamePiece;
    int moneyAmount;
    int location;
    bool indexOfProperties[40];
    bool alive;
    std::string gamePieceName;
    Coordinates pixelLocation;


public:
    /**
     * @brief Default constructor. Initializes a player with default values.
     */
    Player();
    /**
     * @brief Constructs a player with a specified amount of money.
     * @param money The initial amount of money the player has.
     */
    Player(int money);
    /**
     * @brief Sets the player's name.
     * @param inputName The new name of the player.
     */
    void setPlayerName(std::string inputName);
    /**
     * @brief Sets the game piece character representing the player.
     * @param inputPiece The game piece character.
     */
    void setGamePiece(char inputPiece);
    /**
     * @brief Marks a property as owned or not owned by the player.
     * @param inputIndex Index of the property on the game board.
     * @param isOwned True if the property is now owned by the player, false otherwise.
     */
    void setOwnedProperty(int inputIndex, bool isOwned);
    /**
     * @brief Sets the player's current location on the game board.
     * @param spaceNum The board space number where the player is located.
     */
    void setLocation(int spaceNum);
    /**
     * @brief Sets the name of the game piece.
     * @param inputPieceName The name of the game piece.
     */
    void setGamePieceName(std::string inputPieceName);
    /**
     * @brief Sets the player's location in pixel coordinates (for a GUI representation).
     * @param tempLocation The player's new pixel location.
     */
    void setPixelLocation(Coordinates tempLocation);
    /**
     * @brief Sets the amount of money the player has.
     * @param inputNum The new amount of money.
     */
    void setMoneyAmount(int inputNum);
    /**
     * @brief Retrieves the player's name.
     * @return The player's name.
     */
    std::string getPlayerName();
    /**
     * @brief Gets the game piece character representing the player.
     * @return The game piece character.
     */
    char getGamePiece();
    /**
     * @brief Retrieves the amount of money the player has.
     * @return The player's current amount of money.
     */
    int getMoneyAmount();
    /**
     * @brief Checks if a property is owned by the player.
     * @param inputIndex Index of the property on the game board.
     * @return True if the property is owned by the player, false otherwise.
     */
    bool getOwnedProperty(int inputIndex);
    /**
     * @brief Gets the player's current location on the game board.
     * @return The board space number where the player is located.
     */
    int getLocation();
    /**
     * @brief Checks if the player is still in the game.
     * @return True if the player is alive, false otherwise.
     */
    bool isAlive();
    /**
     * @brief Retrieves the name of the game piece.
     * @return The name of the game piece.
     */
    std::string getGamePieceName();
    /**
     * @brief Gets the player's location in pixel coordinates.
     * @return The player's pixel location.
     */
    Coordinates getPixelLocation();
    /**
     * @brief Adds a specified amount of money to the player's total.
     * @param amount The amount to be added to the player's money.
     */
    void give_money(int amount);
    /**
     * @brief Deducts a specified amount of money from the player's total.
     * @param amount The amount to be deducted from the player's money.
     */
    void take_money(int amount);
    /**
     * @brief Moves the player forward by a specified number of spaces on the board.
     * @param amount The number of spaces to move the player forward.
     */
    void move_player(int amount);
    /**
     * @brief Resets the player's state to default values.
     */
    void reset();

};
#endif //PLAYER_H
