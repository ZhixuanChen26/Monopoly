#include "property.h"

Property::Property(QString name, int rent) : name(name), rent(rent), owner(nullptr) {}

QString Property::getName() const {
    return name;
}

int Property::getRent() const {
    return rent;
}

void Property::setOwner(Player* player) {
    owner = player;
}

Player* Property::getOwner() const {
    return owner;
}
