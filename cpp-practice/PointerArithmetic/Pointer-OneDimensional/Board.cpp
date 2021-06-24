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

void Board::setBoard(int *newBoard){
    board = newBoard;
}

int *Board::getBoard(){

    return board;

}