#include "media.h"

int total_duration(media *medias, int len){

    int total = 0;
    for(int i = 0; i < len; i++){
        media bMedia = *(medias+i);
        total += bMedia.duration;
    }
    return total;

}