#include "player.h"
#include "property.h"

Player::Player(QString name, int initialMoney) : name(name), money(initialMoney) {}

QString Player::getName() const {
    return name;
}

int Player::getMoney() const {
    return money;
}

bool Player::attemptToBuyProperty(Property* property) {
    if (property->getOwner() != nullptr) {
        return false;
    }
    if (money < property->getPrice()) {
        return false;
    }
    money -= property->getPrice();
    property->setOwner(this);
    properties.append(property);
    return true;
}

bool Player::payRent(int amount) {
    if (money < amount) {
        // The player does not have enough funds to pay the rent
        return false;
    }
    money -= amount;
    return true;
}

void Player::attemptToPayRent(Property* property) {
    // If the property has no owner, or the player is the owner, dont need to pay rent
    if (property->getOwner() == nullptr || property->getOwner() == this) {
        return;
    }
    int rent = property->getRent();
    bool paymentSuccess = payRent(rent);
    if (paymentSuccess) {
        property->getOwner()->receiveMoney(rent); // Pay rent to the owner of the property
    } else {
        // If there are insufficient funds
        // selling assets or mortgaging properties
        // Check if the player has enough funds to pay the rent
        // enough funds, pay it, or Bankruptcy， exit the game.
    }
}

void Player::receiveMoney(int amount) {
    money += amount;
}

