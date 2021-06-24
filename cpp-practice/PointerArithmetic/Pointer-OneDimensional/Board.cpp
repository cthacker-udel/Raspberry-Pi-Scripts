#include "Board.hpp"


Board::Board(){

    size = 4;

}

Board::Board(int newSize){

    size = newSize;

}

void Board::setBoard(int *newBoard){
    board = newBoard;
}

int *Board::getBoard(){

    return board;

}