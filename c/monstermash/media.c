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

char *longest_kind(media *medias, int len){

    if(len == 0){
        return "";
    }

    double max = 0.0;
    for(int i = 0; i < len; i++){
        media bMedia = *(medias+i);
        max = fmax(max,bMedia.duration);
    }


    for(int i = 0; i < len; i++){
        media bMedia = *(medias+i);
        if(bMedia.duration == max){
            return bMedia.kind;
        }
    }

}

int same_kind_of_media(media *medias, int len){

    if(len == 0){
        return 0;
    }
    else{

        media firstMedia = *(medias+0);
        char *firstKind = firstMedia.kind;
        for(int i = 0; i < len; i++){
            media bMedia = *(medias+i);
            if(strcmp(firstKind,bMedia.kind) != 0){
                return 0;
            }
        }
        return 1;

    }


}
