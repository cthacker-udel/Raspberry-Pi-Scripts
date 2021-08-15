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