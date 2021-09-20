#include "PokerGame.hpp"

PokerGame::PokerGame(Hand *theDeck, Player *player1, Player *player2){

    this->deck = theDeck;
    this->player1 = player1;
    this->player2 = player2;
    this->games = 0;

}

PokerGame::PokerGame(){

	this->deck = new Hand();
	this->player1 = new Player("Joe",0,0);
	this->player2 = new Player("Carl",0,0);
	this->games = 0;

}


void PokerGame::startGame(){

	// Game Logic

	cout << "The two players facing off today in the arena are : " << endl;

	cout << this->player1->name << " with a total of " << this->player1->wins << " win(s) and " << this->player1->losses << " loss(es)." << endl;

	cout << " and the second player : " << endl;

	cout << this->player2->name << " with a total of " << this->player1->wins << " wins(s) and " << this->player1->losses << " loss(es)." << endl;

	while(true){

		// nest continue playing option outside of game implementation

		if(this->games > 0){
			string res = "";
			do{
				cout << "Do you want to continue playing? (Yy/Nn)" << endl;
				cin >> res;
			}while(res != "Y" && res != "y" && res != "N" && res != "n");

			if(res == "N"){
				endGame();
				return;
			}
			else if(res == "n"){
				endGame();
				return;
			}
		}

		while(true){

			// Game implementation here


		}



	}



}
