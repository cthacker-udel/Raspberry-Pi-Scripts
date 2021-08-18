#include <string>
#include <iostream>
#include <vector>
#include "Player.hpp"
using namespace std;


class Team{

    string name;
    int players;
    vector<Player> players;
    int wins;
    int losses;
    int championshipsWon;
    int playoffGamesWon;

    public:

        string getName();
        int getNumPlayers();

        void addPlayer();

        int getWins();

        int getLosses();

        int getChampionshipsWon();

        int getPlayoffGamesWon();

};