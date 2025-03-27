#include "Board.h"
#include "Cell.h"
#include <iostream>
#include <memory>


namespace gooseGameModel {


Board::Board() : size(DEFAULT_SIZE_BOARD)  {
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

void Board::addPlayer(Player &p) {
    players.push_back(p);
}

int Board::getSize() {
    return size;
}

std::vector<std::shared_ptr<Cell>> &Board::getCellsTab() {
    return cells;
}

std::shared_ptr<Cell> &Board::getCell(unsigned long index) {
    return cells[index];
}


// TO CHANGE
void Board::toString() {
    std::cout << "Board: " << std::endl;
    for (int i = 0; i < size; i++) {
        if (i % 10 == 0) {
            std::cout << std::endl;
        }
        std::cout << i << " ";
    }
}

std::vector<Player> Board::getPlayers() {
    return players;
}

void Board::movePlayer(int playerIndex, int diceValue){
    Player p = players[static_cast<std::vector<Player>::size_type>(playerIndex)];
    p.move(diceValue);
    cells[static_cast<std::vector<Cell>::size_type>(p.getPosition())]->action(p);
}
}