#include "Costume.hpp"

Costume::Costume(string newLabel, int newPrice, vector<char> newSizes){

    label = newLabel;
    price = newPrice;
    sizes = newSizes;

}

int Costume::count_costumes(vector<Costume> costumes){

    return costumes.size();

}


int Costume::total_price(vector<Costume> costumes){

    int total = 0;
    for(int i = 0; i < costumes.size(); i++){
        total += costumes.at(i).price;
    }
    return total;

}

int Costume::count_sizes(vector<Costume> costumes){

    int total = 0;
    for(int i = 0; i < costumes.size(); i++){
        total += costumes.at(i).sizes.size();
    }

}

int Costume::max_price(vector<Costume> costumes){

    int theMax = 0;
    for(int i = 0; i < costumes.size(); i++){
        theMax = fmax(theMax,costumes.at(i).price);
    }
    return theMax;

}