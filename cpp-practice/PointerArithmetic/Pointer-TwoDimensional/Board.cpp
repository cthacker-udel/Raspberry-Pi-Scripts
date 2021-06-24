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


void Board::craftBoard(){

    for(int i = 0; i < size; i++){

        for(int j = 0; j < size; j++){

            *(*(board+j)+i) = j;

        }

    }

}


void Board::setBoard(int **newBoard){

    newBoard = board;

}