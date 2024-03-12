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
    void receiveMoney(int amount);
    bool payRent(int amount);
    void attemptToPayRent(Property* property);


private:
    QString name;
    int money;
    QList<Property*> properties;
};

#endif // PLAYER_H
