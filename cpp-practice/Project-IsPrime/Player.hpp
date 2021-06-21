#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctype.h>
using namespace std;


class Player{

    string name;
    int points;
    friend class Game;

    public:

        Player();

        Player(string);


        int getPoints();

        string getName();

        void setName(string);

        void setPoints(int);


}