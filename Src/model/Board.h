#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <iostream>

#include "Cell.h"
#include "Player.h"

#define DEFAULT_SIZE 40

/**
 * @class Board
 * @brief Represents the game board, managing cells and players.
 */
class Board {
public:
    /**
     * @brief Constructs a new Board object.
     */
    Board();

    /**
     * @brief Destroys the Board object.
     */
    ~Board();

    /**
     * @brief Prints a string representation of the board.
     */
    void toString();

    /**
     * @brief Initializes the board with default settings.
     */
    void init();

    /**
     * @brief Adds a player to the board.
     * @param p The player to add.
     */
    void addPlayer(Player p);

    /**
     * @brief Gets the size of the board.
     * @return The size of the board.
     */
    int getSize();

    /**
     * @brief Gets the vector of cells on the board.
     * @return A vector containing all the cells on the board.
     */
    std::vector<Cell> getCellsTab();

    /**
     * @brief Gets a specific cell on the board by index.
     * @param index The index of the cell to retrieve.
     * @return The cell at the specified index.
     */
    Cell getCell(int index);

    /**
     * @brief Gets the list of players on the board.
     * @return A vector containing all the players on the board.
     */
    std::vector<Player> getPlayers();

    /**
     * @brief Moves a player on the board based on a dice roll.
     * @param playerIndex The index of the player to move.
     * @param diceValue The value of the dice roll.
     */
    void movePlayer(int playerIndex, int diceValue);

private:
    int size; /**< The size of the board. */
    std::vector<Cell> cells; /**< The cells that make up the board. */
    std::vector<Player> players; /**< The players currently on the board. */
};

#endif