#!/bin/bash

if [ ! -z "logindetails.txt" ]; then
    touch logindetails.txt
    name=$1
    cat ${name} >> logindetails.txt
    exit 0
else
    name=$1
    cat ${name} >> logindetails.txt
fi
