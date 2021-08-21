#include "HockeyPlayer.hpp"


HockeyPlayer::HockeyPlayer(){

    this->name = "default";
    this->dob = "0/0/0";
    this->age = 0;
    this->height = 0;
    this->weight = 0;

}

HockeyPlayer::HockeyPlayer(string newName, string newDob, int newAge, int newHeight, int newWeight){

    this->name = newName;
    this->dob = newDob;
    this->age = newAge;
    this->height = newHeight;
    this->weight = newWeight;

}

string HockeyPlayer::getName(){

    return this->name;

}

string HockeyPlayer::getDOB(){

    return this->dob;

}

int HockeyPlayer::getAge(){

    return this->age;

}

int HockeyPlayer::getHeight(){

    return this->height;

}

int HockeyPlayer::getWeight(){

    return this->weight;

}

void HockeyPlayer::setName(string newName){

    this->name = newName;

}

void HockeyPlayer::setDOB(string newDob){

    this->dob = newDob;

}

void HockeyPlayer::setAge(int newAge){

    this->age = newAge;

}

void HockeyPlayer::setHeight(int newHeight){

    this->height = newHeight;

}

void HockeyPlayer::setWeight(int newWeight){

    this->weight = newWeight;

}