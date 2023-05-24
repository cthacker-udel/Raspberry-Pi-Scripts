#include "Pentagon.hpp"
#include <math.h>

Pentagon::Pentagon(){

    side = 10;
    perimeter = 5*side;
    diagonal = ((1 + sqrt(5)) / 2) * side;
    area = (1.0 / 4) * (sqrt(5 * (5+2 * sqrt(5)))) * pow(side,2);

}

Pentagon::Pentagon(int newSide){

    side = newSide;
    perimeter = side*5;
    diagonal = ((1 + sqrt(5)) / 2) * side;
    area = (1.0 / 4) * (sqrt(5 * (5+2 * sqrt(5)))) * pow(side,2);

}

int Pentagon::getSide(){

    return side;

}

void Pentagon::setSide(int newSide){

    side = newSide;

}


int Pentagon::getArea(){

    return area;

}


int Pentagon::getPerimeter(){

    return perimeter;

}

int Pentagon::getDiagonal(){

    return diagonal;

}