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

float Monster::average_spookiness(vector<Monster> monsters){

    int numMonsters = monsters.size();
    float totalSpookiness = 0.0;
    for(int i = 0; i < monsters.size(); i++){
        totalSpookiness += monsters.at(i).spookiness;
    }
    return totalSpookiness / numMonsters;

}

float Monster::average_undead_spookiness(vector<Monster> monsters){

    int numUndead = count_undead_monsters(monsters);
    float totalUndeadSpookiness = 0.0;
    for(int i = 0; i < monsters.size(); i++){
        if(monsters.at(i).undead){
            totalUndeadSpookiness += monsters.at(i).spookiness;
        }
    }
    return totalUndeadSpookiness / numUndead;


}
