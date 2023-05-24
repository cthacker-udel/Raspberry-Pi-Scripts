#include "Rhombus.hpp"
#include <math.h>

Rhombus::Rhombus(int newPDiagonal, int newQDiagonal, int newSideLength){
	pDiagonal = newPDiagonal;
	qDiagonal = newQDiagonal;
	side = newSideLength;
	area = (pDiagonal * qDiagonal) / 2;
	perimeter = 4*side;
}

int Rhombus::getPDiagonal(){
	return pDiagonal;
}

int Rhombus::getQDiagonal(){
	return qDiagonal;
}

int Rhombus::getSideLength(){
	return side;
}

int Rhombus::getArea(){
	return area;
}

int Rhombus::getPerimeter(){
	return perimeter;
}

void Rhombus::setPDiagonal(int newPDiagonal){
	pDiagonal = newPDiagonal;
	area = (pDiagonal * qDiagonal) / 2;
}

void Rhombus::setQDiagonal(int newQDiagonal){
	qDiagonal = newQDiagonal;
	arae = (pDiagonal * qDiagonal) / 2;
}

void Rhombus::setSideLength(int newSideLength){
	side = newSideLength;
	perimeter = 4*side;
}


int Rhombus::getArea(){
	return area;
}


int Rhombus::getPerimeter(){
	return perimeter;
}
