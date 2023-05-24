#include "grave.h"

int count_grave_all(grave *graves, int len){


    int total = 0;
    for(int i = 0; i < len; i++){

        grave theGrave = *(graves+i);
        int graveMessageLen = strlen(theGrave.message);
        int graveNameLen = strlen(theGrave.name);
        total += graveMessageLen + graveNameLen;

    }
    return total;

}


int count_grave_characters(grave *graves, int len){

    int total = 0;
    for(int i = 0; i < len; i++){

        grave theGrave = *(graves+i);
        int graveMessageLen = theGrave.message;
        int graveNameLen = theGrave.name;
        for(int j = 0; j < graveMessageLen; j++){

            char graveMessageChar = *(theGrave.message+j);
            if(isalpha(graveMessageChar)){
                total++;
            }

        }
        for(int j = 0; j < graveNameLen; j++){

            char graveNameChar = *(theGrave.name);
            if(isalpha(graveNameChar)){
                total++;
            }

        }

    }
    return total;

}

int estimate_grave_cost(grave *graves, int len){

    int total = count_grave_characters(graves,len) * 2;
    return total;

}

int count_shouters(grave *graves, int len){

    int count = 0;
    int foundShouter = 0;
    for(int i = 0; i < len; i++){

        grave theGrave = *(graves+i);
        int graveMessageLen = strlen(theGrave.message);
        for(int j = 0; j < graveMessageLen; j++){

            char graveMessageChar = *(theGrave.message+j);
            if(toupper(graveMessageChar) == graveMessageChar){
                continue;
            }
            else{
                foundShouter = 0;
                break;
            }
            foundShouter = 1;

        }
        if(foundShouter){
            count++;
        }

    }
    return count;


}