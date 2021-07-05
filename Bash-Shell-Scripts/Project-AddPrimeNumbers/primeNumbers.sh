#!/bin/bash

echo -e "\nThis game will consist of generating n prime numbers, and summing them together\n"

count=0

is_prime(){

    number=$1
    start_number=2
    while [ start_number -lt number ]; do
        if [ $((number % start_number)) -eq 0 ]; then
            echo "Not a prime number"
            return 0
        fi
    done
    return 1

}


while [ count -lt 5 ]; do
    echo -e "\nGenerating first prime number\n"
    number=$(shuf -i 1-10000 -n 1)
