#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include "Plane.hpp"
using namespace std;

class Pilot{

    string name;
    int age;
    int milesFlown;
    int citiesTraveled;
    vector<Plane> planesThrown;

    public:

        Pilot(string);

        Pilot();

        int getAge();

        int getMilesFlown();

        int getCitiesTraveled();

        vector<Plane> getPlanesThrown();



};