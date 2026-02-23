#ifndef DICE_H
#define DICE_H

#include <random>
/**
 * @class Dice
 * @brief Represents a dice with a customizable number of sides.
 *
 * This class uses a Mersenne Twister pseudo-random generator to simulate dice rolls.
 * @author Zhixuan Chen
 */
class Dice {
private:
    int sides; ///< Number of sides on the dice.
    std::mt19937 rng; ///< Mersenne Twister random number generator.

public:
    /**
     * @brief Constructor that initializes a dice with a specified number of sides.
     *
     * @param numSides Number of sides for the dice, defaults to 6.
     */
    explicit Dice(int numSides = 6);
    /**
     * @brief Rolls the dice and returns the result.
     *
     * @return A random integer between 1 and the number of sides on the dice.
     */
    int rollDice();
};

#endif // DICE_H
