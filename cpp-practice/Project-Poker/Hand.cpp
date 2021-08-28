#include "Hand.hpp"


Hand::Hand(vector<Card> cards){

    this->hand = cards;

}

Card *Hand::deal(){

    if(this->hand.empty()){

        // deck has not been created yet
        return NULL;

    }
    else{

        Card *theCard = &this->hand[this->hand.size()-1];
        this->hand.pop_back();
        return theCard;

    }


}

vector<Card *>Hand::dealN(int n){


	vector<Card *> theCards;

    if(this->hand.empty()){

    	// return blank vector
    	return theCards;
    }
    else{

    	for(int i = 0; i < n; i++){

    		Card *theCard = &this->hand[this->hand.size()-1];
    		theCards.push_back(theCard);
    		this->hand.pop_back();

    	}
    	return theCards;


    }


}