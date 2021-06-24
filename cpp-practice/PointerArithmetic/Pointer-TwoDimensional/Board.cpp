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
                count++:
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


void Board::craftBoard(){

    for(int i = 0; i < size; i++){

        for(int j = 0; j < size; j++){

            *(*(board+i)+j) = j;

        }

    }

}


void Board::setBoard(int **newBoard){

    newBoard = board;

}