#include "Board.hpp"


Board::Board(){

    size = 4;

}

Board::Board(int newSize){

    size = newSize;

}

Board::~Board(){

    delete []board;

}

void Board::craftBoard(){

    board = new int[size];

}

int Board::sumBoard(){

    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += *(board+i);
    }
    return sum;

}

int Board::primeCount(){

    int count = 0;
    for(int i = 0; i < size; i++){
        int value = *(board+i);
        if(isPrime(value)){
            count++;
        }
    }
    return count;

}

int Board::evenCount(){

    int count = 0;
    for(int i = 0; i < size; i++){
        int value = *(board+i);
        if(value % 2 == 0){
            count++;
        }
    }
    return count;

}

bool Board::isPrime(int number){

    if(number < 2 && number >= 0){
        return true;
    }
    else if(number == 2 || number == 3 || number == 5){
        return true;
    }
    else if(number % 2 == 0 || number % 3 == 0 || number % 5 == 0){
        return false;
    }
    else{
        int sqrtNumber = sqrt(number);
        for(int i = 2; i < sqrtNumber; i++){
            if(number % i == 0){
                return false;
            }
        }
        return true;
    }

}

int Board::oddCount(){

    int count = 0;
    for(int i = 0; i < size; i++){
        int value = *(board+i);
        if(value % 2 != 0){
            count++;
        }
    }
    return count;

}

void Board::setBoard(int *newBoard){
    board = newBoard;
}

int *Board::getBoard(){

    return board;

}