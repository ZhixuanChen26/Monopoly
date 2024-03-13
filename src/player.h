#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QList>
#include <QMessageBox>
#include <QPushButton>

// Forward declaration
class Property;

class Player : public QObject {
    Q_OBJECT

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
    void mortgage(Property* property);
    bool payRent(int amount);
    void declareBankruptcy();
    void displayPlayerInfo();

    // Public attributes
    bool hasGetOutofJailCard;
    bool isTurn;
    bool inJail;
    bool isBankrupt;

signals:
    void moneyChanged(int newAmount);
      
private:
    QString name;
    int playerID;
    QString character;
    int position;
    int money;
    QVector<Property*> properties;

};

#endif // PLAYER_H
