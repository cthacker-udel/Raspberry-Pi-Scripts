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

int Monster::count_undead_monsters(vector<Monster> monsters){

    int count = 0;
    for(int i = 0; i < monsters.size(); i++){
        if(monsters.at(i).undead){
            count++;
        }
    }
    return count;

}
