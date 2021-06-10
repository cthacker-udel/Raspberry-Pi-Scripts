#include "Parallelogram.hpp"


Parallelogram::Parallelogram(){
    base = 10;
    side = 10;
    height = 10;
    perimeter = 2*(side + base);
    area = base*height;
}


Parallelogram::Parallelogram(int newBase, int newHeight, int newSide){
    base = newBase;
    height = newHeight;
    side = newSide;
    perimeter = 2*(side + base);
    area = base*height;
}

int Parallelogram::getBase(){
    return base;
}


int Parallelogram::getHeight(){
    return height;
}

int Parallelogram::getSide(){
    return side;   
}

int Parallelogram::getPerimeter(){
    return perimeter;
}

int Parallelogram::getArea(){
    return area;
}
