#include "party.h"

int sum_guests(party theParty){

    return theParty.werewolves + theParty.vampires + theParty.witches;

}

int were_only_werewolves(party theParty){

    if(theParty.vampires > 0 || theParty.witches > 0){
        return 0;
    }
    else{
        return 1;
    }

}

int total_folks(party theParty){

    return theParty.werewolves + (theParty.vampires * 2) + (theParty.witches * 2);

}