#include "Controller.h"


Controller::Controller() {
    // Initialize the game and view
    game = gooseGameModel::Game();
    view = View();
    
    game.addPlayer("Player 1", 'A');
    game.addPlayer("Player 2", 'B');
    game.addPlayer("Player 3", 'C');
    game.addPlayer("Player 4", 'D');

    // Set the initial player
    game.launchGame();

    game.playTurn();
};

void Controller::update() {
    // Retrieve the game board
    auto board = game.getBoard();
    view.setCurrentPlayer(game.getCurrentPlayer());
    view.setBoard(board);
    
    // Update the view with the current game state
    view.update();
}

void Controller::display(int facetNumber) {
    // Draw the current scene
    view.draw(facetNumber);
}