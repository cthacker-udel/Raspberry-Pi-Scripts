#include <string>
#include <iostream>
#include <cmath>
using namespace std;


class Pitcher{

    string name;
    int age;
    int pitches;
    int strikes;
    int balls;
    int noHitters;

    public:

        Pitcher(string);

        Pitcher();

        int getAge();

        int getPitches();

        int getStrikes();

        int getBalls();

        int getNoHitters();

        void setAge(int);

        void setPitches(int);

        void setStrikes(int);

        void setBalls(int);

        void setNoHitters(int);

        ~Pitcher();


};