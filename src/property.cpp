#include "property.h"

Property::Property(QString name, int price, int rent) : name(name), price(prcie), rent(rent), owner(nullptr) {}

QString Property::getName() const {
    return name;
}

int Property::getPrice() const {
    return price;
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

