#include <string>
#include <iostream>
using namespace std;

class Car{

    string manufacturer;
    int year;
    int miles;
    friend class Rent;

    public:

        Car(string,int,int); // manufacturer,year,miles

        Car();
        
        int getYear();

        int getMiles();

        string getManufacturer();

};
