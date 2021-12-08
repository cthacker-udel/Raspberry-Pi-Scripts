#include <string>
#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <vector>
#include <utility>
#include <cmath>
#include "Player.hpp"
using namespace std;


class Othello{

	char board[8][8];
	int size;
	Player player1;
	Player player2;
	int numPlayer;

public:

	Othello();

	Othello(string str1, char c);

	Othello(string str1, char c, string str2, char c2);

	void makemat();

	void printmat();

	void placepiece(Player);

	int countandflippieces(int,int,string,bool,int);

	void ckwin();

	void playGame();

	void compplacepiece(Player);


};