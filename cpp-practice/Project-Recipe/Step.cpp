#include "Step.hpp"

Step::Step(string newStep){

    this->step = newStep;

}

Step::Step(string newStep, int newTimes){

    this->step = newStep;
    this->times = newTimes;

}

void Step::setTimes(int newTimes){

    this->times = newTimes;

}