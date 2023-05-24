#include <string>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class Monster{

    string name;
    string kind;
    int spookiness;
    bool undead;

    public:

        Monster(string,string,int,bool);

        int countMonsters(vector<Monster>);

        int count_undead_monsters(vector<Monster>);

        float average_spookiness(vector<Monster>);

        float average_undead_spookiness(vector<Monster>);

        int count_spooky_monsters(vector<Monster>);

        int count_vampires(vector<Monster>);


};