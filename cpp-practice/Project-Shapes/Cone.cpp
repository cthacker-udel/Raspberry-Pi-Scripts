#include "Cone.hpp"
#include <math.h>

Cone::Cone(){
    radius = 10;
    height = 10;

    surfaceArea = PI * radius * (radius + sqrt(pow(height,2) + pow(radius,2)));
    slantHeight = sqrt(pow(radius,2) + pow(height,2));
    lateralSurface = PI * radius * sqrt(pow(height,2) + pow(radius,2));
    baseArea = PI * pow(radius,2);
    volume = PI * pow(radius,2) * (height*1.0 / 3);
}


Cone::Cone(int newRadius, int newHeight){

    radius = newRadius;
    height = newHeight;

    surfaceArea = PI * radius * (radius + sqrt(pow(height,2) + pow(radius,2)));

    slantHeight = sqrt(pow(radius,2) + pow(height,2));

    lateralSurface = PI * radius * sqrt(pow(height,2) + pow(radius,2));

    baseArea = PI * pow(radius,2);

    volume = PI * pow(radius,2) * (height*1.0 / 3);

}


int Cone::getSurfaceArea(){
    return surfaceArea;
}

int Cone::getBaseArea(){
    return baseArea;
}

int Cone::getLateralSurface(){
    return lateralSurface;
}

int Cone::getVolume(){
    return volume;
}

int Cone::getSlantHeight(){
    return slantHeight;
}

int Cone::getRadius(){
    return radius;
}

int Cone::getHeight(){
    return height;
}

void Cone::setRadius(int newRadius){
    radius = newRadius;

    surfaceArea = PI * radius * (radius + sqrt(pow(height,2) + pow(radius,2)));

    slantHeight = sqrt(pow(radius,2) + pow(height,2));

    lateralSurface = PI * radius * sqrt(pow(height,2) + pow(radius,2));

    baseArea = PI * pow(radius,2);

    volume = PI * pow(radius,2) * (height*1.0 / 3);

}

void Cone::setHeight(int newHeight){
    height = newHeight;

    surfaceArea = PI * radius * (radius + sqrt(pow(height,2) + pow(radius,2)));

    slantHeight = sqrt(pow(radius,2) + pow(height,2));

    lateralSurface = PI * radius * sqrt(pow(height,2) + pow(radius,2));

    baseArea = PI * pow(radius,2);

    volume = PI * pow(radius,2) * (height*1.0 / 3);

}


