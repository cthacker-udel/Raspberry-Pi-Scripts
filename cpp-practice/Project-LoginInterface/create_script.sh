#!/bin/bash

if [ ! -z "logindetails.txt" ]; then
    touch logindetails.txt
    firstname=$1
    lastname=$2
    echo "${firstname} ${lastname}" >> logindetails.txt
    exit 0
else
    name=$1
    echo "${firstname} ${lastname}" >> logindetails.txt
fi
