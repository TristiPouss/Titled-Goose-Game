#include "Cell.h"
#include "Player.h"
#include "Board.h"


#include <iostream>

namespace gooseGameModel {



void Cell::action(std::shared_ptr<Player> player){
    // Does nothing, supress warning
    player->move(0);
}

void GooseCell::action(std::shared_ptr<Player> player){
    if (DEV) std::cout << "Goose Cell: Moving player " << player->getName() << " forward 9 spaces." << std::endl;
    player->move(9);

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

void TeleportCell::action(std::shared_ptr<Player> player){
    player->setPosition(this->destination);
}

TrapCell::TrapCell(int turns)  {
    if (turns < 0) {
        timeout = 0;
    } else {
        timeout = turns;
    }
}

void TrapCell::action(std::shared_ptr<Player> player){
    player->setTimeout(timeout);
}

} //namespace