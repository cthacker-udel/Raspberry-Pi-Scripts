#include "PokerGame.hpp"

PokerGame::PokerGame(Hand *theDeck, Player *player1, Player *player2){

    this->deck = theDeck;
    this->player1 = player1;
    this->player2 = player2;

}
