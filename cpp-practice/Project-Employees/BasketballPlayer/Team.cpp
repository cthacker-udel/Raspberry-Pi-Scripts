#include "Team.hpp"

Team::Team(){

    this->name = "default name";
    this->players = 0;
    this->wins = 0;
    this->losses = 0;
    this->championshipsWon = 0;
    this->playoffGamesWon = 0;

}

Team::Team(string newName, int newPlayers){

    this->name = newName;
    this->players = newPlayers;
    this->wins = 0;
    this->losses = 0;
    this->championshipsWon = 0;
    this->playoffGamesWon = 0;

}