#ifndef CELL_H
#define CELL_H

/**
 * @brief Represents a cell in the game model.
 * 
 * The Cell class serves as a base class for defining cells in the game model.
 * It provides a virtual function `action` that can be overridden by derived classes
 * to define specific behavior for the cell.
 */
class Cell {
public:
    Cell();
    ~Cell();

private:
    /**
     * @brief The action to be performed when a player lands on this cell.
     */
    virtual void action();
};

#endif
