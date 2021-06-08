#include "Rectangle.hpp"

Rectangle::Rectangle(){
    
    int length = 10;
    int width = 10;

}


Rectangle::Rectangle(int newLength,int newWidth){

    int length = newLength;
    int width = newWidth;

}

void Rectangle::calculateArea(){
    area = length * width;
}

void Rectangle::calculateDiagonal(){
    diagonal = (int)sqrt(pow(width,2) + pow(length,2));
}

void Rectangle::calculatePerimeter(){
    perimeter = 2*(length + width);
}


int Rectangle::getLength(){
    return length;
}

int Rectangle::getWidth(){
    return width;
}

int Rectangle::getArea(){
    return area;
}

int Rectangle::getDiagonal(){
    return diagonal;
}

int Rectangle::getPerimeter(){
    return perimeter;
}

void Rectangle::setLength(int newLength){
    length = newLength;
    calculateArea();
    calculateDiagonal();
    calculatePerimeter();
}

void Rectangle::setWidth(int newWidth){
    width = newWidth;
    calculateArea();
    calculateDiagonal();
    calculatePerimeter();
}

void Rectangle::setArea(int newArea){
    area = newArea;
}

void Rectangle::setPerimeter(int newPerimeter){
    perimeter = newPerimeter;
}

void Rectangle::setDiagonal(int newDiagonal){
    diagonal = newDiagonal;
}
