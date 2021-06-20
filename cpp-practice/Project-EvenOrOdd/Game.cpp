#include "Game.hpp"

Game::Game(){

}

Game::Game(string player1Name){

    Player tempPlayer1(player1Name);

    player1 = tempPlayer1;

}

Game::Game(string player1Name, string player2Name){

    Player tempPlayer1(player1Name);

    Player tempPlayer2(player2Name);

    player1 = tempPlayer1;

    player2 = tempPlayer2;

}

void Game::setPlayer1(Player newPlayer){

    player1 = newPlayer;

}

void Game::setPlayer2(Player newPlayer){

    player2 = newPlayer;

}

void Game::startGame(){



    
}