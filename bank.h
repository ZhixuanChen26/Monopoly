#ifndef BANK_H
#define BANK_H
#include <string>
class Bank {
private:
    int moneyAmount;
public:
    Bank();
    int getAmount();
    void give_money(int amount);
    void take_money(int amount);
};
#endif

