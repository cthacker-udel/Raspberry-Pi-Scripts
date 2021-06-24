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


int **Board::craftBoard(){

}


void Board::setBoard(int **newBoard){

    newBoard = board;

}