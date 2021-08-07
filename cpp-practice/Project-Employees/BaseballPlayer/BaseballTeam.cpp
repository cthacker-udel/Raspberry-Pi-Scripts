#include "BaseballTeam.hpp"


Player * BaseballTeam::newPlayer(string newName, int newAge){

    if(this->first == NULL){
        this->first = new Player(newName,newAge);
        this->last = this->first;
    }
    else{

        // add to linked list
        Player *tmpFirst = this->first;
        while(tmpFirst->next != NULL){

            tmpFirst = tmpFirst->next;

        }
        tmpFirst->next = new Player(newName,newAge);

    }

}


