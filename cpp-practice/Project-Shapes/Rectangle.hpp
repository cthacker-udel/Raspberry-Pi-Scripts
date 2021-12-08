using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <math.h>


class Rectangle{

    int length;
    int width;
    int area;
    int perimeter;
    int diagonal;

    public:

        Rectangle();

        Rectangle(int,int);

        int getLength();

        int getWidth();

        void setLength(int);

        void setWidth(int);

        int getArea();

        void setArea(int);

        int getDiagonal();

        void setDiagonal(int);

        int getPerimeter();

        void setPerimeter(int);

        void calculateArea();

        void calculateDiagonal();

        void calculatePerimeter();

};
