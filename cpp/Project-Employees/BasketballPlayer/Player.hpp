#include <string>
#include <vector>
#include <ctype.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Player{

    string name;
    string team;
    int points;
    int blocks;
    int rebounds;

    int pointsInPaint;
    int midRangeShots;
    int threePointShots;
    int pointsInPaintAtt;
    int midRangeShotsAtt;
    int threePointShotsAtt;

    public:

        Player(string,string);

        string getName();

        string getTeam();

        int getPoints();

        void setPoints(int);

        int getBlocks();

        void setBlocks(int);

        int getRebounds();

        void setRebounds(int);

        int getPointsInPaint();

        void setPointsInPaint(int);

        int getMidRangeShots();

        void setMidRangeShots(int);

        int getThreePointShots();

        void setThreePointShots(int);

        int getPointsInPaintAtt();

        void setPointsInPaintAtt(int);

        int getMidRangeShotsAtt();

        void setMidRangeShotsAtt(int);

        int getThreePointShotsAtt();

        void setThreePointShotsAtt(int);



};