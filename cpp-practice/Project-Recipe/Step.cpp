#include "Step.hpp"

Step::Step(string newStep){

    this->step = newStep;

}

Step::Step(string newStep, int newTimes){

    this->step = newStep;
    this->time = newTimes;

}

void Step::setTime(int newTimes){

    this->time = newTimes;

}