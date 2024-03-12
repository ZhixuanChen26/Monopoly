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
    // If the property has no owner, or the player is the owner, dont need to pay rent
    if (property->getOwner() == nullptr || property->getOwner() == this) {
        return;
    }

    int rent = property->getRent();
    bool paymentSuccess = payRent(rent);

    if (!paymentSuccess) {
        // Insufficient funds, a dialog box pops up
        QMessageBox msgBox;
        msgBox.setWindowTitle("Insufficient funds");
        msgBox.setText("You don’t have enough funds to pay the rent");
        msgBox.setInformativeText("Do you want to sell your property or mortgage them to raise funds?");

        QPushButton *sellButton = msgBox.addButton("sell property", QMessageBox::YesRole);
        QPushButton *mortgageButton = msgBox.addButton("mortgage property", QMessageBox::NoRole);
        QPushButton *cancelButton = msgBox.addButton("cancel", QMessageBox::RejectRole);

        msgBox.exec();

        if (msgBox.clickedButton() == sellButton) {
            // Player chooses to sell property
            sell(property);
        } else if (msgBox.clickedButton() == mortgageButton) {
            // Players choose mortgage property
            mortgage(property);
        } else if (msgBox.clickedButton() == cancelButton) {
            // Player chooses to cancel, go bankrupt, quit the game.

        }
    }else {
        // Successfully pay rent to the owner of the property
        property->getOwner()->receiveMoney(rent);
    }
}

void Player::receiveMoney(int amount) {
    money += amount;
}

void Player::sell(Property* property) {
    // Sell the designated properties
    // Update player funds and property ownership
}

void Player::mortgage(Property* property) {
    // Mortgage designated property
    // Update player funds and property mortgage status
}


