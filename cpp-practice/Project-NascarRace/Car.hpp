#include <string>
#include <cmath>
#include <iostream>
#include "Driver.hpp"
using namespace std;

class Car{

    Driver theDriver;
    int hp;
    int mph;
    string model;
    int milesDriven;

    public:

        Car(Driver,string,int,int);

        Car(string,int,int);

        void setDriver(Driver);

        int getHP();

        int getMPH();

        string getModel();

        int getMilesDriven();

        void setMilesDriven(int);

};