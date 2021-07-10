#!/bin/bash

random_number=$(shuf -i 2-1000 -n 1)

echo "Random number is : $random_number"

./poker ${random_number}
