#include "Rent.hpp"

Rent::Rent(string newType, int intValue, double newRate){

    srand(time(NULL));
    if(newType.compare("day") == 0){
        this->days = intValue;
        this->months = 0;
        this->years = 0;
    }
    else if(newType.compare("month") == 0){
        this->months = intValue;
        this->days = 0;
        this->years = 0;
    }
    else if(newType.compare("year") == 0){
        this->years = intValue;
        this->days = 0;
        this->months = 0;
    }

    this->rate = newRate;
    this->total = 0;
    this->id = rand() % 141;

};

Car *Rent::getCar(){
    return this->car;
}

User *Rent::getUser(){
    return this->renter;
}
