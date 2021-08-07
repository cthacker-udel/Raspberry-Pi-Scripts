#include <stdlib.h>
#include "Player.cpp"
#include <string>
using namespace std;

class BaseballTeam{

    Player *first = NULL;
    Player *last = NULL;
    string name;

    public:

        Player *newPlayer(string,int);



};