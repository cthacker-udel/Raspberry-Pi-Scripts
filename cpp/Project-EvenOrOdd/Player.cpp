#include "Player.hpp"


Player::Player(){

    name = "computer";
    points = 0;

}

Player::Player(string playerName){

    name = playerName;
    points = 0;

}

int Player::getPoints(){

    return points;

}


void Player::setPoints(int newPoints){

    points = newPoints;

}

string Player::getName(){

    return name;

}

void Player::setName(string newName){

    name = newName;

}

