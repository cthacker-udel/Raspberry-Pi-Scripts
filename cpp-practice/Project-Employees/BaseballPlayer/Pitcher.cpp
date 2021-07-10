#include "Pitcher.hpp"

Pitcher::Pitcher(){

    this->pitches = 0;
    this->strikes = 0;
    this->balls = 0;
    this->noHitters = 0;

}

Pitcher::~Pitcher(){

    delete this;

}

int Pitcher::getPitches(){

    return this->pitches;

}

int Pitcher::getStrikes(){

    return this->strikes;

}

int Pitcher::getBalls(){

    return this->balls;

}

int Pitcher::getNoHitters(){

    return this->noHitters;

}

void Pitcher::setPitches(int newPitches){

    this->pitches = newPitches;

}

void Pitcher::setStrikes(int newStrikes){

    this->strikes = newStrikes;

}

void Pitcher::setBalls(int newBalls){

    this->balls = newBalls;

}

void Pitcher::setNoHitters(int newNoHitters){

    this->noHitters = newNoHitters;

}
