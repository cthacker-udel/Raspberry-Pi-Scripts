#include "Party.hpp"

Party::Party(){

    werewolves = 0;
    vampires = 0;
    witches = 0;
    type = "";

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



