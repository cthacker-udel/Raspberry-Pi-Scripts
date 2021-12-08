#include "State.hpp"

State::State(){
    name = "Default city name";
    population = 10000;
    capital = "Default capital name";
}


State::State(string newName,int newPop){
    name = newName;
    population = newPop;
}


void State::setPopulation(int newPop){
    population = newPop;
}

void State::setName(string newName){
    name = newName;
}


int State::getPopulation(){
    return population;
}

string State::getCapital(){
    return capital;
}

string State::getName(){
    return name;
}


void State::addCity(City newCity){
    cities.push_back(newCity);
}
