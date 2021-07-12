#!/bin/bash

if [ -z "rentals.txt" ]; then
    touch rentals.txt
else
    echo "rentals.txt exists"
fi

