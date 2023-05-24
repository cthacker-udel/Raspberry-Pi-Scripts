#include "RightTriangle.hpp"


Triangle::Triangle(){
    legA = 10;
    legB = 20;
    hypotenuse = sqrt((legA*legA) + (legB*legB));
    area = (legA * legB) / 2;
    perimeter = legA + legB + sqrt(pow(legA,2) + pow(legB,2));
}

Triangle::Triangle(int newLegA, int newLegB){
    legA = newLegA;
    legB = newLegB;
    hypotenuse = sqrt((legA * legA) + (legB*legB));
    area = (legA * legB) / 2;
    perimeter = legA + legB + sqrt(pow(legA,2) + pow(legB,2));
}


int Triangle::getArea(){
    return area;
}


int Triangle::getPerimeter(){
    return perimeter;
}

int Triangle::getHypotenuse(){
    return hypotenuse;
}
