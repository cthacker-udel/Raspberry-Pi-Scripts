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

Pitcher *PitcherTeam::addToTeam(Pitcher *newPitcher){

    if(this->first = NULL){
        this->first = newPitcher;
        this->last = newPitcher;
    }
    else{

        Pitcher *tmpFirst = this->first;
        while(tmpFirst != NULL){
            tmpFirst = tmpFirst->next;
        }
        tmpFirst->next = newPitcher;


    }

}