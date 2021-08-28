//
// Created by flyin on 8/28/2021.
//

#ifndef HAND_HPP
#define HAND_HPP
#include <vector>
#include "Card.hpp"
using namespace std;


class Hand{

    vector<Card> hand;

public:

    Hand(vector<Card>);


    Card *deal();

    vector<Card *> dealN(int);

};


#endif //HAND_HPP
