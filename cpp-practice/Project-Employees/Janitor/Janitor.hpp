#include <string>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;


class Janitor{

    string name;
    int age;
    int yearsWorked;
    int bathroomsCleaned;
    int officesCleaned;
    int hallwaysCleaned;

    public:

        Janitor();

        Janitor(string,int,int);

        void addBathroomCleaned();

        void addOfficeCleaned();

        void addHallwayCleaned();

        int getAge();

        int getYearsWorked();

        string getName();

        int getBathroomsCleaned();

        int getOfficesCleaned();

        int getHallwaysCleaned();




};
