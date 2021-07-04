#include "Driver.hpp"
#include "Car.hpp"

class Race{

    string name;
    int milesEachLap;
    int laps;
    Car *head;

    public:

        Race();

        Race(string,int,int);

        string getName();

        int getMilesEachLap();

        int getLaps();

        Car *getHead();

        int getNumOfCars();

        void addHead();
        
        Car *constructCar();


};