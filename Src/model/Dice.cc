#include "Dice.h"
#include <random>

namespace gooseGameModel {

    int Dice::roll() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, max_value);
        return dis(gen);
    }
}