#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <QVector>
#include <QMessageBox>
#include <QPushButton>

// Forward declaration
class Property;

class Player {
public:
    Player(QString name, int playerID, QString character, int position, int initialMoney);

    QString getName() const;
    int getPlayerID() const;
    QString getCharacter() const;
    int getPosition() const;
    int getMoney() const;

    bool attemptToBuyProperty(Property* property);
    void attemptToPayRent(Property* property);
    void receiveMoney(int amount);

    // Public attributes
    bool hasGetOutofJailCard;
    bool isTurn;
    bool inJail;
    bool isBankrupt;

private:
    QString name;
    int playerID;
    QString character;
    int position;
    int money;
    QVector<Property*> properties;

    bool payRent(int amount);
    void sell(Property* property);
    void mortgage(Property* property);
};

#endif // PLAYER_H
