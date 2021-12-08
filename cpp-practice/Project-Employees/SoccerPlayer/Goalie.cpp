#include "Goalie.hpp"

Goalie::Goalie(string newName){

    this->name = newName;

}

Goalie::Goalie(string newName, int theSaves, string newTeam){

    this->name = newName;
    this->saves = theSaves;
    this->team = newTeam;

}

void Goalie::setName(string theName){

    this->name = theName;

}

void Goalie::setSaves(int theSaves){

    this->saves = theSaves;

}

void Goalie::setTeam(string theTeam){

    this->team = theTeam;

}