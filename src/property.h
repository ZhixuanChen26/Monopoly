#ifndef PROPERTY_H
#define PROPERTY_H

#include <QString>
#include "player.h"

class Property {
public:
    Property(QString name, int price, int rent);

    QString getName() const;
    int getPrice() const;
    int getRent() const;
    void setOwner(Player* player);
    Player* getOwner() const;

private:
    QString name;
    int price;
    int rent;
    Player* owner;
};

#endif // PROPERTY_H

