#include <cmath>
#include <string>
#include <iostream>
#include "Car.cpp"
#include "User.cpp"
using namespace std;



class Rent{

    int days;
    int months;
    int years;
    string type;
    double total;
    double rate;
    User renter;
    Car car;

    public:

        Rent(string,int,double); // type --> discerns which number to apply to, days, months or years, and rate




};