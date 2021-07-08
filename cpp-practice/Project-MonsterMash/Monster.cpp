#include "Monster.hpp"

Monster::Monster(){

    name = "";
    kind = "";
    spookiness = 0;
    undead = false;

}

int Monster::countMonsters(vector<Monster> monsters){

    return monsters.size();

}
