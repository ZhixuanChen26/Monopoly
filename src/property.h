#ifndef PROPERTY_H
#define PROPERTY_H

#include <QString>
#include "player.h"

class Property {
public:
    Property(QString name, int rent);

    QString getName() const;
    int getRent() const;
    void setOwner(Player* player);
    Player* getOwner() const;

private:
    QString name;
    int rent;
    Player* owner;
};

#endif // PROPERTY_H
