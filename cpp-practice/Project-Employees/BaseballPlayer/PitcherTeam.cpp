#include "PitcherTeam.hpp"


PitcherTeam::PitcherTeam(){

    first = NULL;
    last = NULL;
    teamName = NULL;

}

PitcherTeam::PitcherTeam(string newName){

    this->teamName = newName;
    this->first= NULL;
    this->last = NULL;

}