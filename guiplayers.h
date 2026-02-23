#ifndef GUIPLAYERS_H
#define GUIPLAYERS_H

#include "player.h"
#include "space.h"
#include "money_action.h"
#include "bank.h"
#include <QWidget>
#include <QDockWidget>
#include <QMessageBox>
#include <QLabel>
#include <string>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSignalMapper>

/**
 * @class GUIPlayers
 * @brief Represents the graphical interface for a player in the game.
 *
 * This class extends QDockWidget to provide a graphical display of a player's
 * status, including money, owned properties, and possible actions like upgrading properties.
 * @author Rafic
 */
class GUIPlayers : public QDockWidget {
    Q_OBJECT

protected:
    Player* player;
    QLabel *numLabel;
    QLabel *moneyLabel;
    QVBoxLayout* layout;
    QWidget* sideBar;
    QLabel* gamePieceImg;
    QPushButton** ownedProperties;
    int currentPropertyNum;
    int allProperties[40];
    int ownedCount;
    Space** allSpaces;
    MoneyAction moneyAction;
    Bank* bankPointer;

private slots:
    /**
     * @brief Slot to handle upgrading a property.
     */
    void upgradeSpace();

public:
    /**
     * @brief Constructor for GUIPlayers with a player object and player number.
     * @param p Pointer to the Player object.
     * @param playerNum The player's number (used for identification).
     */
    GUIPlayers(Player* p, int playerNum);
    /**
     * @brief Default constructor.
     */
    GUIPlayers();
    /**
     * @brief Updates the display of the player's money.
     */
    void setMoneyText();
    /**
     * @brief Adds a property to the player's GUI representation.
     * @param propertyNum The number of the property on the board.
     * @param propertyName The name of the property.
     * @param spaceArray Array of pointers to all spaces on the game board.
     */
    void addProperty(int propertyNum,std::string propertyName, Space** spaceArray);
    /**
     * @brief Enables the upgrade button for properties.
     */
    void enableUpgrade();
    /**
     * @brief Disables the upgrade button for properties.
     */
    void disableUpgrade();
    /**
     * @brief Sets the array of all spaces on the game board.
     * @param spaceArray Array of pointers to all spaces on the game board.
     */
    void setAllSpaces(Space** spaceArray);
    /**
     * @brief Sets the Bank object for money transactions.
     * @param tempBank Pointer to the Bank object.
     */
    void setBank(Bank* tempBank);

};

#endif //GUIPLAYERS_H
