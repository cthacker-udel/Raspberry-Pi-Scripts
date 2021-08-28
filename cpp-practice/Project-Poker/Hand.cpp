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

	string suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
	string ranks[] = {"1","2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
	int numRanks[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};

	for(int i = 0; i < 4; i++){ // suits

		for(int j = 0; j < 14; j++){ // ranks

			this->hand.push_back(Card(suits[i],ranks[j],numRanks[j]));

		}


	}


}

void Hand::shuffle(int n){

	// shuffle n times

	// generate int list of indexes of vector, choose them at random,

	list<int> indexes;
	vector<Card> newCards;

	for(int i = 0; i < n; i++){

		// shuffling n times
		for(int i = 0; i < (int)this->hand.size(); i++){
			indexes.push_back(i);
		}

		for(int j = 0; j < (int)this->hand.size(); j++){

			int randIndex = rand() % indexes.size();
			int count = 0;
			list<int>::iterator it = indexes.begin();
			for(;it != indexes.end();it++,count++){

				if(count == randIndex){
					newCards.push_back(this->hand[*it]);
					indexes.remove(*it);
					break;
				}

			}


		}
		this->hand = newCards;
		newCards.clear();
	}

}