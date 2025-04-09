#include "Cell.h"
#include "Player.h"


void NormalCell::action(Player &player){
    // Do Nothing
}

void GooseCell::action(Player &player){
    player.move(9);
}

TeleportCell::TeleportCell(int destination) : destination(destination){

}

void TeleportCell::action(Player &player){
    player.setPosition(this->destination);
}

TrapCell::TrapCell(int turns) : timeout(turns) {

}

void TrapCell::action(Player &player){
    player.setTimeout(timeout);
}