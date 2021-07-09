#include "Media.hpp"

Media::Media(string newName, string newKind, int newDuration){

    name = newName;
    kind = newKind;
    duration = newDuration;

}

int Media::total_duration(vector<Media> medias){

    int total = 0;
    for(int i = 0; i < medias.size(); i++){
        total += medias.at(i).duration;
    }
    return duration;

}

int Media::count_not_long(vector<Media> medias){

    int count = 0;
    for(int i = 0; i < medias.size(); i++){

         if(medias.at(i).duration < 100){
             count++;
         }

    }
    return count;

}

int Media::take_until_long(vector<Media> medias){

    int count = 0;
    for(int i = 0; i < medias.size(); i++){
        if(medias.at(i).duration >= 100){
            return count;
        }
        count++;
    }
    return count;

}

string Media::longest_kind(vector<Media> medias){

    int max = 0;
    for(int i = 0; i < medias.size(); i++){
        max = fmax(max,medias.at(i).duration);
    }

    for(int i = 0; i < medias.size(); i++){
        if(medias.at(i).duration == max){
            return medias.at(i).kind;
        }
    }
    return "";

}