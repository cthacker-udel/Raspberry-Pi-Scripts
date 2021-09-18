#ifndef POKER_GAME_HPP
#define POKER_GAME_HPP

#pragma once

#include "PokerCombos.hpp"
#include "Player.hpp"

class PokerGame{

    Hand *deck;
    Player *player1;
    Player *player2;
    int games;

    public:

        PokerGame(Hand *, Player *, Player *);
        
        PokerGame();
        
        void startGame();

        void endGame(); // display player stats


};

#endif
