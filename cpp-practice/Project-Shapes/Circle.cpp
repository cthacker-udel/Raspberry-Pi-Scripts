#include "Circle.hpp"


Circle::Circle(){
    radius = 10;
}

Circle::Circle(int newRadius){
    radius = newRadius;
}

int Circle::getRadius(){
    return radius;
}

void Circle::setRadius(int newRadius){
    radius = newRadius;
}

int Circle::getDiameter(){
    return diameter;
}

void Circle::setDiameter(int newDiameter){
    diameter = newDiameter;
}

int Circle::getArea(){
    return area;
}

void Circle::setArea(int newArea){
    area = newArea;
}

int Circle::getCircumference(){
    return circumference;
}

void Circle::setCircumference(int newCircumference){
    circumference = newCircumference;
}

void Circle::calculateArea(){
    area = PI * pow(radius,2);
}

void Circle::calculateDiameter(){
    diameter = 2 * radius;
}

void Circle::calculateCircumference(){
    circumference = 2 * PI * radius;
}


