#!/bin/bash

if [ ! -e rentals.txt]; then
    echo "rental logs do not exist : unable to search"
    exit 0
fi

searchString=$1

grep "${searchString}" rentals.txt

if [ $? -eq 0 ]; then
    #string found
    echo "Rental found!"
else
    echo "Rental not found"
fi