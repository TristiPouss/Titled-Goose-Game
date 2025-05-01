#include "Controller.h"


Controller::Controller() {
    // Initialize the game and view
    game = gooseGameModel::Game();
    view = View();
    
    game.addPlayer("Player 1", 'A');
    game.addPlayer("Player 2", 'B');
    game.addPlayer("Player 3", 'C');
    game.addPlayer("Player 4", 'D');

};

void Controller::update() {
    // Retrieve the game board
    auto board = game.getBoard();
    view.setCurrentPlayer(game.getCurrentPlayer());
    view.setBoard(board);
    
    // Update the view with the current game state
    view.update();
}


void Controller::playTurn() {
    // Play the current turn in the game
    if (game.getState() == gooseGameModel::stateGame::WAITING) {
       game.launchGame();
       return;
    }
    if (view.isAnimating()) {
        return;
    }
    game.playTurn();
}

void Controller::display(int facetNumber) {
    // Draw the current scene
    view.draw(facetNumber);
}