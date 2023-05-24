#include "PokerCombos.hpp"
using namespace std;
/*
 * Combos:
 *
 * Royal Flush - done
 * Straight Flush - done
 * Four of a Kind - done
 * Full House - done
 * Flush
 * Straight - done
 * Three of a Kind - done
 * Two pair - done
 * Pair - done
 * High Card - done
 *
 */

int PokerCombos::rankHand(Hand hand){

	if(this->isRoyalFlush(hand)){
		// 1
		return 1;
	}
	else if(this->isStraightFlush(hand)){
		return 2;
	}
	else if(this->isFourOfAKind(hand)){
		return 3;
	}
	else if(this->isFullHouse(hand)){
		return 4;
	}
	else if(this->isFlush(hand)){
		return 5;
	}
	else if(this->isStraight(hand)){
		return 6;
	}
	else if(this->isThreeOfAKind(hand)){
		return 7;
	}
	else if(this->isTwoPair(hand)){
		return 8;
	}
	else if(this->isPair(hand)){
		return 9;
	}
	else{
		return 10; // high card
	}

}

int PokerCombos::findHighCard(Hand hand, int times){

	if(times == (int)hand.getHand().size()){
		// reached end of hand, declare tie by returning -1
		return -1;
	}
	else{

		return sortNumRanks(hand)[times];

	}

}

bool PokerCombos::isFlush(Hand hand){

	return isSameSuit(hand);

}

bool PokerCombos::isRoyalFlush(Hand hand){

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

bool PokerCombos::isThreeOfAKind(Hand hand){

	vector<int> ranks = sortNumRanks(hand);

	bool foundThreeOfAKind = false;

	for(int i = 0; i < (int)ranks.size(); i++){

		foundThreeOfAKind = findNumKinds(hand,ranks[i]) == 3;

	}
	return foundThreeOfAKind;


}

bool PokerCombos::isTwoPair(Hand hand){

	bool foundTwoKind = false;
	int firstRank = 0;

	vector<int> ranks = sortNumRanks(hand);

	for(int i = 0; i < (int)ranks.size(); i++){

		int numKind = findNumKinds(hand,ranks[i]);

		if(numKind == 2 && !foundTwoKind){
			firstRank = ranks[i];
			foundTwoKind = true;
		}
		if(numKind == 2 && foundTwoKind && ranks[i] != firstRank){

			return true;

		}

	}
	return false;

}

bool PokerCombos::isPair(Hand hand){

	vector<int> ranks = sortNumRanks(hand);

	for(int i = 0; i < (int)ranks.size(); i++){

		int numKinds = findNumKinds(hand,ranks[i]);

		if(numKinds == 2){
			return true;
		}

	}
	return false;


}


bool PokerCombos::isStraight(Hand hand){

	return isAlternating(hand);

}


bool PokerCombos::isFullHouse(Hand hand){

	vector<int> ranks = sortNumRanks(hand);

	bool found2Kind = false;
	bool found3Kind = false;

	for(int i = 0; i < (int)ranks.size(); i++){

		int kinds = findNumKinds(hand,ranks[i]);
		if(kinds == 2){
			found2Kind = true;
		}
		if(kinds == 3){
			found3Kind = true;
		}

	}
	return found2Kind && found3Kind;



}

bool PokerCombos::isFourOfAKind(Hand hand){

	vector<int> sortedNumRanks = sortNumRanks(hand);

	for(int i = 0; i < (int)sortedNumRanks.size(); i++){

		int kinds = findNumKinds(hand,sortedNumRanks[i]);
		if(kinds == 4){
			return true;
		}
	}
	return false;


}

bool PokerCombos::isStraightFlush(Hand hand){

	if(isAlternating(hand) && isSameSuit(hand)){
		return true;
	}
	else{
		return false;
	}

}

int PokerCombos::findLowCard(Hand hand){

	return sortNumRanks(hand)[0];

}

vector<int> PokerCombos::sortNumRanks(Hand hand){

	list<int> numList;

	vector<Card> cards = hand.getHand();

	for(int i = 0; i < (int)cards.size(); i++){
		Card theCard  = cards[i];
		numList.push_back(theCard.getNumRank());
	}

	numList.sort();

	vector<int> ranks;

	while(!numList.empty()){
		int rank = numList.front();
		ranks.push_back(rank);
		numList.pop_front();
	}
	return ranks;
}

int PokerCombos::findNumSuit(Hand hand, string suit){

	int count = 0;

	vector<Card> cards = hand.getHand();

	for(int i = 0; i < (int)cards.size(); i++){

		Card theCard = cards[i];
		if(theCard.getSuit() == suit){
			count++;
		}

	}
	return count;


}

int PokerCombos::findNumKinds(Hand hand, int num){

	// calculate the number of "kinds" of a number, for four of a kind, three of a kind

	int count = 0;

	vector<Card> cards = hand.getHand();

	for(int i = 0; i < (int)cards.size(); i++){

		Card theCard = cards[i];
		if(theCard.getNumRank() == num){
			count++;
		}

	}
	return count;

}


bool PokerCombos::isSameSuit(Hand hand){

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

bool PokerCombos::isAlternating(Hand hand){

	vector<Card> cards = hand.getHand();

	list<int> sortedRanks;
	list<int> origRanks;

	for(int i = 0; i < (int)cards.size(); i++){

		int theNumRank = cards[i].getNumRank();

		sortedRanks.push_back(theNumRank);
		origRanks.push_back(theNumRank);

	}
	sortedRanks.sort();

	vector<int> origRanksVector;
	vector<int> sortedRanksVector;

	for(int eachint : sortedRanks){

		sortedRanksVector.push_back(eachint);

	}

	for(int eachint : origRanksVector){

		origRanksVector.push_back(eachint);

	}

	for(int i = 0; i < (int)origRanksVector.size(); i++){

		int iVal = origRanksVector[i];
		int jVal = sortedRanksVector[i];
		if(iVal != jVal){
			return false;
		}

	}
	return true;

}
