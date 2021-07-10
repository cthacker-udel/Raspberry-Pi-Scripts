#include "Cube.hpp"
#include <math.h>

Cube::Cube(int newEdge){
	edge = newEdge;
	volume = edge*edge*edge;
	spaceDiagonal = sqrt(3) * edge;
	surfaceArea = 6 * (edge*edge);
}

int Cube::getEdge(){
	return edge;
}


int Cube::getSurfaceArea(){
	return surfaceArea;
}

int Cube::getVolume(){
	return volume;
}

int Cube::getSpaceDiagonal(){
	return spaceDiagonal;
}
