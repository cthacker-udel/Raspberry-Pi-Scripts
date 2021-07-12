#include <cmath>
#include <string>
#include <iostream>
#include <stdlib.h>
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
    User *renter = new User();
    Car *car = new Car();

    public:

        Rent(string,int,double); // type --> discerns which number to apply to, days, months or years, and rate



};