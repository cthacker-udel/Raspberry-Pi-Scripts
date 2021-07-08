#include "Party.hpp"

Party::Party(string newType,int newWerewolves,int newVampires,int newWitches){

    werewolves = newWerewolves;
    vampires = newVampires;
    witches = newWitches;
    type = newType;

}

int Party::sumGuests(Party theParty){

    return witches + vampires + werewolves;

}

bool Party::were_only_werewolves(Party theParty){

    if(vampires > 0 || witches > 0){
        return false;
    }
    else{
        return true;
    }

}

string Party::check_party_size(Party theParty){

    int numGuests = sumGuests();
    if(numGuests <= 20){
        return "small";
    }
    else if(numGuests > 20 && numGuests < 40){
        return "medium";
    }
    else{
        return "big";
    }

}

float Party::check_party_ratio(Party theParty){

    int numWerewolves = werewolves;
    int numVampires = vampires *2 ;
    return (numVampires * 1.0) / numWerewolves;

}



