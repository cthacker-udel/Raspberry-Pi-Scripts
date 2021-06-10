#include "Board.hpp"
#include <iostream>
#include <ctype.h>
using namespace std;


Board::Board(char diff, bool d){

	level = diff;
	debug = d;
	wallStrength = 6;
	InitAll();
}

Board::Board(bool d){

	level = 'e';
	debug = d;
	wallStrength = 6;
	InitAll();

}

Board::Board(char diff, string name, bool d){

	level = diff;
	debug = d;
	mydog.name = name;
	wallStrength = 6;
	InitAll();

}

void Board::boardConfig(){


	cout << "before loop" << endl;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			board[i][j] = '+';
		}
	}
	// placing walls
	int count = 0;
	int restriction = tolower(level) == 'e'? 9: tolower(level) == 'm'? 13 : 16;
	cout << "Before loop" << endl;
	while(count <= restriction){
		int isVerticalOrHorizontal = rand () % 2;
		int i = rand() % size;
		int j = rand() % size;
		if(isVerticalOrHorizontal == 1){
			if(board[i][j] != '+'){
				continue;
			}
			else{
				if(tolower(level) == 'e' && count <= 9){
					board[i][j] = '|';
					count++;
				}
				else if(tolower(level) == 'm' && count <= 13){
					board[i][j] = '|';
					count++;
				}
				else if(tolower(level) == 'h' && count <= 16){
					board[i][j] = '|';
					count++;
				}
			}
		}
		else{
			if(board[i][j] != '+'){
				continue;
			}
			else{
				if(tolower(level) == 'e' && count <= 9){
					board[i][j] = '-';
					count++;
				}
				else if(tolower(level) == 'm' && count <= 13){
					board[i][j] = '-';
					count++;
				}
				else if(tolower(level) == 'h' && count <= 16){
					board[i][j] = '-';
					count++;
				}
			}
		}
	}

	cout << "\n TOTAL COUNT = " << count << endl;

	board[startx][0] = 'D';
	board[endx][size-1] = 'E';

}

void Board::printBoard(void){

	mydog.printDog();

	for(int i = 0; i < size; i++){
		cout << "-";
	}
	cout << endl;

	for(int i = 0; i < size; i++){
		cout << "| ";
		for(int j = 0; j < size; j++){
			if(board[i][j] == '+'){
				cout << " ";
			}
			else if(board[i][j] == 'T'){
				if(debug){
					cout << "T";
				}
				else{
					cout << " ";
				}
			}
			else if(board[i][j] == 'F'){
				if(debug){
					cout << "F";
				}
				else{
					cout << " ";
				}
			}
			else if(board[i][j] == 'D'){
				cout << board[i][j];
			}
			else{
				cout << board[i][j];
			}
		}
		cout << " |" << endl;
	}
	cout << mydog.name << " has " << mydog.strength << " strength" << endl;


}

void Board::InitAll(void){

	bool keepPlaying = true;
	while(keepPlaying){

		cout << "What level of difficulty do you want (e, m, or h)?" << endl;
		char c;
		cin >> c;
		level = c;
		startx = rand() % size;
		starty = 0;
		endx = rand() % size;
		endy = size-1;

		mydog.x = startx;
		mydog.y = starty;
		boardConfig();
		addFood();
		addTraps();
		printBoard();
		playGame();

		cout << "Play again?" << endl;
		string s = "no";
		cin >> s;
		if(s == "yes" || s == "Yes" || s == "y" || s == "Y"){
			keepPlaying = true;
			mydog.reset();
		}
		else{
			cout << "Thanks for playing!" << endl;
			keepPlaying = false;
		}
	}
}

void Board::playGame(){

	bool play = true;
	while(play){
		cout << "Move (u, d, l, r) " << endl;
		char c;
		cin >> c;
		play = moveDog(c);
		if(mydog.x == endx && mydog.y == endy){
			cout << "You have won! Congrats!" << endl;
			break;
		}
		printBoard();
	}

}

bool Board::moveDog(char movement){



	switch(tolower(movement)){

		case 'r':{
			int newY = mydog.y + 1;
			if(newY == size){ // dog is  on the edge
				cout << "You are on the edge of the map" << endl;
				return true;
			}
			if(board[mydog.x][newY] == 'F'){ // ran into food
				int randStrength = rand() % 17;
				mydog.changeStrength(randStrength);
				board[mydog.x][mydog.y] = '+';
				mydog.y = newY;
				board[mydog.x][mydog.y] = 'D';
				return true;
			}
			if(board[mydog.x][newY] == 'T'){ // ran into a trap
				int randDecrease = rand() % 17;
				bool res = mydog.changeStrength(randDecrease * -1);
				if(!res){
					mydog.die();
				}
				board[mydog.x][mydog.y] = '+';
				mydog.y = newY;
				board[mydog.x][mydog.y] = 'D';
				return true;
			}
			if(board[mydog.x][newY] == '-' || board[mydog.x][newY] == '|'){
				if(mydog.strength >= 6){
					string response;
					bool res;
					cout << "Do you want to knock down that wall?(yes,Yes,y | no,n,No) Costs 6 strength" << endl;
					cin >> response;
						if(response == "yes"){
							board[mydog.x][newY] = '+';
							cout << "You have broken down the wall" << endl;
							res = mydog.changeStrength(-6);
							if(!res){
								mydog.die();
							}
							board[mydog.x][mydog.y] = '+';
							mydog.y = newY;
							board[mydog.x][mydog.y] = 'D';
							return true;
						}
						else if(response == "Yes"){
							board[mydog.x][newY] = '+';
							cout << "You have broken down the wall" << endl;
							res = mydog.changeStrength(-6);
							if(!res){
								mydog.die();
							}
							board[mydog.x][mydog.y] = '+';
							mydog.y = newY;
							board[mydog.x][mydog.y] = 'D';
							return true;
						}
						else if(response == "y"){
							board[mydog.x][newY] = '+';
							cout << "You have broken down the wall" << endl;
							res = mydog.changeStrength(-6);
							if(!res){
								mydog.die();
							}
							board[mydog.x][mydog.y] = '+';
							mydog.y = newY;
							board[mydog.x][mydog.y] = 'D';
							return true;
						}
						else if(response == "no"){
							cout << "Wall has not been broken, your dog loses 1 strength point" << endl;
							res = mydog.changeStrength(-1);
							if(!res){
								mydog.die();
								return false;
							}
							return true;
						}
						else if(response == "n"){
							cout << "Wall has not been broken, your dog loses 1 strength point" << endl;
							res = mydog.changeStrength(-1);
							if(!res){
								mydog.die();
								return false;
							}
							return true;
						}
						else if(response == "No"){
							cout << "Wall has not been broken, your dog loses 1 strength point" << endl;
							res = mydog.changeStrength(-1);
							if(!res){
								mydog.die();
								return false;
							}
							return true;
						}

				}
				else{

					cout << "There is a wall here, and your dog does not have enough strength to knock it down" << endl;
					return true;

				}
			}
			if(board[mydog.x][newY] == '+'){
				bool res = mydog.changeStrength(-2);
				if(!res){
					mydog.die();
					return false;
				}
				else{
					board[mydog.x][mydog.y] = '+';
					mydog.y = newY;
					board[mydog.x][mydog.y] = 'D';
					return true;
				}
			}
			if(board[mydog.x][newY] == 'E'){
				mydog.y = newY;
				return true;
			}
			break;
		}
		case 'l':{
			int newY = mydog.y - 1;
						if(newY == size){ // dog is  on the edge
							cout << "You are on the edge of the map" << endl;
							return true;
						}
						if(board[mydog.x][newY] == 'F'){ // ran into food
							int randStrength = rand() % 17;
							mydog.changeStrength(randStrength);
							board[mydog.x][mydog.y] = '+';
							mydog.y = newY;
							board[mydog.x][mydog.y] = 'D';
							return true;
						}
						if(board[mydog.x][newY] == 'T'){ // ran into a trap
							int randDecrease = rand() % 17;
							bool res = mydog.changeStrength(randDecrease * -1);
							if(!res){
								mydog.die();
								return false;
							}
							board[mydog.x][mydog.y] = '+';
							mydog.y = newY;
							board[mydog.x][mydog.y] = 'D';
							return true;
						}
						if(board[mydog.x][newY] == '-' || board[mydog.x][newY] == '|'){
							if(mydog.strength >= 6){
								string response;
								bool res;
								cout << "Do you want to knock down that wall?(yes,Yes,y | no,n,No) Costs 6 strength" << endl;
								cin >> response;
									if(response == "yes"){
										board[mydog.x][newY] = '+';
										cout << "You have broken down the wall" << endl;
										res = mydog.changeStrength(-6);
										if(!res){
											mydog.die();
											return false;
										}
										board[mydog.x][mydog.y] = '+';
										mydog.y = newY;
										board[mydog.x][mydog.y] = 'D';
										return true;
									}
									else if(response == "Yes"){
										board[mydog.x][newY] = '+';
										cout << "You have broken down the wall" << endl;
										res = mydog.changeStrength(-6);
										if(!res){
											mydog.die();
											return false;
										}
										board[mydog.x][mydog.y] = '+';
										mydog.y = newY;
										board[mydog.x][mydog.y] = 'D';
										return true;
									}
									else if(response == "y"){
										board[mydog.x][newY] = '+';
										cout << "You have broken down the wall" << endl;
										res = mydog.changeStrength(-6);
										if(!res){
											mydog.die();
											return false;
										}
										board[mydog.x][mydog.y] = '+';
										mydog.y = newY;
										board[mydog.x][mydog.y] = 'D';
										return true;
									}
									else if(response == "no"){
										cout << "Wall has not been broken, your dog loses 1 strength point" << endl;
										res = mydog.changeStrength(-1);
										if(!res){
											mydog.die();
											return false;
										}
										return true;
									}
									else if(response == "n"){
										cout << "Wall has not been broken, your dog loses 1 strength point" << endl;
										res = mydog.changeStrength(-1);
										if(!res){
											mydog.die();
											return false;
										}
										return true;
									}
									else if(response == "No"){
										cout << "Wall has not been broken, your dog loses 1 strength point" << endl;
										res = mydog.changeStrength(-1);
										if(!res){
											mydog.die();
											return false;
										}
										return true;
									}

							}
							else{

								cout << "There is a wall here, and your dog does not have enough strength to knock it down" << endl;
								return true;

							}
						}
						if(board[mydog.x][newY] == '+'){
							bool res = mydog.changeStrength(-2);
							if(!res){
								mydog.die();
								return false;
							}
							else{
								board[mydog.x][mydog.y] = '+';
								mydog.y = newY;
								board[mydog.x][mydog.y] = 'D';
								return true;
							}
						}
						if(board[mydog.x][newY] == 'E'){
							mydog.y = newY;
							return true;
						}
						break;
		}
		case 'u':{
			//mydog.x -= 1;
			int newX = mydog.x - 1;
						if(newX == size){ // dog is  on the edge
							cout << "You are on the edge of the map" << endl;
							return true;
						}
						if(board[newX][mydog.y] == 'F'){ // ran into food
							int randStrength = rand() % 17;
							mydog.changeStrength(randStrength);
							board[mydog.x][mydog.y] = '+';
							mydog.x = newX;
							board[mydog.x][mydog.y] = 'D';
							return true;
						}
						if(board[newX][mydog.y] == 'T'){ // ran into a trap
							int randDecrease = rand() % 17;
							bool res = mydog.changeStrength(randDecrease * -1);
							if(!res){
								mydog.die();
								return false;
							}
							board[mydog.x][mydog.y] = '+';
							mydog.x = newX;
							board[mydog.x][mydog.y] = 'D';
							return true;
						}
						if(board[newX][mydog.y] == '-' || board[newX][mydog.y] == '|'){
							if(mydog.strength >= 6){
								string response;
								bool res;
								cout << "Do you want to knock down that wall?(yes,Yes,y | no,n,No) Costs 6 strength" << endl;
								cin >> response;
									if(response == "yes"){
										board[newX][mydog.y] = '+';
										cout << "You have broken down the wall" << endl;
										res = mydog.changeStrength(-6);
										if(!res){
											mydog.die();
											return false;
										}
										board[mydog.x][mydog.y] = '+';
										mydog.x = newX;
										board[mydog.x][mydog.y] = 'D';
										return true;
									}
									else if(response == "Yes"){
										board[newX][mydog.y] = '+';
										cout << "You have broken down the wall" << endl;
										res = mydog.changeStrength(-6);
										if(!res){
											mydog.die();
											return false;
										}
										board[mydog.x][mydog.y] = '+';
										mydog.x = newX;
										board[mydog.x][mydog.y] = 'D';
										return true;
									}
									else if(response == "y"){
										board[newX][mydog.y] = '+';
										cout << "You have broken down the wall" << endl;
										res = mydog.changeStrength(-6);
										if(!res){
											mydog.die();
											return false;
										}
										board[mydog.x][mydog.y] = '+';
										mydog.x = newX;
										board[mydog.x][mydog.y] = 'D';
										return true;
									}
									else if(response == "no"){
										cout << "Wall has not been broken, your dog loses 1 strength point" << endl;
										res = mydog.changeStrength(-1);
										if(!res){
											mydog.die();
											return false;
										}
										return true;
									}
									else if(response == "n"){
										cout << "Wall has not been broken, your dog loses 1 strength point" << endl;
										res = mydog.changeStrength(-1);
										if(!res){
											mydog.die();
											return false;
										}
										return true;
									}
									else if(response == "No"){
										cout << "Wall has not been broken, your dog loses 1 strength point" << endl;
										res = mydog.changeStrength(-1);
										if(!res){
											mydog.die();
											return false;
										}
										return true;
									}

							}
							else{

								cout << "There is a wall here, and your dog does not have enough strength to knock it down" << endl;
								return true;

							}
						}
						if(board[newX][mydog.y] == '+'){
							bool res = mydog.changeStrength(-2);
							if(!res){
								mydog.die();
								return false;
							}
							else{
								board[mydog.x][mydog.y] = '+';
								mydog.x = newX;
								board[mydog.x][mydog.y] = 'D';
								return true;
							}
						}
						if(board[newX][mydog.y] == 'E'){
							mydog.x = newX;
							return true;
						}
						break;
		}
		case 'd':{
				int newX = mydog.x + 1;
							if(newX == size){ // dog is  on the edge
								cout << "You are on the edge of the map" << endl;
								return true;
							}
							if(board[newX][mydog.y] == 'F'){ // ran into food
								int randStrength = rand() % 17;
								cout << "You have ran into food and gained " << randStrength << "strength!" << endl;
								mydog.changeStrength(randStrength);
								board[mydog.x][mydog.y] = '+';
								mydog.x = newX;
								board[mydog.x][mydog.y] = 'D';
								return true;
							}
							if(board[newX][mydog.y] == 'T'){ // ran into a trap
								int randDecrease = rand() % 17;
								cout << "You have ran into a trap and lost " << randDecrease << " strength!" << endl;
								bool res = mydog.changeStrength(randDecrease * -1);
								if(!res){
									mydog.die();
									return false;
								}
								board[mydog.x][mydog.y] = '+';
								mydog.x = newX;
								board[mydog.x][mydog.y] = 'D';
								return true;
							}
							if(board[newX][mydog.y] == '-' || board[newX][mydog.y] == '|'){
								if(mydog.strength >= 6){
									string response;
									bool res;
									cout << "Do you want to knock down that wall?(yes,Yes,y | no,n,No) Costs 6 strength" << endl;
									cin >> response;
										if(response == "yes"){
											board[newX][mydog.y] = '+';
											cout << "You have broken down the wall" << endl;
											res = mydog.changeStrength(-6);
											if(!res){
												mydog.die();
												return false;
											}
											board[mydog.x][mydog.y] = '+';
											mydog.x = newX;
											board[mydog.x][mydog.y] = 'D';
											return true;
										}
										else if(response == "Yes"){
											board[newX][mydog.y] = '+';
											cout << "You have broken down the wall" << endl;
											res = mydog.changeStrength(-6);
											if(!res){
												mydog.die();
												return false;
											}
											board[mydog.x][mydog.y] = '+';
											mydog.x = newX;
											board[mydog.x][mydog.y] = 'D';
											return true;
										}
										else if(response == "y"){
											board[newX][mydog.y] = '+';
											cout << "You have broken down the wall" << endl;
											res = mydog.changeStrength(-6);
											if(!res){
												mydog.die();
												return false;
											}
											board[mydog.x][mydog.y] = '+';
											mydog.x = newX;
											board[mydog.x][mydog.y] = 'D';
											return true;
										}
										else if(response == "no"){
											cout << "Wall has not been broken, your dog loses 1 strength point" << endl;
											res = mydog.changeStrength(-1);
											if(!res){
												mydog.die();
												return false;
											}
											return true;
										}
										else if(response == "n"){
											cout << "Wall has not been broken, your dog loses 1 strength point" << endl;
											res = mydog.changeStrength(-1);
											if(!res){
												mydog.die();
												return false;
											}
											return true;
										}
										else if(response == "No"){
											cout << "Wall has not been broken, your dog loses 1 strength point" << endl;
											res = mydog.changeStrength(-1);
											if(!res){
												mydog.die();
												return false;
											}
											return true;
										}

								}
								else{

									cout << "There is a wall here, and your dog does not have enough strength to knock it down" << endl;
									return true;

								}
							}
							if(board[newX][mydog.y] == '+'){
								bool res = mydog.changeStrength(-2);
								if(!res){
									mydog.die();
									return false;
								}
								else{
									board[mydog.x][mydog.y] = '+';
									mydog.x = newX;
									board[mydog.x][mydog.y] = 'D';
									return true;
								}
							}
							if(board[newX][mydog.y] == 'E'){
								mydog.x = newX;
								return true;
							}
			break;
		}
		default:
			return true;

	}
	return true;
}

void Board::addFood(){

	int x;
	int y;
	int count = 0;


	if(tolower(level) == 'e'){
		do{
			x = rand() % size;
			y = rand() % size;
			if(board[x][y] == '+'){
				board[x][y] = 'F';
				count++;
			}
		}while(count <= size);
	}
	else if(tolower(level) == 'm'){
		do{

			x = rand() % size;
			y = rand() % size;
			if(board[x][y] == '+'){
				board[x][y] = 'F';
			}


		}while(count <= size-2);
	}
	else if(tolower(level) == 'h'){

		do{

			x = rand() % size;
			y = rand() % size;
			if(board[x][y] == '+'){
				board[x][y] = 'F';
			}

		}while(count <= size-4);

	}

}

void Board::addTraps(){

	int x;
	int y;
	int count = 0;

	if(tolower(level) == 'e'){

		do{

			x = rand() % size;
			y = rand() % size;
			if(board[x][y] == '+'){
				board[x][y] = 'T';
			}
			count++;

		}while(count <= size-6);

	}
	else if(tolower(level) == 'm'){

		do{

			x = rand() % size;
			y = rand() % size;
			if(board[x][y] == '+'){
				board[x][y] = 'T';
			}
			count++;

		}while(count <= size-8);

	}
	else if(tolower(level) == 'h'){

		do{

			x = rand() % size;
			y = rand() % size;

			if(board[x][y] == '+'){
				board[x][y] = 'T';
			}
			count++;

		}while(count <= size-10);

	}


}
