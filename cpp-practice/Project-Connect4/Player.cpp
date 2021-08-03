#include "Player.hpp"

Player::Player(){

    this->name = "Computer";
    this->piece = 'C';

}

Player::Player(string newName, char newPiece){

    this->name = newName;
    this->piece = newPiece;


}