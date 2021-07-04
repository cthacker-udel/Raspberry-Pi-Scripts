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

Car *Car::constructCar(){

    /*

    Construct Driver first

    */

   string driverName;
   int driverAge;


   cout << "Enter the drivers name" << endl;
   cin >> driverName;
   cout << "Enter the drivers age" << endl;
   cin >> driverAge;
   Driver newDriver(driverName,driverAge);

   /*

    Constructing car

   */

    int carHp;
    int carMph;
    string carModel;


    cout << "Enter the horsepower of the car" << endl;
    cin >> carHp;
    cout << "Enter the mph of the car" << endl;
    cin >> carMph;
    cout << "Enter the model of the car" << endl;
    cin >> carModel;

    Car *newCar = new Car(newDriver,carModel,carHp,carMph);
    return newCar;

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