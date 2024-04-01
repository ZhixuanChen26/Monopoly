#ifndef DICE_H
#define DICE_H

#include <random>

class Dice {
private:
    int sides;
    std::mt19937 rng;

public:
    explicit Dice(int numSides = 6);
    int rollDice();
};

#endif // DICE_H
