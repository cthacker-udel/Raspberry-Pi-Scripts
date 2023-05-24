#include "Pilot.hpp"

Pilot::Pilot(string newName){

    this->name = newName;

}

Pilot::Pilot(){

    this->name = "Dinkleberg";

}

int Pilot::getAge(){

    return this->age;

}

int Pilot::getMilesFlown(){

    return this->milesFlown;

}

int Pilot::getCitiesTraveled(){

    return this->citiesTraveled;

}

vector<Plane> Pilot::getPlanesThrown(){

    return this->planesThrown;

}

void Pilot::addPlane(Plane thePlane){

    this->planesThrown.push_back(thePlane);

}

void Pilot::addMilesFlown(int newMilesFlown){

    this->milesFlown += newMilesFlown;

}

void Pilot::addCityTraveled(int newCity){

    this->citiesTraveled += newCity;

}

