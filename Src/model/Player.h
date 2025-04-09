#ifndef PLAYER_H
#define PLAYER_H

#include <string>


namespace gooseGameModel {


/**
 * @class Player
 * @brief Represents a player in the game.
 */
class Player {
    public:
        /**
         * @brief Default constructor.
         */
        Player() : timeout(0), position(0), name("[]"), c('!') {};

        /**
         * @brief Constructor with name args
         */
        Player(std::string name, char representation) :timeout(0), position(0), name(name), c(representation) {} ;
        
     
        /**
         * @brief Moves the player a given number of steps.
         * @param steps Number of steps to move (positive or negative).
         */
        void move(int steps);

        /**
         * @brief Sets the timeout for the player's turn.
         * @param timeout Timeout value in turns.
         */
        void setTimeout(int to_wait);

        /**
         * @brief Gets the timeout for the player's turn.
         * @return Timeout value in turns.
         */
        int getTimeout() const;

        /**
         * @brief Sets the player's position on the board.
         * @param position Position value on the board.
         */
        void setPosition(int new_pos);

        /**
         * @brief Gets the player's position on the board.
         * @return Position value on the board.
         */
        unsigned getPosition() const;

        /**
         * @brief Sets the player's name.
         * @param name Name of the player.
         */
        void setName(std::string new_name);

        /**
         * @brief Gets the player's name.
         * @return Name of the player.
         */
        std::string getName() const;

        /**
         * @brief Gets the character representation of the player.
         * @return Character representing the player.
         */
        char getChar() const;

        /**
         * @brief Sets the character representation of the player.
         * @param c Character representing the player.
         */
        void setChar(char new_c);

    private:
        int timeout; ///< Timeout for the player's turn in turns.
        int position; ///< Position of the player on the board.
        std::string name; ///< Name of the player.
        char c; ///< Character representation of the player.
};

} //namespace
#endif