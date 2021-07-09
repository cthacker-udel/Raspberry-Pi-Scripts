#include "monster.h"

int count_monsters(monster *theMonsters,int len){

    return len;

}

int count_undead_monsters(monster *theMonsters, int len){

    int count = 0;
    for(int i = 0; i < len; i++){

        monster theMonster = *(theMonsters+i);
        if(theMonster.undead){
            count++;
        }

    }
    return count;


}
