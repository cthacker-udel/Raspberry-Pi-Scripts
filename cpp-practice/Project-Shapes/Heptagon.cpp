#include "Heptagon.hpp"
#include <math.h>

Heptagon::Heptagon(){

    side = 10;
    area = (7.0 / 4) * pow(side,2) * atan(oneEightyRadians*1.0 / 7);
    perimeter = 7*side; 

}

Heptagon::Heptagon(int newSide){

    side = newSide;
    area = (7.0 / 4) * pow(side,2) * atan(oneEightyRadians*1.0 / 7);
    perimeter = 7*side;

}


int Heptagon::getSide(){

    return side;

}

void Heptagon::setSide(int newSide){

    side = newSide;

}

