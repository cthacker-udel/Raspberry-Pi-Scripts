#include <string>
#include <cmath>
#include <iostream>
#include "Pitcher.cpp"
#include "Batter.cpp"
using namespace std;

class Player{

    string name;
    int age;
    Player *next;
    friend class BaseballTeam;

    public:

        Player(string,int);


};