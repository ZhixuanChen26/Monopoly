#include "dice.h"
#include <random>

Dice::Dice(int numSides) : sides(numSides), rng(std::random_device{}()) {}

int Dice::rollDice() {
    std::uniform_int_distribution<int> dist(1, sides);
    return dist(rng);
}
