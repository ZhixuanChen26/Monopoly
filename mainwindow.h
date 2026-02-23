#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include "centralwidget.h"
#include "bottomBar.h"
#include "guiplayers.h"
#include <QPlainTextEdit>
#include "player.h"
#include "space.h"


/**
 * @class MainWindow
 * @brief The main window of the application, managing the game's GUI and state.
 *
 * This class is responsible for the graphical user interface of the game,
 * including the setup of the game board, player management, and handling the
 * game turns.
 * @author Zhixuan Chen
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    GUIPlayers* guiPlayers[4];
    CentralWidget* centralWidget;
    BottomBar* bottomBar;
    int playerTurn;
    int totalPlayers;
    Player* players;
    Coordinates boardSpace[40];
    Space** spaces;

public:
    /**
     * @brief Constructs a MainWindow with a specified number of players.
     * @param numPlayers The number of players in the game.
     */
    MainWindow(int numPlayers);
    /**
     * @brief Default constructor.
     */
    MainWindow();
    /**
     * @brief Advances the game to the next player's turn.
     */
    void nextTurn();
    /**
     * @brief Retrieves the current player's turn index.
     * @return The index of the current player's turn.
     */
    int getPlayerTurn();
    /**
     * @brief Assigns a game piece to a player.
     * @param playerNum The player's number (index).
     * @param pieceName The name of the game piece to assign.
     */
    void setGamePiece(int playerNum, std::string pieceName);
    /**
     * @brief Sets up the main window and its components.
     */
    void windowSetUp();
    /**
     * @brief Retrieves the name of a player's game piece.
     * @param playerNum The player's number (index).
     * @return The name of the game piece.
     */
    std::string getGamePiece(int playerNum);
    /**
     * @brief Sets the location of a player on the game board.
     * @param playerNum The player's number (index).
     * @param spaceNum The board space number to move the player to.
     */
    void setPlayerLocation(int playerNum, int spaceNum);
    /**
     * @brief Retrieves a player's location on the game board.
     * @param playerNum The player's number (index).
     * @return The board space number where the player is located.
     */
    int getPlayerLocation(int playerNum);
    /**
     * @brief Gets the pixel coordinates of a player's location on the game board.
     * @param playerNum The player's number (index).
     * @return The pixel coordinates of the player's location.
     */
    Coordinates getPlayerPixels(int playerNum);
    /**
     * @brief Retrieves the ownership status of a space on the game board.
     * @param spaceIndex The index of the space.
     * @return The player number who owns the space, or -1 if the space is not owned.
     */
    int getSpaceOwnership(int spaceIndex);
    /**
     * @brief Determines the type of a game board space.
     * @param inputIndex The index of the space.
     * @return A string representing the type of the space (e.g., "property", "railroad").
     */
    std::string spaceType(int inputIndex);
    /**
     * @brief Gets a pointer to a player object by player number.
     * @param num The player's number (index).
     * @return A pointer to the Player object.
     */
    Player* getPlayer(int num);
    /**
     * @brief Retrieves the name of a player.
     * @param playerNum The player's number (index).
     * @return The name of the player.
     */
    std::string getPlayerName(int playerNum);
    /**
     * @brief Retrieves the rent amount of a space on the game board.
     * @param spaceIndex The index of the space.
     * @return The rent amount.
     */
    int getSpaceRent(int spaceIndex);
    /**
     * @brief Retrieves the amount of money a player has.
     * @param playerNum The player's number (index).
     * @return The amount of money.
     */
    int getPlayerMoney(int playerNum);
    /**
     * @brief Retrieves the property cost of a space on the game board.
     * @param spaceIndex The index of the space.
     * @return The property cost.
     */
    int getSpacePropertyCost(int spaceIndex);
    /**
     * @brief Sets the ownership of a space on the game board.
     * @param spaceIndex The index of the space.
     * @param playerNum The player number who will own the space.
     */
    void setSpaceOwnership(int spaceIndex, int playerNum);
    /**
     * @brief Marks a player as having lost the game.
     * @param playerNum The player's number (index).
     */
    void playerLost(int playerNum);
    /**
     * @brief Checks if a player is still in the game.
     * @param playerNum The player's number (index).
     * @return True if the player is still alive (in the game), false if they have lost.
     */
    bool isPlayerAlive(int playerNum);
    /**
     * @brief Retrieves the tax amount of a space on the game board.
     * @param spaceIndex The index of the space.
     * @return The tax amount.
     */
    int getSpaceTax(int spaceIndex);
    /**
     * @brief Retrieves the name of a space on the game board.
     * @param spaceIndex The index of the space.
     * @param index The name index for spaces with multiple names.
     * @return The name of the space.
     */
    std::string getSpaceName(int spaceIndex, int index);
    /**
     * @brief Gets all spaces on the game board.
     * @return A pointer to an array of pointers to Space objects representing all board spaces.
     */
    Space** getAllSpaces();
};

#endif //MAINWINDOW_H


