#include "Cylinder.hpp"
#include <math.h>

Cylinder::Cylinder(){
    radius = 10;
    height = 10;
    surfaceArea = calcSurfaceArea();
    lateralSurface = calcLateralSurface();
    baseArea = calcBaseArea();
    volume = calcVolume();
    diameter = calcDiameter();
}

Cylinder::Cylinder(int newRadius, int newHeight){
    radius = newRadius;
    height = newHeight;

    surfaceArea = calcSurfaceArea();
    lateralSurface = calcLateralSurface();
    baseArea = calcBaseArea();
    volume = calcVolume();
    diameter = calcDiameter();
}


int Cylinder::calcSurfaceArea(){
    int result = 2*PI*radius*height + 2*PI*(radius*radius);
    return result; 
}


int Cylinder::calcLateralSurface(){
    int result = 2*PI*radius*height;
    return result;
}

int Cylinder::calcBaseArea(){
    int result = PI * (radius*radius);
    return result;
}

int Cylinder::calcVolume(){
    int result = PI*(radius*radius)*height;
    return result;
}

int Cylinder::calcDiameter(){
    int result = 2*sqrt(volume / (PI*height));
    return result;
}

void Cylinder::setRadius(int newRadius){
    radius = newRadius;
    surfaceArea = calcSurfaceArea();
    lateralSurface = calcLateralSurface();
    baseArea = calcBaseArea();
    volume = calcVolume();
    diameter = calcDiameter();
}

void Cylinder::setHeight(int newHeight){
    height = newHeight;
    surfaceArea = calcSurfaceArea();
    lateralSurface = calcLateralSurface();
    baseArea = calcBaseArea();
    volume = calcVolume();
    diameter = calcDiameter();
}

int Cylinder::getSurfaceArea(){
    return surfaceArea;
}

int Cylinder::getLateralSurface(){
    return lateralSurface;
}

int Cylinder::getVolume(){
    return volume;
}

int Cylinder::getBaseArea(){
    return baseArea;
}

int Cylinder::getDiameter(){
    return diameter;
}
