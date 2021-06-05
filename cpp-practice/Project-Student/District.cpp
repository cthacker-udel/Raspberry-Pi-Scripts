#include "District.hpp"


District::District(){
    name = "Thacker Ville";
    founded = 1800;
    population = 1;
}


District::District(string newName){
    name = newName;
    founded = 1800;
    population = 1;
}

District::District(string newName, int newPopulation){
    name = newName;
    founded = 1800;
    population = newPopulation;
}


District::District(string newName, int newPopulation, int newFounded){
    name = newName;
    founded = newFounded;
    population = newPopulation;
}


int District::getPopulation(void){
    return population;
}

string District::getName(void){
    return name;
}
