#include "Square.hpp"
#include <math.h>


Square::Square(){
    side = 10;
    area = side*side;
    diagonal = sqrt(2)*side;
    perimeter = 4*side;
}


Square::Square(int newSide){
    side = newSide;
    area = side*side;
    diagonal = sqrt(2)*side;
    perimeter = 4*side;
}

void Square::setSideLength(int newSide){
    side = newSide;
}

int Square::getSideLength(){
    return side;
}

int Square::getArea(){
    return area;
}

int Square::getDiagonal(){
    return diagonal;
}

int Square::getPerimeter(){
    return perimeter;
}
