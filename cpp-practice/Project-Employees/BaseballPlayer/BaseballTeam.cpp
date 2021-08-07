#include "BaseballTeam.hpp"


Player * BaseballTeam::newPlayer(string newName, int newAge){

    if(this->first == NULL){
        this->first = new Player(newName,newAge);
        this->last = this->first;
    }
    else{

        // add to linked list
        


    }

}


