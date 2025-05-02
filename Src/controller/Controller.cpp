#include "Controller.h"
#include <bits/types/time_t.h>


Controller::Controller() {
    // Initialize the game and view
    game = gooseGameModel::Game();
    view = View();
    
    game.addPlayer("Player 1", 'A');
    game.addPlayer("Player 2", 'B');
    game.addPlayer("Player 3", 'C');
    game.addPlayer("Player 4", 'D');

};

void Controller::update(time_t frameTime) {
    double delta = difftime(frameTime, lastFrameTime);
    lastFrameTime = frameTime;
    // Retrieve the game board
    auto board = game.getBoard();
    
    view.setBoard(board);
    
    // Update the view with the current game state
    view.update(delta);

    // Update the current player in the view at the end of the frame in case of animation
    // This ensure that the camera is set to the right player
    if (!view.isAnimating()) view.setCurrentPlayer(game.getCurrentPlayer());
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
    view.switchToDiceScene();
}

void Controller::resetGame() {
    // Reset the game state
    game.resetGame();
}

void Controller::display(int facetNumber) {
    // Draw the current scene
    view.draw(facetNumber);
}