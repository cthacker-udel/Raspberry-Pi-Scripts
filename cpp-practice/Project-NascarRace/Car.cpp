#include "Car.hpp"

Car::Car(Driver newDriver, string theModel, int theHP, int theMph){

    theDriver = newDriver;
    hp = theHP;
    mph = theMph;
    model = theModel;
    milesDriven = 0;

}

Car::Car(string theModel, int theHp, int theMph){

    model = theModel;
    hp = theHp;
    mph = theMph;
    milesDriven = 0;
    theDriver = Driver();

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