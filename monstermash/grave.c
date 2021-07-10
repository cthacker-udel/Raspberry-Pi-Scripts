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