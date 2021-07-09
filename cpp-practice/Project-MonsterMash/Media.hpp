#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class Media{

    string name;
    string kind;
    int duration;

    public:

        Media(string,string,int);

        int total_duration(vector<Media>);

        int count_not_long(vector<Media>);

        int take_until_long(vector<Media>);

        string longest_kind(vector<Media>);

        bool some_kind_of_media(vector<Media>);


};