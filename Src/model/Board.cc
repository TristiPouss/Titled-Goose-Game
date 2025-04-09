#include "Board.h"
#include "Cell.h"


Board::Board() : size(DEFAULT_SIZE)  {
    init();
}

Board::~Board() {
    cells.clear();
    players.clear();
}


void Board::init() {
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
                cells.push_back(GooseCell());
                break;
            case 6:
                cells.push_back(TeleportCell(12));
                break;
            case 19:
                cells.push_back(TrapCell(2));
                break;
            case 31:
                cells.push_back(TeleportCell(20));
                break;
            case 39:
                cells.push_back(TeleportCell(1));
                break;
        }
    }
}

void Board::addPlayer(Player &p) {
    players.push_back(p);
}

int Board::getSize() {
    return size;
}

std::vector<Cell> &Board::getCellsTab() {
    return cells;
}

Cell &Board::getCell(int index) {
    return cells[index];
}

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
    Player p = players[playerIndex];
    p.move(diceValue);
}