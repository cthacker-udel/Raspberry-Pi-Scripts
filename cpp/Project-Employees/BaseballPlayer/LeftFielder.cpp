#include "LeftFielder.hpp"

LeftFielder::LeftFielder(string newName){

    this->name = newName;
    this->catches = 0;
    this->doublePlays = 0;

}

LeftFielder::LeftFielder(string newName, int newCatches){

    this->name = newName;
    this->catches = newCatches;
    this->doublePlays = 0;

}

LeftFielder::LeftFielder(string newName, int newCatches, int newDoublePlays){

    this->name = newName;
    this->catches = newCatches;
    this->doublePlays = newDoublePlays;

}

string LeftFielder::getName(){

    return this->name;

}

int LeftFielder::getCatches(){

    return this->catches;

}

int LeftFielder::getDoublePlays(){

    return this->doublePlays;

}

void LeftFielder::setName(string newName){

    this->name = newName;

}

void LeftFielder::setCatches(int newCatches){

    this->catches = newCatches;

}

void LeftFielder::setDoublePlays(int newDoublePlays){

    this->doublePlays = newDoublePlays;

}