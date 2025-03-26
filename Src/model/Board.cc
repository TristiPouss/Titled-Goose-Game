#include "Board.h"


Board::Board() : size(DEFAULT_SIZE)  {
    init();
}

Board::~Board() {
    cells.clear();
    players.clear();
}


void Board::init() {
    for (int i = 0; i < size; i++) {
        if (i % 9 == 0) {
            cells.push_back(GooseCell());
        } else if (i % 7 == 0) {
            cells.push_back(TrapCell(2));
        } else {
            cells.push_back(NormalCell());
        }
    }
}