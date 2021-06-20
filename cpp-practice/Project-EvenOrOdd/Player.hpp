#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Player{

    string name;
    int points;

    public:

        Player();

        Player(string);

        int getPoints();

        void setPoints(int);

        string getName();

        void setName(string);


};