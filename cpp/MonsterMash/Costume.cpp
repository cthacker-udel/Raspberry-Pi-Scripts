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

string Costume::most_expensive_costume(vector<Costume> costumes){

    int theMax = max_price(costumes);
    string maxLabel;
    for(int i = 0; i < costumes.size(); i++){
        if(costumes.at(i).price == theMax){
            maxLabel = costumes.at(i).label;
        }
    }
    return maxLabel;

}

string Costume::find_last_medium(vector<Costume> costumes){

    string lastMedium;
    for(int i = costumes.size()-1; i >= 0; i--){
        vector<char> theSizes = costumes.at(i).sizes;
        for(int j = 0; j < theSizes.size(); j++){
            if(theSizes.at(j) == 'M'){
                return costumes.at(i).label;
            }
        }
    }
    return "";

}

string Costume::find_first_small(vector<Costume> costumes){

    string firstSmall;
    for(int i = 0; i < costumes.size(); i++){
        vector<char> theSizes = costumes.at(i).sizes;
        for(int j = 0; j < theSizes.size(); j++){
            if(theSizes.at(j) == 'S'){
                return costumes.at(i).label;
            }
        }
    }
    return "";

}