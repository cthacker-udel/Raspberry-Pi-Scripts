#include "RandomPlayer.hpp"


RandomPlayer::RandomPlayer(string newName, int newAge){

    this->age = newAge;
    this->name = newName;

}



int RandomPlayer::getAge(){

    return this->age;


}