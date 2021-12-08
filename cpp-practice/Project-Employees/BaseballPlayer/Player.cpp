#include "Player.hpp"

Player::Player(string newName, int newAge){

    name = newName;
    age = newAge;

}

string Player::toString(){

    return "-=-=-=Player " + this->name + "-=-=-=\nAge : " + this->age;

}