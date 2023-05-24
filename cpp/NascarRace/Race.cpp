#include "Race.hpp"

Race::Race(){

    name = "King of the Hill";
    milesEachLap = 10;
    laps = 50;
    head = NULL;

}


Race::Race(string newName, int newMilesEachLap, int newLaps){

    name = newName;
    milesEachLap = newMilesEachLap;
    laps = newLaps;
    head = NULL;

}

string Race::getName(){

    return name;

}

int Race::getMilesEachLap(){

    return milesEachLap;

}

int Race::getLaps(){

    return laps;

}


Car *Race::getHead(){

    return head;

}

int Race::getNumOfCars(){

    int count = 0;
    Car *tempHead = head;
    while(tempHead != NULL){
        tempHead = tempHead->next;
        count++;
    }
    return count;

}

Car *Race::constructCar(){

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


void Race::addHead(){

    head = constructCar();

}