#include "Game.hpp"


Game::Game(){

    numPlayers = 0;

    startGame();

}

Game::Game(string player1Name){

    numPlayers = 1;

    Player tempPlayer1(player1Name);

    player1 = tempPlayer1;

    startGame();

}

Game::Game(string player1Name, string player2Name){

    numPlayers = 2;

    Player player1Temp(player1Name);

    Player player2Temp(player2Name);

    player1 = player1Temp;

    player2 = player2Temp;

}

void Game::displayRules(){

    cout << "\nThe rules of this game are for the player to guess if a number is prime or not, if the number is not prime and the opponent guesses wrong, then the player gains a point while the opponent loses a point.\n" << endl;

}

void Game::displayPrompt(){

    cout << "Player, please choose an option (y/n) if number is prime \n" << endl;

}

void Game::correctAnswer(){

    cout << "You have chosen correctly! You gain 1 point \n";

}

void Game::incorrectAnswer(){

    cout << "You have chosen incorrectly! You lose 1 point\n";

}



void Game::startGame(){

    srand(time(NULL));

    if(numPlayers == 0){

        int randomNumber = rand() % 100000;
        if(turn){



        }

    }
    else if(numPlayers == 1){



    }
    else{



    }


}


