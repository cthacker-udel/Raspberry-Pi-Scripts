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