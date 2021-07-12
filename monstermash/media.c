#include "media.h"

int total_duration(media *medias, int len){

    int total = 0;
    for(int i = 0; i < len; i++){
        media bMedia = *(medias+i);
        total += bMedia.duration;
    }
    return total;

}

int count_not_long(media *medias, int len){

    int count = 0;
    for(int i = 0; i < len; i++){
        media bMedia = *(medias+i);
        if(bMedia.duration < 100){
            count++;
        }
    }
    return count;

}

int take_until_long(media *medias, int len){

    int count = 0;
    for(int i = 0; i < len; i++){
        media bMedia = *(medias+i);
        if(bMedia.duration >= 100){
            return count;
        }
        count++;
    }
    return count;

}