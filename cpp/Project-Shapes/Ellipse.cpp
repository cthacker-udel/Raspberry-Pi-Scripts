#include "Ellipse.hpp"

Ellipse::Ellipse(){
    aAxis = 10;
    bAxis = 20;
    area = PI * aAxis * bAxis;
    /*
     * 
     * calculating circumference
     *
     */ 

    int pi_a_b = PI * (a+b);
    int a_minus_b_squared = (a-b) * (a-b);
    int a_plus_b_squared = (a+b) * (a+b);
    int a_b_fraction = a_minus_b_squared / a_plus_b_squared;
    int inside_sqrt_result = -3 * a_b_fraction + 4;
    int sqrt_inside = sqrt(inside_sqrt_result) + 10;
    int denom = a_plus_b_squared * sqrt_inside;
    int frac_result_2 = a_minus_b_squared / denom;
    int result_total = 3 * frac_result_2 + 1;
    circumference = pi_a_b * result_total;
}


Ellipse::Ellipse(int newAAxis,int newBAxis){
    
    aAxis = newAAxis;
    bAxis = newBAxis;

    area = PI * aAxis * bAxis;

    int pi_a_b = PI * (a+b);
    int a_minus_b_squared = (a-b) * (a-b);
    int a_b_fraction = a_minus_b_squared / a_plus_b_squared;
    int inside_sqrt_result = -3 * a_b_fraction + 4; 
    int sqrt_inside = sqrt(inside_sqrt_result) + 10;
    int denom = a_plus_b_squared * sqrt_inside;
    int frac_result_2 = a_minus_b_squared / denom;
    int result_total = 3 * frac_result_2 + 1;
    circumference = pi_a_b * result_total;

}

int Ellipse::getArea(){
    return area;
}

int Ellipse::getCircumference(){
    return circumference;
}

int Ellipse::getAAxis(){
    return aAxis;
}

int Ellipse::getBAxis(){
    return bAxis;
}
