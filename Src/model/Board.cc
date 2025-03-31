#include "Board.h"
#include "Cell.h"
#include "Player.h"
#include <iostream>
#include <memory>
#include <ostream>


namespace gooseGameModel {


Board::Board() : size(DEFAULT_SIZE_BOARD), nb_players(0)  {
    init();
}
Board::~Board() {
    cells.clear();
    players.clear();
}


void Board::init() {
    cells.clear();
    for (int i = 0; i < size; i++) {
        switch (i) {
            // Add special cells to the board - Goose, Teleport, Trap, etc.
            case 5:
            case 9:
            case 14:
            case 18:
            case 23:
            case 27:
            case 32:
            case 36:
                cells.push_back(std::make_shared<GooseCell>());
                break;
            case 6:
                cells.push_back(std::make_shared<TeleportCell>(12));
                break;
            case 19:
                cells.push_back(std::make_shared<TrapCell>(2));
                break;
            case 31:
                cells.push_back(std::make_shared<TeleportCell>(20));
                break;
            case 39:
                cells.push_back(std::make_shared<TeleportCell>(1));
                break;
            default:
                cells.push_back(std::make_shared<Cell>());
            }
        

    }
}

void Board::addPlayer(std::shared_ptr<Player> p) {
    players.push_back(p);
    nb_players++;
}

int Board::getSize() {
    return size;
}

std::vector<std::shared_ptr<Cell>> &Board::getCellsTab() {
    return cells;
}

std::shared_ptr<Cell> &Board::getCell(unsigned long index) {
    if (index >= cells.size()) {
        index = cells.size() - 1;
    }
    if (index < 0) {
        index = 0;
    }

    return cells[index];
}

unsigned long Board::getNbPlayer(){
    return nb_players;
}

// TO CHANGE
void Board::toString() {
    std::cout << "Board: " << std::endl;
    for (int i = 0; i < size; i++) {
        if (i % 10 == 0) {
            std::cout << std::endl;
        }
        bool playerOnCell = false;
        for (const auto &player : players) {
            if (player->getPosition() == i) {
            std::cout << "[" << player->getChar() << "] ";
            playerOnCell = true;
            break;
            }
        }
        if (playerOnCell) {
            continue;
        }
        if (std::dynamic_pointer_cast<GooseCell>(cells[i])) {
            std::cout << "[G] ";
        } else if (std::dynamic_pointer_cast<TeleportCell>(cells[i])) {
            std::cout << "[T] ";
        } else if (std::dynamic_pointer_cast<TrapCell>(cells[i])) {
            std::cout << "[X] ";
        } else {
            std::cout << "[" << i << "] ";
        }
    }
    std::cout << std::endl;
}

std::vector<std::shared_ptr<Player>> Board::getPlayers() {
    return players;
}

void Board::movePlayer(unsigned playerIndex, int diceValue){
    players[playerIndex]->move(diceValue);
    cells[static_cast<std::vector<Cell>::size_type>(players[playerIndex]->getPosition())]->action(players[playerIndex]);
}
}