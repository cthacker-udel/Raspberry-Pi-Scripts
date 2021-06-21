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

void Game::correctComputerAnswer(){

    cout << "The computer has chosen incorrectly! They gain 1 point\n";

}

void Game::incorrectComputerAnswer(){

    cout << "The computer has chosen incorrectly! They lose 1 point\n";

}

bool isPrime(int number){

    if(number < 2){
        return true;
    }
    else if(number == 2 || number == 3 || number == 5){
        return true;
    }
    else{

        for(int i = 0; i < ((int)sqrt(number))+1; i++){
            if(number % i == 0){
                return false;
            }
        }
        return true;
    }

}



void Game::startGame(){

    srand(time(NULL));

    while(1){

        if(numPlayers == 0){

            int randomNumber = rand() % 100000;
            if(turn){
                int computerGuess = rand() % 2 + 1;
                if(computerGuess == 1 && isPrime(randomNumber)){
                    player1.points++;
                    turn = !turn;
                    correctComputerAnswer();
                    player1.displayPoints();
                }
                else if(computerGuess == 1 && !isPrime(randomNumber)){
                    player1.points--;
                    turn = !turn;
                    incorrectComputerAnswer();
                    player1.displayPoints();
                }
                else if(computerGuess == 0 && !isPrime(randomNumber)){
                    player1.points++;
                    turn = !turn;
                    correctComputerAnswer();
                    player1.displayPoints();
                }
                else if(computerGuess == 0 && isPrime(randomNumber)){
                    player1.points--;
                    turn = !turn;
                    incorrectComputerAnswer();
                    player1.displayPoints();
                }
            }
            else{
                int computerGuess = rand() % 2 + 1;
                if((computerGuess == 1 && isPrime(randomNumber))){
                    player2.points++;
                    turn = !turn;
                    correctComputerAnswer();
                    player2.displayPoints();
                }
                else if(computerGuess == 1 && !isPrime(randomNumber)){
                    player2.points--;
                    turn = !turn;
                    incorrectComputerAnswer();
                    player2.displayPoints();
                }
                else if(computerGuess == 0 && !isPrime(randomNumber)){
                    player2.points++;
                    turn = !turn;
                    correctComputerAnswer();
                    player2.displayPoints();
                }
                else if(computerGuess == 0 && isPrime(randomNumber)){
                    player2.points--;
                    turn = !turn;
                    incorrectComputerAnswer();
                    player2.displayPoints();
                }
            }

        }
        else if(numPlayers == 1){

            int randomNumber = rand() % 100000;

                while(1){

                    if(turn){

                        string answer;
                        cout << "Is the number generated prime or not?(y/n)" << endl;
                        cin >> answer;
                        if(tolower(answer[0]) == 'y'){

                            if(isPrime(randomNumber)){
                                player1.points++;
                                turn = !turn;
                                correctAnswer();
                                player1.displayPoints();
                            }
                            else{
                                player1.points--;
                                turn = !turn;
                                incorrectAnswer();
                                player1.displayPoints();
                            }

                        }   
                        else if(tolower(answer[0]) == 'n'){

                            if(!isPrime(randomNumber)){
                                player1.points++;
                                turn = !turn;
                                correctAnswer();
                                player1.displayPoints();
                            }
                            else{
                                player1.points--;
                                turn = !turn;
                                incorrectAnswer();
                                player1.displayPoints();
                            }

                        }

                        else{
                            cout << "Enter a valid input" << endl;
                        }

                    }
                    else{

                        int computerGuess = rand() % 2 + 1;
                        switch(computerGuess){

                            case 1:

                                if(isPrime(randomNumber)){
                                    player2.points++;
                                    turn = !turn;
                                    correctComputerAnswer();
                                    player2.displayPoints();
                                }
                                else{
                                    player2.points--;
                                    turn = !turn;
                                    incorrectComputerAnswer();
                                    player2.displayPoints();
                                }

                                break;

                            case 2:

                                if(!isPrime(randomNumber)){
                                    player2.points++;
                                    turn = !turn;
                                    correctComputerAnswer();
                                    player2.displayPoints();
                                }
                                else{
                                    player2.points--;
                                    turn = !turn;
                                    incorrectComputerAnswer();
                                    player2.displayPoints();
                                }

                                break;
                        }

                    }
                }

        }
        else{

            int randomNumber = rand() % 100000;

            while(1){

                if(turn){

                    string answer;
                    cout << "Is the number generated prime or not?(y/n)\n";
                    cin >> answer;
                    if(tolower(answer[0]) == 'y'){
                        if(isPrime(randomNumber)){
                            player1.points++;
                            turn = !turn;
                            correctAnswer();
                        }
                        else{
                            player1.points--;
                            turn = !turn;
                            incorrectAnswer();
                        }
                    }
                    else if(tolower(answer[0]) == 'n'){
                        if(!isPrime(randomNumber)){
                            player1.points++;
                            turn = !turn;
                            correctAnswer();
                        }
                        else{
                            player1.points--;
                            turn = !turn;
                            incorrectAnswer();
                        }
                    }
                    else{
                        cout << "Enter a valid input" << endl;
                    }

                }
                else{

                    string answer;
                    cout << "Is the number generated prime or not?(y/n)\n";
                    cin >> answer;
                    if(tolower(answer[0]) == 'y'){
                        if(isPrime(randomNumber)){
                            player2.points++;
                            turn = !turn;
                            correctAnswer();
                        }
                        else{
                            player2.points--;
                            turn = !turn;
                            incorrectAnswer();
                        }
                    }
                    else if(tolower(answer[0]) == 'n'){
                        if(!isPrime(randomNumber)){
                            player2.points++;
                            turn = !turn;
                            correctAnswer();
                        }
                        else{
                            player2.points--;
                            turn = !turn;
                            incorrectAnswer();
                        }
                    }
                    else{
                        cout << "Enter a valid input" << endl;
                    }

                }

            }

        }
    }


}


