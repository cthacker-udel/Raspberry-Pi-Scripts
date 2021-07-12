#include "Car.hpp"

Car::Car(){


    cout << "Enter the car manufacturer" << endl;
    cin >> this->manufacturer;
    cout << "Enter the car's year" << endl;
    cin >> this->year;
    cout << "Enter the car's miles" << endl;
    cin >> this->miles;

}

Car::Car(string newManufacturer, int newYear, int newMiles){

    this->manufacturer = newManufacturer;
    this->year = newYear;
    this->miles = newMiles;

}
