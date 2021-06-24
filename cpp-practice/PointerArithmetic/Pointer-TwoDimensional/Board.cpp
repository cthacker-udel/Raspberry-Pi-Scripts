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