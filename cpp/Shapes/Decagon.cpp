#include "Decagon.hpp"
#include <math.h>

Decagon::Decagon(){

    side = 10;
    area = (5.0 / 2) * pow(side,2) * (sqrt(5 + 2*(sqrt(5))));
    perimeter = side*10;

}

Decagon::Decagon(int newSide){

    side = newSide;

    area = (5.0 / 2) * pow(side,2) * (sqrt(5 + 2*(sqrt(5))));
    
    perimeter = side*10;

}

int Decagon::getSide(){

    return side;

}

void Decagon::setSide(int newSide){

    side = newSide;

}

int Decagon::getArea(){

    return area;

}

int Decagon::getPerimeter(){

    return perimeter;

}