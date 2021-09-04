//
// Created by flyin on 8/28/2021.
//

#ifndef HAND_HPP
#define HAND_HPP

#pragma once

#include <vector>
#include "Card.hpp"
#include <list>
#include <iostream>
using namespace std;


class Hand{

    vector<Card> hand;

public:

    Hand(vector<Card>);

    Card *deal();

    vector<Card *> dealN(int);
    
    void createDeck();
    
    void shuffle(int);
    
    vector<Card> getHand();

};


#endif //HAND_HPP
