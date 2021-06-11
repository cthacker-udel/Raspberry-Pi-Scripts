#include "Trapezoid.hpp"


Trapezoid::Trapezoid(){
    aBase = 10;
    bBase = 20;
    cSide = 30;
    dSide = 40;
    height = 50;
    area = ((aBase*1.0 + bBase) / 2) / height;
    perimeter = aBase + bBase + cSide + dSide;

}
