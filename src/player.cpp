#include "player.h"
#include "property.h"

Player::Player(QString name, int playerID, QString character, int position, int initialMoney)
    : hasGetOutofJailCard(false), isTurn(false), inJail(false), isBankrupt(false), name(name),
    playerID(playerID), character(character), position(position), money(initialMoney) {}

QString Player::getName() const {
    return name;
}

int Player::getPlayerID() const {
    return playerID;
}

QString Player::getCharacter() const {
    return character;
}

int Player::getPosition() const {
    return position;
}

int Player::getMoney() const {
    return money;
}

bool Player::attemptToBuyProperty(Property* property) {
    if (property->getOwner() != nullptr) {
        return false;
    }
    if (money < property->getPrice()) {
        QString failureMessage = QString("%1 does not have enough funds to purchase %2.").arg(name, property->getName());
        QMessageBox::warning(nullptr, "Insufficient Funds", failureMessage);
        return false;
    }
    money -= property->getPrice();
    property->setOwner(this);
    properties.append(property);
    QString successMessage = QString("%1 has successfully purchased %2.").arg(name,property->getName());
    QMessageBox::information(nullptr, "Purchase Successful", successMessage);
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
    if (property->getOwner() == nullptr || property->getOwner() == this) {
        QMessageBox::information(nullptr, "No Rent to Pay", "You don't need to pay rent for this property.");
        return; // If the property has no owner or the player is the owner, there is no need to pay rent
    }

    int rent = property->getRent();
    bool paymentSuccess = payRent(rent);

    // try to increase money to pay the rent.
    while (!paymentSuccess && !properties.isEmpty()) {
        mortgage(property);
        paymentSuccess = payRent(rent);
    }

    if (paymentSuccess) {
        // Rent payment successful
        property->getOwner()->receiveMoney(rent);
        QMessageBox::information(nullptr, "Payment Success", "Rent payment successful.");
    } else{
        declareBankruptcy();
    }
}

void Player::receiveMoney(int amount) {
    money += amount;
}

void Player::declareBankruptcy() {
    QMessageBox::information(nullptr, "Payment Failure", "Bankruptcy");

    for (auto property : properties) {
        if(property != nullptr){
            property->setOwner(nullptr);
        }
    }
    properties.clear();
    money = 0;
    isBankrupt = true;
}

void Player::mortgage(Property* property) {
    // Mortgage designated property
    // Update player funds and property mortgage status
}
