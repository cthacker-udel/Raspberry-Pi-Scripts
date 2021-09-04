
#ifndef PLAYER_HPP
#define PLAYER_HPP

#pragma once

#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

class Player{

    string name;
    int wins;
    int losses;

    public:

        Player(string,int,int);

};

#endif
