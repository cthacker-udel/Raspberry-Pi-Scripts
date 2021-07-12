#!/bin/bash

firstname=$1
lastname=$2
byr=$3
bmt=$4
bdy=$5
dob="[Date of Birth : ${bdy}/${bmt}/${byr}]"
fullname="[Name : $firstname $lastname]"
carManu=$6
carYear=$7
carMiles=$8
carDetails="[Manufacturer : $carManu | Year : $carYear | Miles : $carMiles]"
fullStr="$fullname $dob $carDetails"

if [ -z "rentals.txt" ]; then
    touch rentals.txt
fi

echo "$fullStr" >> rentals.txt