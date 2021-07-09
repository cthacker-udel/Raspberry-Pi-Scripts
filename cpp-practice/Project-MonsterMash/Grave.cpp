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