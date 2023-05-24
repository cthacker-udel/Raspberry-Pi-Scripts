#include "Game.hpp"

Game::Game(){

    numPlayers = 0;

}

Game::Game(string player1Name){

    Player tempPlayer1(player1Name);

    player1 = tempPlayer1;

    numPlayers = 1;

}

Game::Game(string player1Name, string player2Name){

    Player tempPlayer1(player1Name);

    Player tempPlayer2(player2Name);

    player1 = tempPlayer1;

    player2 = tempPlayer2;

    numPlayers = 2;

}

void Game::setPlayer1(Player newPlayer){

    player1 = newPlayer;

}

void Game::setPlayer2(Player newPlayer){

    player2 = newPlayer;

}

void Game::displayRules(){

    cout << "The rules of the game are : the computer generates a random number, which is not displayed, and the player either guesses even or odd, then if they answer right, the player gains a point and the computer loses a point, if they guess wrong, the player loses a point and the computer gains a point. The player can enter the word quit to quit the game, and display the score, and then determine the winner!" << endl;

}

void Game::displayScore(){

    if(numPlayers == 0){
        cout << "\n---------- SCORES ----------\nCOMPUTER1 : " << player2.points << "\nCOMPUTER2 : " << player1.points << "-\n-------------------\n" << endl;
    }
    else if(numPlayers == 1){
        if(player1.name != "computer"){
            cout << "\n---------- SCORES ----------\nUSER : " << player1.points << "\nCOMPUTER : " << player2.points << "-\n-------------------\n" << endl;
        }
        else{
            cout << "\n---------- SCORES ----------\nUSER : " << player2.points << "\nCOMPUTER : " << player1.points << "-\n-------------------\n" << endl;
        }
    }
    else if(numPlayers == 2){
        cout << "\n---------- SCORES ----------\n" << player1.name << " : " << player1.points << "\n" << player2.name << " : " << player2.points << "-\n-------------------\n" << endl;
    }

}


void Game::startGame(){

    /*

    Implementation : 2 players, 1 player, TODO : 0 players

    */


    srand(time(NULL));
    cout << "\n\n------ Welcome to the game : even or odd! ------\n\n" << endl;
    displayRules();
    string guess;
    bool turn = true;
    while(1){
        int computerRandom = rand() % 10000 + 1;
        cout << "\nEven or Odd?\n";
        cin >> guess;
        if(tolower(guess.at(0)) == 'e' && computerRandom % 2 == 0){
            cout << "\nCorrect guess! Number was : " << computerRandom << " and you guessed even, you gain 1 point while the opposing player loses 1 point" << endl;
            if(numPlayers == 2 && turn){
                player1.points++;
                player2.points--;
                turn = !turn;
                displayScore();
            }
            else if(numPlayers == 2 && !turn){
                player1.points--;
                player2.points++;
                turn = !turn;
                displayScore();
            }
            else if(numPlayers == 1){
                player1.points++;
                player2.points--;
                displayScore();
            }
        }
        else if(tolower(guess.at(0)) == 'e' && computerRandom % 2 != 0){
            cout << "\nIncorrect guess! Number was : " << computerRandom << " and you guessed even, you lose 1 point while the opposing player gains 1 point" << endl;
            if(numPlayers == 2 && turn){
                player1.points--;
                player2.points++;
                turn = !turn;
                displayScore();
            }
            else if(numPlayers == 2 && !turn){
                player1.points++;
                player2.points--;
                turn = !turn;
                displayScore();
            }
            else if(numPlayers == 1){
                player1.points--;
                player2.points++;
                displayScore();
            }
        }
        else if(tolower(guess.at(0)) == 'o' && computerRandom % 2 != 0){
            cout << "\nCorrect guess! Number was : " << computerRandom << " and you guessed odd, you gain 1 point while the opposing player loses 1 point" << endl;
            if(numPlayers == 2 && turn){
                player1.points++;
                player2.points--;
                turn = !turn;
                displayScore();
            }
            else if(numPlayers == 2 && !turn){
                player1.points--;
                player2.points++;
                turn = !turn;
                displayScore();
            }
            else if(numPlayers == 1){
                player1.points++;
                player2.points--;
                displayScore();
            }
        }
        else if(tolower(guess.at(0)) == 'o' && computerRandom % 2 == 0){
            cout << "\nIncorrect guess! Number was : " << computerRandom << " and you guessed odd, you lose 1 point while the opposing player gains 1 point" << endl;
            if(numPlayers == 2 && turn){
                player1.points--;
                player2.points++;
                turn = !turn;
                displayScore();
            }
            else if(numPlayers == 2 && !turn){
                player1.points++;
                player2.points--;
                turn = !turn;
                displayScore();
            }
            else if(numPlayers == 1){
                player1.points--;
                player2.points++;
                displayScore();
            }
        }
        else if(tolower(guess.at(0)) == 'q'){
            break;
        }
    }
    displayScore();


}