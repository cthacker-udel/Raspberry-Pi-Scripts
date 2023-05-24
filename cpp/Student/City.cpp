#include "City.hpp"


City::City(){
    name = "Default city name";
    population = 10000;
}


City::City(string newName, int newPopulation){
    name = newName;
    population = newPopulation;
}


vector<District> City::getDistricts(){
    return districts;
}


string City::getName(){
    return name;
}

int City::getPopulation(){
    return population;
}

void City::addDistrict(District newDistrict){
    districts.push_back(newDistrict);
}

void City::setName(string newName){
    name = newName;
}

void City::setPopulation(int newPop){
    population = newPop;
}


