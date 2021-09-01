#include "Card.hpp"
#include "Hand.hpp"
#include <list>
#include <map>
#include <string>
#include <vector>
using namespace std;

/*
 * Combos:
 *
 * Royal Flush
 * Straight Flush
 * Four of a Kind
 * Full House
 * Flush
 * Straight
 * Three of a Kind
 * Two pair
 * Pair
 * High Card
 *
 */

bool isSameSuit(Hand hand){
	
	vector<Card> cards = hand.getHand();
	/*
	 * 
	 * Any size hand, return if all same suit
	 * 
	 */
	
	string theSuit = cards[0].getSuit();
	
	for(int i = 0; i < (int)cards.size(); i++){
		
		string iSuit = cards[i].getSuit();
		if(theSuit != iSuit){
			return false;
		}
		
	}
	return true;
}


bool isRoyalFlush(Hand hand){

	vector<Card> cards = hand.getHand();

	if(cards.size() < 5){
		return false;
	}
	else{

		vector<string> suits;
		for(Card eachcard : cards){

			suits.push_back(eachcard.getSuit());

		}
		list<string> listSuits;
		for(int i = 0; i < (int)suits.size(); i++){
			listSuits.push_back(suits[i]);
		}
		list<string> uniqueSuits(listSuits);
		uniqueSuits.unique();
		int count = 0;
		string suitFrequency[4][2];
		int placement = 0;
		for(string eachsuit : uniqueSuits){
			for(int i = 0; i < (int)suits.size(); i++){

				if(suits[i] == eachsuit){
					count++;
				}

			}
			suitFrequency[placement][0] = eachsuit;
			suitFrequency[placement][1] = count+"";
			placement++;
			count = 0;
		}

		// collected all suit frequencies, now cycle through each pair, and if frequency >= 5, then cycle through the hand
		// and check if it is the correct collection of cards

		bool KingFound = false;
		bool JackFound = false;
		bool QueenFound = false;
		bool AceFound = false;
		bool TenFound = false;

		for(int i = 0; i < 4; i++){

			for(int j = 0; j < 2; j++){

				if(stoi(suitFrequency[i][1]) >= 5){
					// valid suit to check

					for(Card eachcard : cards){

						int rank = eachcard.getNumRank();
						string suit = eachcard.getSuit();
						if(suit == suitFrequency[i][0]){
							if(rank == 14){
								// ace
								AceFound = true;
							}
							else if(rank == 13){
								// king
								KingFound = true;
							}
							else if(rank == 12){
								// queen
								QueenFound = true;
							}
							else if(rank == 11){
								// jack
								JackFound = true;
							}
							else if(rank == 10){
								// ten
								TenFound = true;
							}
						}

					}
					if(AceFound && KingFound && QueenFound && JackFound && TenFound){

						// royal flush
						return true;

					}

				}


			}

		}
		return false;

		// check all suit frequencies


	}





}