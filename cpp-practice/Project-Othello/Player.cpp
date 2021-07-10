/*
 * Player.cpp
 *
 *  Created on: Jun 17, 2021
 *      Author: Trea & Cameron
 */

#include "Player.hpp"

Player::Player(){

	name = "computer";
	piece = 'B';

}

Player::Player(string newName, char newPiece){

	name = newName;
	piece = newPiece;

}