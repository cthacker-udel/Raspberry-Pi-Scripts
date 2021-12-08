#include "Janitor.hpp"

Janitor::Janitor(){

    name = "Gerry";
    age = 45;
    yearsWorked = 20;

}

Janitor::Janitor(string newName, int newAge, int newYearsWorked){

    name = newName;
    age = newAge;
    yearsWorked = newYearsWorked;

}

void Janitor::addBathroomCleaned(){

    bathroomsCleaned++;

}

void Janitor::addOfficeCleaned(){

    officesCleaned++;

}

void Janitor::addHallwayCleaned(){

    hallwaysCleaned++;

}