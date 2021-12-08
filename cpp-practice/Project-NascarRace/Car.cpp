#include "Car.hpp"

Car::Car(Driver newDriver, string theModel, int theHP, int theMph){

    theDriver = newDriver;
    hp = theHP;
    mph = theMph;
    model = theModel;
    milesDriven = 0;
    next = NULL;
    prev = NULL;

}

Car::Car(string theModel, int theHp, int theMph){

    model = theModel;
    hp = theHp;
    mph = theMph;
    milesDriven = 0;
    theDriver = Driver();
    next = NULL;
    prev = NULL;

}

Car::~Car(){
    delete this;
}

void Car::setDriver(Driver newDriver){

    theDriver = newDriver;

}

int Car::getHP(){

    return hp;

}

int Car::getMPH(){

    return mph;

}

string Car::getModel(){

    return model;

}

int Car::getMilesDriven(){

    return milesDriven;

}

void Car::setMilesDriven(int newMilesDriven){

    milesDriven = newMilesDriven;

}