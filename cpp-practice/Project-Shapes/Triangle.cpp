#include "Triangle.hpp"


Triangle::Triangle(){
    base = 10;
    height = 10;
    sideA = 10;
    sideC = 20;
    area = (base*height) / 2;
    gamma = asin((area * 2)/(sideA * base));
    perimeter = sideA + base + sideC;
}


Triangle::Triange(int newBase, int newHeight, int newSideA, int newSideC){
    base = newBase;
    height = newHeight;
    sideA = newSideA;
    sideC = newSideC;

    area = (base*height) / 2;
    gamma = asin((area * 2)/(sideA * base));
    perimeter = sideA + base + sideC;
}


int Triangle::getSideA(){
    return sideA;
}

int Triangle::getSideC(){
    return sideC;
}

int Triangle::getBase(){
    return base;
}

int Triangle::getHeight(){
    return height;
}

int Triangle::getArea(){
    return area;
}

int Triangle::getGamma(){
    return gamma;
}

int Triangle::getPerimeter(){
    return perimeter;
}
