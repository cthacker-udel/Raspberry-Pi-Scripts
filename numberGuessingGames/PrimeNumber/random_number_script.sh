#!/bin/bash

number=$(shuf -i 1-100 -n 1)

echo "The random number is : ${number}"

./game ${number}
