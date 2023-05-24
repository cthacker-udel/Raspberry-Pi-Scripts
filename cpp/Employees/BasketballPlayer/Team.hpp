#include <string>
#include <iostream>
#include <vector>
#include "Player.hpp"
using namespace std;


class Team{

    string name;
    int players;
    vector<Player> thePlayers;
    int wins;
    int losses;
    int championshipsWon;
    int playoffGamesWon;

    public:

        Team(); // default team

        Team(string,int); // name and players

        Team(string,int,int,int,int,int);
        // name and players, wins, losses, championshipsWon, and playoffGamesWon

        string getName();
        int getNumPlayers();

        void addPlayer();

        int getWins();

        int getLosses();

        int getChampionshipsWon();

        int getPlayoffGamesWon();

};