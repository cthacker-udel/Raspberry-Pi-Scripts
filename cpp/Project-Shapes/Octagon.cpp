#include "Octagon.hpp"
#include <math.h>

Octagon::Octagon(){

    side = 10;
    perimeter = side*8;
    area = 2*(1 + sqrt(2)) * pow(side,2);

}

Octagon::Octagon(int newSide){

    side = newSide;
    perimeter = side*8;
    area = 2*(1 + sqrt(2)) * pow(side,2);

}

int Octagon::getSide(){

    return side;

}

void Octagon::setSide(int newSide){

    side = newSide;

}

int Octagon::getArea(){

    return area;

}

int Octagon::getPerimeter(){

    return perimeter;

}