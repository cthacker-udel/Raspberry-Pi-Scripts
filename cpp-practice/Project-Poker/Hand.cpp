#include "Hand.hpp"


Hand::Hand(list<Card> cards){

    this->hand = cards;

}

Card *Hand::deal(){

    if(this->hand == NULL){

        // deck has not been created yet
        return NULL;

    }
    else{

        Card *theCard = this->hand.back;
        this->hand.pop_back();
        return theCard;

    }


}

list<Card *>Hand::dealN(int n){

    if(this->hand == NULL || this->hand.size < n){

        

    }


}