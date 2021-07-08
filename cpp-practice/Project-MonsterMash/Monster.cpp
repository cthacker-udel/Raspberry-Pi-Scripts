#include "Monster.hpp"

Monster::Monster(string newName, string newKind, int newSpookiness, bool newUndead){

    name = newName;
    kind = newKind;
    spookiness = newSpookiness;
    undead = newUndead;

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

int Monster::count_spooky_monsters(vector<Monster> monsters){

    int count = 0;
    for(int i = 0; i < monsters.size(); i++){
        if(monsters.at(i).spookiness >= 2){
            count++;
        }
    }
    return count;

}

int Monster::count_vampires(vector<Monster> monsters){

    int count = 0;
    for(int i = 0; i < monsters.size(); i++){
        if(monsters.at(i).kind.compare("vampire") == 0){
            count++;
        }
    }
    return count;

}
