#include <string>
#include <iostream>
#include <cmath>
using namespace std;


class Pitcher{

    int pitches;
    int strikes;
    int balls;
    int noHitters;
    Pitcher *next;
    friend class PitcherTeam;

    public:

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