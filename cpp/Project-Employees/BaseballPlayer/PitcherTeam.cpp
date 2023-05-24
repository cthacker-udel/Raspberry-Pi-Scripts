#include "PitcherTeam.hpp"


PitcherTeam::PitcherTeam(){

    first = NULL;
    last = NULL;
    teamName = "";

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

void PitcherTeam::displayTeam(){

    if(this->first == NULL){
        cout << "Team is empty, unable to display team" << endl;
    }
    else{
        Pitcher *tmpFirst = this->first;
        while(tmpFirst != NULL){
            cout << tmpFirst->toString() << endl;
            tmpFirst = tmpFirst->next;
        }
        cout << "Team displayed!" << endl;
    }

}