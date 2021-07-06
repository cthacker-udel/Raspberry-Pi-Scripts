#!/bin/bash

random_drop(){

    rand_num=$(shuf -i 1-100 -n 1)
    if [ ((${rand_num} % 2)) -eq 0 ]; then
        # drop successful
    else
        # drop unsuccessful
    fi

}

successful_shot(){

    arg=$1

    if [ $arg -eq 3 ]; then
        #shotgun
    elif [ $arg -eq 2 ]; then
        #pistol
    elif [ $arg -eq 1 ]; then 
        #machine gun
    elif [ $arg -eq 0 ]; then
        #baseball bat
    elif [ $arg -eq -1 ]; then
        #hand-to-hand
    fi

}

type_of_drop(){

    if [ $1 -eq 1 ]; then
        # randomize drop
        rand_num=$(shuf -i 1-100 -n 1)
        if [ $((rand_num % 2)) -ne 0 ]; then
            # medkit drop
        elif [ $((rand_num % 2)) -eq 0]; then
            #ammo drop
        fi
    else
        #no drop success
    fi

}


echo -e "\nWelcome to the Zombie Survival Game! You are trying to survive the horde, how long can you survive?"

read -p "Enter your players name : " name

opponent_hp=0
your_hp=0
your_shotgun_ammo=0
your_pistol_ammo=0
your_machine_gun_ammo=0

while true; do
    #zombie appears, prompt is given
done

