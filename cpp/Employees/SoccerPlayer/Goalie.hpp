#include <string>
#include <cmath>
#include <stdlib.h>
#include <iostream>
using namespace std;


class Goalie{

    string name;
    int saves;
    string team;

    public:

        Goalie(string theName);

        Goalie(string theName, int theSaves, string theTeam);

        void setName(string);

        void setSaves(int);

        void setTeam(string);


};