#include <string>
#include <cmath>
#include <iostream>
using namespace std;

class Driver{

    string name;
    int age;
    int racesWon;
    int racesLost;
    int racesTied;

    public:

        Driver(string);

        Driver(string,int);

        string getName();

        int getAge();

        int getRacesWon();

        void setRacesWon(int);

        void setRacesLost(int);

        void setRacesTied(int);


};