#include "Board.hpp"


Board::Board(){

    size = 4;

}

Board::Board(int newSize){

    size = newSize;

}

Board::~Board(){

    cout << "Destroying the Board" << endl;

}

int **Board::getBoard(){

    return board;

}

int Board::sumBoard(){

    int sum = 0;
    for(int i = 0; i < size; i++){

        for(int j = 0; j < size; j++){
        
            sum += *(*(board+i)+j);
        
        }

    }
    return sum;

}

int Board::evenCount(){

    int count = 0;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            int value = *(*(board+i)+j);
            if(value % 2 == 0 && value != 0){
                count++;
            }
        }
    }
    return count;

}

int Board::oddCount(){

    int count = 0;

    for(int i = 0; i < size; i++){

        for(int j = 0; j < size; j++){

            int value = *(*(board+i)+j);
            if(value % 2 != 0){
                count++;
            }

        }

    }
    return count;

}

int Board::primeCount(){

    int count = 0;

    for(int i = 0; i < size; i++){

        for(int j = 0; j < size; j++){

            int value = *(*(board+i)+j);
            if(isPrime(value)){
                count++;
            }

        }

    }
    return count;

}

bool Board::isPrime(int number){

    if(number < 0){
        return false;
    }
    else if(number < 2){
        return true;
    }
    else if(number == 2 || number == 3 || number == 5){
        return true;
    }
    else{

        int theSqrt = sqrt(number);
        for(int i = 0; i < theSqrt; i++){
            if(number % i == 0){
                return false;
            }
        }
        return true;


    }

}



void Board::craftBoard(){

    board = new int*[size];

    for(int i = 0; i < size; i++){

        for(int j = 0; j < size; j++){

            *(*(board+i)+j) = j;

        }

    }

}


void Board::setBoard(int **newBoard){

    newBoard = board;

}