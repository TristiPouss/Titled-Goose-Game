#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Dice.h"
#include <memory>
#include <string>
#include <tuple>


namespace gooseGameModel {

enum stateGame {
    WAITING,
    PLAYING,
    END
};


/**
 * @class Game
 * @brief Represents the main game logic and state.
 * 
 * The Game class manages the game board, dice rolls, and turn progression.
 * It provides methods to advance the game state and access or modify its components.
 */
class Game{
    public:
    /**
    * @brief Default constructor for the Game class.
    * 
    * Initializes the game with default settings, including the board, dice, and turn counter.
    */
    Game();

    /**
    * @brief Add a player to the game
    */
    void addPlayer(std::string name, char representation);

    /**
     * @brief Get the current Turn
     */ 

    unsigned getTurn() const {
        return turn;
    }

    /**
    * @brief Get the current player 
    */
    unsigned getCurrentPlayer() const {
        return curr_player;
    }

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
    * @brief Retrieves the current state of the game.
    *
    * @return The current state of the game (WAITING, PLAYING, END).
    */

    stateGame getState() const;

    /**
      * @brief Launches the game
      */
    void launchGame();

    /**
      * @brief Reset the game
      */
    void resetGame();

    float *getCurrentPlayerPosition() const;

    private:

        // Variables
        std::unique_ptr<Board> board;
        std::tuple<Dice , Dice> dices;
        stateGame g_state;
        unsigned curr_player; 
        unsigned turn; // Current turn number


};

} // namespace

#endif