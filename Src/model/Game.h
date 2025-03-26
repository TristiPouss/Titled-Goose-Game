#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Dice.h"
#include <tuple>


/**
 * @class Game
 * @brief Represents the main game logic and state.
 * 
 * The Game class manages the game board, dice rolls, and turn progression.
 * It provides methods to advance the game state and access or modify its components.
 */
class Game{
    /**
    * @brief Default constructor for the Game class.
    * 
    * Initializes the game with default settings, including the board, dice, and turn counter.
    */
    Game();

    /**
    * @brief Destructor for the Game class.
    * 
    * Cleans up any resources used by the game.
    */
    ~Game();
    
    /**
    * @brief Advances the game to the next turn.
    * 
    * Updates the game state to reflect the start of a new turn.
    */
    void nextTurn();
    
    /**
    * @brief Executes the actions for the current turn.
    * 
    * Handles the logic for playing out the current turn, including dice rolls and board updates.
    */
    void playTurn();
    
    /**
    * @brief Retrieves the current game board.
    * 
    * @return The current state of the game board.
    */
    Board getBoard();
    
    /**
    * @brief Sets the game board to a new state.
    * 
    * @param b The new board state to set.
    * @return The updated game board.
    */
    Board setBoard(Board b);
 
    private:

        // Variables
        Board board;
        std::tuple<Dice , Dice> dices;
        int turn;

};

#endif