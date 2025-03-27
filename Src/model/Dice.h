#ifndef DICE_H
#define DICE_H

namespace gooseGameModel {
/**
 * @class Dice
 * @brief Represents a dice that can be rolled to generate random numbers.
 */
class Dice {
    public:
        /**
         * @brief Default constructor for the Dice class.
         * Initializes the dice with a default maximum value of 6.
         */
        Dice();

        /**
         * @brief Parameterized constructor for the Dice class.
         * @param max_value The maximum value the dice can roll.
         */
        Dice(int max_value);

        /**
         * @brief Destructor for the Dice class.
         */
        ~Dice();

        /**
         * @brief Rolls the dice and generates a random number between 1 and max_value.
         * @return A random integer between 1 and max_value.
         */
        int roll();

    private:
        /**
         * @brief The maximum value of the dice (default: 6).
         */
        int max_value;
};

}
#endif