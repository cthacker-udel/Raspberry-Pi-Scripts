#include "SoccerPlayer.hpp"

SoccerPlayer::SoccerPlayer(){

    name = "Ronaldo";
    age = -1;
    goals = -1;
    shotsAtt = -1;
    yellowCards = -1;
    redCards = -1;
    passComplete = -1;
    passAtt = -1;

}

SoccerPlayer::SoccerPlayer(string newName){

    name = newName;
    age = -1;
    goals = -1;
    shotsAtt = -1;
    yellowCards = -1;
    redCards = -1;
    passComplete = -1;
    passAtt = -1;


}

SoccerPlayer::~SoccerPlayer(){

    cout << "Deleting soccer player" << endl;
    delete this;

}

string SoccerPlayer::getName(){

    return name;

}

int SoccerPlayer::getAge(){

    return age;

}

void SoccerPlayer::setAge(int newAge){

    age = newAge;

}

int SoccerPlayer::getGoals(){

    return goals;

}

void SoccerPlayer::setGoals(int newGoals){

    goals = newGoals;

}