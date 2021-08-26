#include "Card.hpp"


Card::Card(string newSuit, string newRank, int numRank){

    this->suit = newSuit;
    this->rank = newRank;
    this->numRank = numRank;


}

string Card::getSuit(){

    return this->suit;

}

string Card::getRank(){

    return this->rank;

}

int Card::getNumRank(){

    return this->numRank;

}