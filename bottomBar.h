#ifndef BOTTOMBAR_H
#define BOTTOMBAR_H

#include <QWidget>
#include <QDockWidget>
#include <QPushButton>
#include <QGridLayout>
#include "guiplayers.h"
#include "centralwidget.h"
#include "money_action.h"
#include "bank.h"
#include "card.h"
#include "card_move.h"
#include "card_money.h"
class MainWindow;

/**
 * @class BottomBar
 * @brief Represents the bottom bar in the game's UI.
 *
 * Contains controls for game actions and displays game status.
 * @author Adam Seif
 */

class BottomBar : public QDockWidget {
    Q_OBJECT
protected:

    QPushButton* rollButton; ///< Button for rolling dice.
    QPushButton* upgradeButton; ///< Button for upgrading properties.
    QPushButton* purchaseButton; ///< Button for purchasing properties.
    QPushButton* endTurnButton; ///< Button to end the current turn.
    // Buttons for viewing player status.
    QPushButton* player1Button;
    QPushButton* player2Button;
    QPushButton* player3Button;
    QPushButton* player4Button;
    QGridLayout* layout; ///< Layout for arranging buttons.
    QWidget* bottomWidget; ///< Container for layout.
    // Game state variables.
    int diceRoll1;
    int diceRoll2;
    Bank* bank;
    Player* freePark;
    MoneyAction moneyAction;
    Card** community;
    Card** chance;
    int newSpace;
    int oldSpace;
    int numAlive;
    int communityCount;
    int chanceCount;
    int index[10];
    GUIPlayers** allPlayers;
    CentralWidget* monopolyBoard;
    MainWindow* myWindow;
    int numberOfPlayers;
    int currentPlayerNum;
private slots:
    // Slot functions for button actions.
    void rollDice();
    void upgrade();
    void purchase();
    void endTurn();
    void seePlayer1();
    void seePlayer2();
    void seePlayer3();
    void seePlayer4();

public:
    /** @brief Constructor for BottomBar. */
    BottomBar();
    /** @brief Sets players for the game.
     *  @param numberPlayers Number of players.
     *  @param tempPlayers Array of player GUIs.
     */
    void setPlayers(int numberPlayers, GUIPlayers* tempPlayers[]);
    /** @brief Sets the central widget for the game board.
     *  @param tempBoard Pointer to the game board widget.
     */
    void setCentralWidget(CentralWidget* tempBoard);
    /** @brief Sets the main window containing this widget.
     *  @param tempWindow Pointer to the main window.
     */
    void setMainWindow(MainWindow* tempWindow);
    /** @brief Disables control buttons based on game state.
     *  @param num Number of buttons to disable.
     */
    void disableButtons(int num);

};
#endif // BOTTOMBAR_H
