
#ifndef POKER_COMBOS_HPP
#define POKER_COMBOS_HPP

#pragma once

#include "Hand.hpp"
#include <list>
#include <map>
#include <string>
#include <vector>
using namespace std;

class PokerCombos{
	
	public:
		
		int findHighCard(Hand,int);
		
		bool isThreeOfAKind(Hand);
		
		bool isTwoPair(Hand);
		
		bool isPair(Hand);
		
		bool isStraight(Hand);
		
		bool isFullHouse(Hand);
		
		bool isFourOfAKind(Hand);
		
		bool isStraightFlush(Hand);
		
		bool isFlush(Hand);

		int findLowCard(Hand);
		
		vector<int> sortNumRanks(Hand);
		
		int findNumSuit(Hand,string);
		
		int findNumKinds(Hand,int);
		
		bool isSameSuit(Hand);
		
		bool isAlternating(Hand);
		
		bool isRoyalFlush(Hand);

		int rankHand(Hand);
	
	
};

#endif
