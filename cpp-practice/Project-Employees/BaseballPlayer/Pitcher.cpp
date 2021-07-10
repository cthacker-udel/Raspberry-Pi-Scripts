#include "Pitcher.hpp"

Pitcher::Pitcher(string newName){

    this->name = newName;
    this->age = 0;
    this->pitches =0;
    this->strikes = 0;
    this->balls = 0;
    this->noHitters = 0;

}

Pitcher::Pitcher(){

    this->name = "Ron Johnson";
    this->age = 0;
    this->pitches = 0;
    this->strikes = 0;
    this->balls = 0;
    this->noHitters = 0;

}

Pitcher::~Pitcher(){
    
    delete this;

}