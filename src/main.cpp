#include <QtWidgets>
#include "player.h"
#include "property.h"

class BoardWidget : public QWidget {
  
private:
    Player* player;
public:
    BoardWidget(QWidget *parent = nullptr) : QWidget(parent) {
        player = new Player("Player 1", 0);
        player->receiveMoney(10000);
        // Set up the main layout
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->setContentsMargins(0, 0, 0, 0);

        // Create the board layout
        QGridLayout *boardLayout = new QGridLayout;
        mainLayout->addLayout(boardLayout);

        // Add properties and stations to the board
        QStringList properties = {"UCC", "Weldon Library", "Middlesex College" , "Talbot College", "Physics & Astronomy", "Natural Science","Lawson Hall", "Stevenson Hall"};
        QStringList stations = {"The Spoke", "The Wave","The Grad Club","Einstein Cafe"};
        QStringList chanceCards = {"Chance 1", "Chance 2"};

        // Add spaces to the board in the specified order
        addSpace(boardLayout, 0, 0, 1, 1, "Go");
        addSpace(boardLayout, 0, 1, 1, 1, properties.at(0));
        addSpace(boardLayout, 0, 2, 1, 1, properties.at(1));
        addSpace(boardLayout, 0, 3, 1, 1, stations.at(0));
        addSpace(boardLayout, 0, 4, 1, 1, properties.at(2));
        addSpace(boardLayout, 0, 5, 1, 1, "Just Visiting");
        addSpace(boardLayout, 1, 5, 1, 1, properties.at(3));
        addSpace(boardLayout, 2, 5, 1, 1, chanceCards.at(0));
        addSpace(boardLayout, 3, 5, 1, 1, stations.at(1));
        addSpace(boardLayout, 4, 5, 1, 1, properties.at(4));
        addSpace(boardLayout, 5, 5, 1, 1, "Free Parking");
        addSpace(boardLayout, 5, 4, 1, 1, properties.at(5));
        addSpace(boardLayout, 5, 3, 1, 1, stations.at(2));
        addSpace(boardLayout, 5, 2, 1, 1, properties.at(6));
        addSpace(boardLayout, 5, 1, 1, 1, properties.at(7));
        addSpace(boardLayout, 5, 0, 1, 1, "Go to Jail");
        addSpace(boardLayout, 4, 0, 1, 1, chanceCards.at(1));
        addSpace(boardLayout, 3, 0, 1, 1, stations.at(3));
        addSpace(boardLayout, 2, 0, 1, 1, properties.at(0));
        addSpace(boardLayout, 1, 0, 1, 1, properties.at(1));

        // Add player tokens
        for (int i = 0; i < players.size(); ++i) {
            addPlayerToken(boardLayout, 0, i, players[i].getCharacter());
        }
    }

    void addSpace(QGridLayout *layout, int row, int col, int rowSpan, int colSpan, const QString &text) {
        QLabel *spaceLabel = new QLabel(text, this);
        spaceLabel->setAlignment(Qt::AlignCenter);
        spaceLabel->setStyleSheet("border: 1px solid black;");
        layout->addWidget(spaceLabel, row, col, rowSpan, colSpan);
    }

    void addPlayerToken(QGridLayout *layout, int row, int col, const QString &token) {
        QLabel *tokenLabel = new QLabel(this);

        // Set the pixmap based on the token
        if (token == "cat") {
            tokenLabel->setPixmap(QPixmap(":cat.png").scaledToWidth(70));
        } else if (token == "boat") {
            tokenLabel->setPixmap(QPixmap(":boat.png").scaledToWidth(70));
        } else if (token == "moneybag") {
            tokenLabel->setPixmap(QPixmap(":moneybag.png").scaledToWidth(70));
        } else if (token == "hat") {
            tokenLabel->setPixmap(QPixmap(":hat.png").scaledToWidth(70));
        } else if (token == "duck") {
            tokenLabel->setPixmap(QPixmap(":duck.png").scaledToWidth(70));
        } else if (token == "car") {
            tokenLabel->setPixmap(QPixmap(":car.png").scaledToWidth(70));
        }

        tokenLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(tokenLabel, row, col);
    }
  
private:
    QVector<Player> players;
};
  
public slots:
    void checkWinCondition() {
        if (player->getMoney() >= 10000) {
            QString winMessage = QString("%1 has won the game with $%2!").arg(player->getName()).arg(player->getMoney());
            QMessageBox winBox;
            winBox.setWindowTitle("Game Over");
            winBox.setText(winMessage);
            winBox.exec();
            QApplication::quit();
        }
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Prompt the user to enter the number of players
    bool ok;
    int numPlayers = QInputDialog::getInt(nullptr, "Enter Number of Players", "Enter a number between 2 and 6:", 2, 2, 6, 1, &ok);
    if (!ok) return 0; // User canceled, exit the application

    QVector<Player> players;
    QStringList availableCharacters = {"car", "boat", "cat", "moneybag", "hat", "duck"};

    QDialog dialog;
    QVBoxLayout layout(&dialog);
    QComboBox characterComboBox;
    characterComboBox.addItems(availableCharacters); // Add available characters to the combo box
    layout.addWidget(&characterComboBox);

    QPushButton submitButton("Submit");
    layout.addWidget(&submitButton);

    int playersSelected = 0; // Counter to track the number of players whose tokens have been selected

    QObject::connect(&submitButton, &QPushButton::clicked, [&]() {
        QString name = QInputDialog::getText(&dialog, QString("Enter Player %1's Name").arg(playersSelected + 1), "Name:");
        if (name.isEmpty()) return; // User canceled, do nothing

        QString character = characterComboBox.currentText();
        if (character.isEmpty()) return; // No character selected, do nothing

        availableCharacters.removeAll(character);

        players.append(Player(name, playersSelected + 1, character, 0, 1500)); // Assuming initial position is 0 and initial money is 1500
        characterComboBox.clear();
        characterComboBox.addItems(availableCharacters); // Update the combo box with remaining available characters
        dialog.setWindowTitle(QString("Select Player %1's Token").arg(playersSelected + 2)); // Set window title for the next player
        ++playersSelected; // Increment the counter

        if (playersSelected == numPlayers) // If tokens have been selected for all players, close the dialog
            dialog.accept();
    });

    // Show the dialog
    dialog.setWindowTitle(QString("Select Player %1's Token").arg(playersSelected + 1));
    dialog.exec();
    if (dialog.result() == QDialog::Rejected) return 0; // User canceled, exit the application

    // Create and show the board widget
    BoardWidget boardWidget(players);
    boardWidget.setWindowTitle("Monopoly Board");
    boardWidget.show();

    return app.exec();
}


