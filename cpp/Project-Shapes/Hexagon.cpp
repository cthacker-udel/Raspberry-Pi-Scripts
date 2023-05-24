#include "Hexagon.hpp"
#include <math.h>

Hexagon::Hexagon(){

    side = 10;
    area = ((3*sqrt(3)) / 2) * pow(side,2);
    perimeter = 6*side;

}

Hexagon::Hexagon(int newSide){

    side = newSide;
    area = ((3*sqrt(3)) / 2) * pow(side,2);
    perimeter = 6*side;

}

int Hexagon::getSide(){

    return side;

}

void Hexagon::setSide(int newSide){

    side = newSide;

}

int Hexagon::getArea(){

    return area;

}

int Hexagon::getPerimeter(){

    return perimeter;

}
