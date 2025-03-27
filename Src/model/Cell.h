#ifndef CELL_H
#define CELL_H

#include "Player.h"

namespace gooseGameModel {

/**
 * @brief Represents a cell in the game model.
 * 
 * The Cell class serves as a base class for defining cells in the game model.
 * It provides a virtual function `action` that can be overridden by derived classes
 * to define specific behavior for the cell.
 */
enum CellType{
    NORMAL,
    TRAP,
    TELEPORT,
    GOOSE,
};


/**
  * @brief Represents a cell in the game model.
*/
class Cell {
    public:
        // Does nothing since it's a normal cell
        virtual void action(Player& player);

        // Return the type of the cell
        virtual CellType getType() { return CellType::NORMAL; };
};


/**
 * @brief Represents a goose cell in the game model.
 */
class GooseCell : public Cell {
    public:
        
        // Moves the player to the next goose cell
        void action(Player& player) override;

        // Return the type of the cell
        CellType getType() override { return CellType::GOOSE; };
    };

/**
 * @brief Represents a trap cell in the game model.
 */
class TrapCell : public Cell {
    public:
        TrapCell(int turns);
        
        // Time out the player for a certain number of turns
     
       void action(Player& player) override;

       // Return the type of the cell
       CellType getType() override { return CellType::TRAP; };

       private: 
        int timeout;
    };

    


/**
 * @brief Represents a teleport cell (Well, Death and Bridge Cell) in the game model.
 */
class TeleportCell : public Cell {
    public:
        TeleportCell(int destination);
    
        // Moves the player to a specific cell
        void action(Player& player) override;

        // Return the type of the cell
        CellType getType() override { return CellType::TELEPORT; };
    
    private:
        int destination;
    };

}

#endif
