using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <math.h>


class Circle{

    int radius;
    double PI = 3.14159;
    int circumference;
    int area;
    int diameter;

    public:

        Circle();

        Circle(int);

        int getRadius();

        void setRadius(int);

        void calculateDiameter();

        int getDiameter();

        void setDiameter(int);

        void calculateArea();

        int getArea();

        void setArea(int);

        void calculateCircumference();

        int getCircumference();

        void setCircumference(int);



};
