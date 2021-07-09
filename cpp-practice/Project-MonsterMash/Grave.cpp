#include "Grave.hpp"

Grave::Grave(string newName, string newMessage){

    name = newName;
    message = newMessage;

}

int Grave::count_grave_all(vector<Grave> graves){

    int count = 0;
    for(int i = 0; i < graves.size(); i++){

        string theMsg = graves.at(i).message;
        count += theMsg.length();

    }
    return count;

}

int Grave::count_grave_characters(vector<Grave> graves){

    int count = 0;
    for(int i = 0; i < graves.size(); i++){

        string theMsg = graves.at(i).message;
        for(int j = 0; j < theMsg.length(); j++){
            char theChar = theMsg.at(j);
            if(theChar != ' ' && theChar != '\n'){
                count++;
            }
        }

    }
    return count;
}


int Grave::estimate_grave_cost(vector<Grave> graves){

    int totalGraveChars = count_grave_characters(graves);
    return totalGraveChars * 2;

}