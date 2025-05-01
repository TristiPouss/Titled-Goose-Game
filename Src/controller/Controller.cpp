#include "Controller.h"


Controller::Controller() {
    // Initialize the game and view
    game = gooseGameModel::Game();
    view = View();
    
};

void Controller::update() {
    // Update the game state
    
    game.nextTurn();
    view.update();
}

void Controller::display(int facetNumber) {
    // Draw the current scene
    view.draw(facetNumber);
}