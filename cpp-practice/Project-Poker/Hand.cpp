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

void Hand::createDeck(){

	string suits[] = {'Spades', 'Hearts', 'Diamonds', 'Clubs'};
	string ranks[] = {"1","2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
	int numRanks[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};

	for(int i = 0; i < 4; i++){ // suits

		for(int j = 0; j < 14; j++){ // ranks

			this->hand.push_back(Card(suits[i],ranks[j],numRanks[j]));

		}


	}


}