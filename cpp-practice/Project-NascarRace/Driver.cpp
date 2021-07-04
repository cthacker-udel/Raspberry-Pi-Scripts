#include "Driver.hpp"

Driver::Driver(string newName){

    name = newName;
    age = 0;
    racesWon = 0;
    racesLost = 0;
    racesTied = 0;

}

Driver::Driver(string newName, int newAge){

    name = newName;
    age = newAge;
    racesWon = 0;
    racesLost = 0;
    racesTied = 0;

}

string Driver::getName(){

    return name;

}

int Driver::getAge(){

    return age;

}

int Driver::getRacesWon(){

    return racesWon;

}

void Driver::setRacesWon(int newRacesWon){

    racesWon = newRacesWon;

}

void Driver::setRacesLost(int newRacesLost){

    racesLost = newRacesLost;

}

void Driver::setRacesTied(int newRacesTied){

    racesTied = newRacesTied;

}