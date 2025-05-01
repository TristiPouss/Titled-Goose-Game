#include "Player.h"
#include "Board.h"

namespace gooseGameModel {
   
    void Player::move(int steps) {
        this->position += steps;
        if (this->position < 0) position = 0;
        if (this->position >= DEFAULT_SIZE_BOARD) position = (DEFAULT_SIZE_BOARD-1) - (position - (DEFAULT_SIZE_BOARD-1));
    }


    void Player::setTimeout(int to_wait) {
        if (to_wait < 0) {
            this->timeout = 0;
            return;
        }
        this->timeout = to_wait;
    }

    int Player::getTimeout() const {
        return this->timeout;
    }


    void Player::setPosition(int new_pos){
        if (new_pos < 0) {
            this->position = 0;
            return;
        }
        if (new_pos >= DEFAULT_SIZE_BOARD) {
            this->position = DEFAULT_SIZE_BOARD - 1;
            return;
        }

        this->position = new_pos;
    }


    unsigned Player::getPosition() const{
        return static_cast<unsigned int>(this->position);
    }


    void Player::setName(std::string new_name){
        this->name = new_name;
    }


    std::string Player::getName() const{
        return name;
    }


    char Player::getChar() const{
        return c;
    }


    void Player::setChar(char new_c){
        this->c = new_c;
    }

}