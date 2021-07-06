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

is_prime(){

    num=$1
    loop_num=$((num-1))
    for i in {2..${loop_num}}; do
        if [ $((num % i == 0)) ]; then
            return 0
        fi
    done
    return 1

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

your_hp=100
your_shotgun_ammo=0
your_pistol_ammo=0
your_machine_gun_ammo=0

while true; do
    echo -e "\nA zombie appears! Choose how to deal with it, here is your ammo status : "
    echo -e "\n1) Shotgun : $your_shotgun_ammo"
    echo -e "\n2) Pistol : $your_pistol_ammo"
    echo -e "\n3) Machine gun : $your_machine_gun_ammo"
    echo -e "\n4) Baseball bat"
    echo -e "\n5) Hand-To-Hand"
    read answer
    
done

