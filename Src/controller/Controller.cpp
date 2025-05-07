#include "Controller.h"
#include <time.h>


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
    // Change light and time of day
	if (game.getCurrentPlayer() == 0) {
		view.changeDayTime();
	}

    game.playTurn();
    auto dices = game.getDicesValues();
    auto dice1 = std::get<0>(dices);
    auto dice2 = std::get<1>(dices);
    view.setDicesValues(dice1, dice2);
    
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
