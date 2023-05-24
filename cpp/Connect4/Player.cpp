#include "Player.hpp"

Player::Player(){

    this->name = "Computer";
    this->piece = 'C';

}

Player::Player(string newName, char newPiece){

    this->name = newName;
    this->piece = newPiece;


}

void Player::setPiece(char newPiece){

    this->piece = newPiece;

}

void Player::setName(string newName){

    this->name = newName;

}

char Player::getPiece(){

    return this->piece;

}

string Player::getName(){

    return this->name;

}