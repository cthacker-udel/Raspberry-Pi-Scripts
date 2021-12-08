#!/bin/bash

if [ ! -e "rentals.txt" ]; then
    touch rentals.txt
    echo "Rental file created!"
fi

