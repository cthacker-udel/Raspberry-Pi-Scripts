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