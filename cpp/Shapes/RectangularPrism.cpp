#include "RectangularPrism.hpp"
#include <math.h>

RectangularPrism::RectangularPrism(){
    length = 10;
    width = 10;
    height = 10;

    area = 2*((width*length) + (height*length) + (height*width));

    volume = width*height*length;

    diagonal = sqrt(pow(length,2) + pow(width,2) + pow(height,2));
}

RectangularPrism::RectangularPrism(int newLength, int newWidth, int newHeight){
    length = newLength;
    width = newWidth;
    height = newHeight;

    area = 2*((width*length) + (height*length) + (height*width));

    volume = width*height*length;

    diagonal = sqrt(pow(length,2) + pow(width,2) + pow(height,2));
}

int RectangularPrism::getArea(){
    return area;
}


int RectangularPrism::getVolume(){
    return volume;
}

int RectangularPrism::getSpaceDiagonal(){
    return diagonal;
}

void RectangularPrism::setWidth(int newWidth){
    width = newWidth;

    area = 2*((width*length) + (height*length) + (height*width));

    volume = width*height*length;

    diagonal = sqrt(pow(length,2) + pow(width,2) + pow(height,2));

}

void RectangularPrism::setHeight(int newHeight){
    height = newHeight;

    area = 2*((width*length) + (height*length) + (height*width));

    volume = width*height*length;

    diagonal = sqrt(pow(length,2) + pow(width,2) + pow(height,2));

}

void RectangularPrism::setLength(int newLength){
    length = newLength;

    area = 2*((width*length) + (height*length) + (height*width));
    
    volume = width*height*length;

    diagonal = sqrt(pow(length,2) + pow(width,2) + pow(height,2));

}


int RectangularPrism::getWidth(){
    return width;
}

int RectangularPrism::getHeight(){
    return height;
}

int RectangularPrism::getLength(){
    return length;
}
