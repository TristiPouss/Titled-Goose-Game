#include "Cell.h"
#include "Player.h"
#include "Board.h"

namespace gooseGameModel {



void Cell::action(Player &player){
    // Do Nothing
}

void GooseCell::action(Player &player){
    player.move(9);
}

TeleportCell::TeleportCell(int destination){
    if (destination < 0) {
        this->destination = 0;
    } else if (destination >= DEFAULT_SIZE_BOARD) {
        this->destination = DEFAULT_SIZE_BOARD - 1;
    } else {
        this->destination = destination;
    }
}

void TeleportCell::action(Player &player){
    player.setPosition(this->destination);
}

TrapCell::TrapCell(int turns)  {
    if (turns < 0) {
        timeout = 0;
    } else {
        timeout = turns;
    }
}

void TrapCell::action(Player &player){
    player.setTimeout(timeout);
}

} //namespace