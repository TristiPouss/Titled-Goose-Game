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

/**
 * @brief Represents a normal cell in the game model.
 */
class NormalCell : public Cell {
    public:
        NormalCell();
        ~NormalCell();

        // Does nothing since it's a normal cell
        void action() override;
    };

/**
 * @brief Represents a goose cell in the game model.
 */
class GooseCell : public Cell {
    public:
        GooseCell();
        ~GooseCell();

        // Moves the player to the next goose cell
        void action() override;
    };

/**
 * @brief Represents a trap cell in the game model.
 */
class TrapCell : public Cell {
    public:
        TrapCell(int turns);
        ~TrapCell();

        // Time out the player for a certain number of turns
        void action() override;
    };


/**
 * @brief Represents a teleport cell (Well, Death and Bridge Cell) in the game model.
 */
class TeleportCell : public Cell {
    public:
        TeleportCell(int destination);
        ~TeleportCell();

        // Moves the player to a specific cell
        void action() override;
    };



#endif
