#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <QList>

class Property;

class Player {
public:
    Player(QString name, int initialMoney);
    QString getName() const;
    int getMoney() const;
    bool payRent(int amount);
    bool attemptToBuyProperty(Property* property);
    void attemptToPayRent(Property* property);
    void receiveMoney(int amount);


private:
    QString name;
    int money;
    QList<Property*> properties;
};

#endif // PLAYER_H

