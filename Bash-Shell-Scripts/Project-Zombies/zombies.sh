#!/bin/bash

random_drop(){

    rand_num=$(shuf -i 1-100 -n 1)
    if [ $((rand_num % 2)) -eq 0 ]; then
        # drop successful
    else
        # drop unsuccessful
    fi

}

successful_shot(){

    arg=$1
    is_prime $arg
    if [ $arg -eq 1 ]; then
        #shotgun
        rand_num=$(shuf -i 1-100 -n 1)
        if [ $((rand_num % 2)) -eq 0 -o $((rand_num % 3)) -eq 0 -o $((rand_num % 5)) -eq 0]; then
            return 1
        else
            return 0
        fi
    elif [ $arg -eq 2 ]; then
        #pistol
        rand_num=$(shuf -i 1-100 -n 1)
        if [ $((rand_num % 2)) -eq 0 -o $((rand_num % 3)) -eq 0 ]; then
            return 1
        else
            return 0
        fi
    elif [ $arg -eq 3 ]; then 
        #machine gun
        rand_num=$(shuf -i 1-100 -n 1)
        if [ $((rand_num % 2)) -eq 0 -o $((rand_num % 5)) -eq 0 -o $((rand_num % 3)) -eq 0 -o $((rand_num % 2)) -ne 0 -o $? -eq 1 ]; then
            return 1
        else
            return 0
        fi
    elif [ $arg -eq 4 ]; then
        #baseball bat
        rand_num=$(shuf -i 1-100 -n 1)
        if [ $((rand_num % 2)) -eq 0 ]; then
            return 1
        else
            return 0
        fi
    elif [ $arg -eq 5 ]; then
        #hand-to-hand
        rand_num=$(shuf -i 1-100 -n 1)
        if [ $((rand_num % 2)) -ne 1]; then
            return 1
        else
            return 0
        fi
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
            return 1
        elif [ $((rand_num % 2)) -eq 0]; then
            #ammo drop
            type_of_ammo=$(shuf -i 1-3 -n 1)
            if [ $type_of_ammo -eq 1 ]; then
                #shotgun
                return 2
            elif [ $type_of_ammo -eq 2 ]; then
                #pistol
                return 3
            elif [ "$type_of_ammo" -eq 3 ]; then
                #machine_gun
                return 4
            else
                #shotgun
                return 2
            fi
        fi
    else
        #no drop success
        return 0
    fi

}


echo -e "\nWelcome to the Zombie Survival Game! You are trying to survive the horde, how long can you survive?"

read -p "Enter your players name : " name

your_hp=100
your_shotgun_ammo=$(shuf -i 10-30 -n 1)
your_pistol_ammo=$(shuf -i 15-45 -n 1)
your_machine_gun_ammo=$(shuf -i 8-100 -n 1) 

while true; do
    if [ $your_hp -le 0 ]; then
        echo "You ran out of HP!"
        exit 2
    fi
    echo -e "\nA zombie appears! Choose how to deal with it, here is your ammo status : "
    echo -e "\n1) Shotgun : $your_shotgun_ammo"
    echo -e "\n2) Pistol : $your_pistol_ammo"
    echo -e "\n3) Machine gun : $your_machine_gun_ammo"
    echo -e "\n4) Baseball bat"
    echo -e "\n5) Hand-To-Hand"
    read answer
    if [ $answer -ne 1 -o $answer -ne 2 -o $answer -ne 3 -o $answer -ne 4 -o $answer -ne 5 ]; then
        echo -e "\nChoose a correct input 1-5\n"
    else
        successful_shot $answer
        if [ $? -eq 1 ]; then
            #zombie killed
            item_drop_num=$(shuf -i 0-1 -n 1)
            type_of_drop $item_drop_num
            if [ $? -eq 0 ]; then
                echo -e "\nThe zombie did not drop an item"
            elif [ $? -eq 1 ]; then
                echo -e "\nThe zombie dropped a medkit, that heals you by 10HP!"
                your_hp=$((your_hp + 10))
            elif [ $? -eq 2 ]; then
                rand_ammo=$(shuf -i 10-20 -n 1)
                echo -e "\nThe zombie dropped $rand_ammo shotgun ammo!"
                your_shotgun_ammo=$((your_shotgun_ammo + rand_ammo))
            elif [ $? -eq 3 ]; then
                rand_ammo=$((shuf -i 10-30 -n 1))
                echo -e "\nThe zombie dropped $rand_ammo pistol ammo!"
                your_pistol_ammo=$((your_pistol_ammo + rand_ammo))
            elif [ $? -eq 4 ]; then
                rand_ammo=$((shuf -i 5-40 -n 1))
                echo -e "\nThe zombie dropped $rand_ammo machine gun ammo!"
                your_machine_gun_ammo=$((your_machine_gun_ammo + rand_ammo))
            fi
        else
            #zombie missed
            echo -e "\nYou missed the zombie! You lost 10HP!"
            your_hp=$((your_hp - 10))
        fi
    fi
    
done

