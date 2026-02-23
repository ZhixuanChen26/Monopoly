#ifndef BANK_H
#define BANK_H
/**
 * @class Bank
 * @brief Manages the bank's money in the game.
 *
 * Allows operations like giving or taking money.
 * @author Jingwen Liu
 */
class Bank {
private:
    int moneyAmount; ///< Current amount of money in the bank.
public:
    /** @brief Constructor initializes bank with default amount. */
    Bank();
    /**
     * @brief Get current money amount in the bank.
     * @return Amount of money.
     */
    int getAmount();
    /**
     * @brief Add money to the bank.
     * @param amount Money to add.
     */
    void give_money(int amount);
    /**
     * @brief Withdraw money from the bank.
     * @param amount Money to withdraw.
     */
    void take_money(int amount);
};
#endif // BANK_H

