//
// Created by flyin on 8/28/2021.
//

#ifndef CARD_HPP
#define CARD_HPP

#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Card{

    string suit;
    string rank;
    int numRank;
    friend class Hand;

public:

    Card(string,string,int);

    string getSuit();

    string getRank();

    int getNumRank();

    void toStringPrint();

    string toString();

};


#endif //CARD_HPP
