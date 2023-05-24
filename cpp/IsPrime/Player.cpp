#include "Player.hpp"

Player::Player(){

    name = "computer";
    points = 0;

}

Player::Player(string newName){

    name = newName;
    points = 0;

}

string Player::getName(){

    return name;

}

int Player::getPoints(){

    return points;

}

void Player::setName(string newName){

    name = newName;

}

void Player::setPoints(int newPoints){

    points = newPoints;

}

void Player::displayPoints(){

    cout << "\n" << this->name << " has a total of " << this->points << " points \n" << endl;

}