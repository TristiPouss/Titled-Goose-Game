#include "Game.h"
#include "Board.h"
#include "Dice.h"
#include <memory>
#include <tuple>

namespace gooseGameModel {

    Game::Game() : turn(0) {
        board = std::make_unique<Board>();
        Dice d1, d2;
        dices = std::make_tuple(d1,d2);
    }

    
};