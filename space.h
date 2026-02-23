#ifndef SPACE_H
#define SPACE_H

#include <string>

/**
 * @brief Represents a space on the game board.
 *
 * This class holds information about a space on the board, such as its type
 * (e.g., property, card, tax), cost, whether it's occupied, and more.
 * @author Jingwen Liu
 */

class Space {

private:
    std::string name[2];
    std::string actionText[2];
    std::string spaceType; //property, card, tax, railroads, jail, etc
    int propertyCost;
    int freeParking;
    bool occupied;
    int owned;
    bool mortgaged;
    int houses;
    int rent;
    int tax;

public:
    /**
     * @brief Sets the names of the space.
     * @param inputName The first name of the space.
     * @param inputName2 The second name of the space.
     */
    void setName(std::string inputName,std::string inputName2);
    /**
     * @brief Sets the type of the space.
     * @param inputType The type of the space.
     */
    void setType(std::string inputType);
    /**
     * @brief Sets the property cost.
     * @param inputCost The cost of the property.
     */
    void setPropertyCost(int inputCost);
    /**
     * @brief Sets the amount of money for free parking.
     * @param inputMoney The amount of money.
     */
    void setFreeParking(int inputMoney);
    /**
     * @brief Sets whether the space is occupied.
     * @param inputOccupied The occupancy status (0 or 1).
     */
    void setOccupied(int inputOccupied);
    /**
     * @brief Sets the ownership status of the space.
     * @param inputOwnership The ownership status.
     */
    void setOwnership(int inputOwnership);
    /**
     * @brief Sets whether the property is mortgaged.
     * @param inputMortgage The mortgage status.
     */
    void setMortgaged(bool inputMortgage);
    /**
     * @brief Sets the rent of the property.
     * @param inputRent The rent amount.
     */
    void setRent(int inputRent);
    /**
     * @brief Sets the tax required to be paid.
     * @param inputTax The tax amount.
     */
    void setTax(int inputTax);
    /**
     * @brief Sets the action text for the space.
     * @param textInput The first piece of action text.
     * @param textInput2 The second piece of action text.
     */
    void setActionText(std::string textInput, std::string textInput2);
    /**
     * @brief Sets the number of houses on the property.
     * @param inputHouses The number of houses.
     */
    void setHouses(int inputHouses);
    /**
     * @brief Attempts to upgrade the property by adding a house.
     * @return true if the upgrade was successful, false otherwise.
     */
    bool upgrade();
    /**
     * @brief Gets the name of the space.
     * @param nameIndex Index to select which name to return (0 or 1).
     * @return The name of the space.
     */
    std::string getName(int nameIndex);
    /**
     * @brief Gets the property cost.
     * @return The cost of the property.
     */
    int getPropertyCost();
    /**
     * @brief Gets the amount of money for free parking.
     * @return The amount of money for free parking.
     */
    int getFreeParking();
    /**
     * @brief Checks if the property is mortgaged.
     * @return True if the property is mortgaged, false otherwise.
     */
    bool getMortgaged();
    /**
     * @brief Gets the rent of the property.
     * @return The rent amount.
     */
    int getRent();
    /**
     * @brief Gets the tax required to be paid.
     * @return The tax amount.
     */
    int getTax();
    /**
     * @brief Gets the ownership status of the space.
     * @return The ownership status.
     */
    int getOwnership();
    /**
     * @brief Gets the action text for the space.
     * @param textIndex Index to select which text to return (0 or 1).
     * @return The action text of the space.
     */
    std::string getActionText(int textIndex);
    /**
     * @brief Gets the type of the space.
     * @return The type of the space.
     */
    std::string getType();
    /**
     * @brief Gets the number of houses on the property.
     * @return The number of houses.
     */
    int getHouses();

};
#endif //SPACE_H
