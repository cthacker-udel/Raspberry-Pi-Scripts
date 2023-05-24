#ifndef BOARD_HPP_
#define BOARD_HPP_

#include "Dog.hpp"
#include <iostream>
#include <string.h>
using namespace std;

class Board{

	int size = 20;
	char board[20][20];
	int wallStrength;
	int startx;
	int starty;
	int endx;
	int endy;
	char level;
	Dog mydog;
	bool debug;

public:

	Board(char diff, string name, bool d);

	Board(char diff, bool d);

	Board(bool d);

	void InitAll();

	void boardConfig();

	void printBoard();

	void addFood();

	void addTraps();

	void playGame();

	bool moveDog(char c);

};

#endif
