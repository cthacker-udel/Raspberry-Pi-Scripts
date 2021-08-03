#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Player{

    string name;
    char piece;
    friend class Board;

    public:

        Player();

        Player(string,char);

};