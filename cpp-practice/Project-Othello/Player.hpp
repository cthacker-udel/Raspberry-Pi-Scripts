/*
 * Player.hpp
 *
 *  Created on: Jun 18, 2021
 *      Author: Cameron
 */

#include <string>
#include <iostream>
using namespace std;

class Player{

	string name;
	char piece;
	friend class Othello;

public:

	Player();

	Player(string,char);

};