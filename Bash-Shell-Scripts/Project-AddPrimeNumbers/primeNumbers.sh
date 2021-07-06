#!/bin/bash

echo -e "\nThis game will consist of generating n prime numbers, and summing them together\n"

count=0

is_prime(){

    number=$1
    start_number=2
    while [ $start_number -lt $number ]; do
        if [ $((number % start_number)) -eq 0 ]; then
            return 0
        fi
        ((start_number++))
    done
    return 1

}

read -p "How many prime numbers do you want to generate?" num


while [ $count -lt ${num} ]; do
    number=$(shuf -i 1-100000 -n 1)
    is_prime $number
    if [ $? -eq 1 ]; then
        echo -e "\nThe number ${number} is prime"
        ((count++))
    fi
done
