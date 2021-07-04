#include "Race.hpp"

Race::Race(){

    name = "King of the Hill";
    milesEachLap = 10;
    laps = 50;
    head = NULL;

}


Race::Race(string newName, int newMilesEachLap, int newLaps){

    name = newName;
    milesEachLap = newMilesEachLap;
    laps = newLaps;
    head = NULL;

}

string Race::getName(){

    return name;

}

int Race::getMilesEachLap(){

    return milesEachLap;

}

int Race::getLaps(){

    return laps;

}


Car *Race::getHead(){

    return head;

}

int Race::getNumOfCars(){

    int count = 0;
    Car *tempHead = head;
    while(tempHead != NULL){
        tempHead = tempHead->next;
        count++;
    }
    return count;

}

void 