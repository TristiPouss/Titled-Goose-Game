#include "Game.h"
#include "Board.h"
#include "Dice.h"
#include "Player.h"
#include <iostream>
#include <memory>
#include <tuple>

namespace gooseGameModel {

    Game::Game() : g_state(stateGame::WAITING) ,curr_player(0), turn(0){
        board = std::make_shared<Board>();
        Dice d1, d2;
        dices = std::make_tuple(d1,d2);
    }

    void Game::nextTurn() {
        if (g_state == END || g_state == WAITING) {
            if (DEV) std::cout << "Game is not in a playable state." << std::endl;
            return;
        }
        turn++;
    }

    void Game::playTurn() {
        // Logic for playing the turn
        // This would include rolling the dice, moving players, etc.
       if (g_state == END || g_state == WAITING) {
            if (DEV)std::cout << "Game is not in a playable state." << std::endl;
            return;
        }
        int diceValue1 = std::get<0>(dices).roll();
        int diceValue2 = std::get<1>(dices).roll();
        dicesValues = std::make_tuple(diceValue1, diceValue2);

        if (DEV) std::cout << "Roll : " << diceValue1 << " " << diceValue2 << std::endl;
        std::shared_ptr<Player> currentPlayer = board->getPlayers()[curr_player];
        std::shared_ptr<Cell> currentCell = board->getCell(currentPlayer->getPosition());
        if (currentPlayer->getTimeout() > 0) {
            currentPlayer->setTimeout(currentPlayer->getTimeout() - 1);
            if (DEV) std::cout << "Player " << currentPlayer->getName() << " is trapped for " << currentPlayer->getTimeout() << " turns." << std::endl;
            curr_player = (curr_player + 1) % board->getNbPlayer();
            if (curr_player == 0) nextTurn();
            return;
        }

        board->movePlayer(curr_player, diceValue1 + diceValue2);
        currentCell->action(currentPlayer);


        // Check for victory conditions
        if (currentPlayer->getPosition() == board->getSize() - 1) {
            g_state = END;
            if (DEV) std::cout << "Player " << currentPlayer->getName() << " wins!" << std::endl;
        } else {
            curr_player = (curr_player + 1) % board->getNbPlayer();
            if (curr_player == 0) nextTurn();
        }
    }

    void Game::resetGame() {
        board->init();
        curr_player = 0;
        turn = 0;
        g_state = WAITING;
    }
    
    Board Game::getBoard() {
        return *board;
    }

    stateGame Game::getState() const {
        return g_state;
    }
    void Game::launchGame() {
        g_state = PLAYING;
        board->init();
        curr_player = 0;
        turn = 0;
    }
    void Game::addPlayer(std::string name, char representation) {
        std::shared_ptr<Player> p = std::make_shared<Player>(name,representation);
        board->addPlayer(p);
    }
};