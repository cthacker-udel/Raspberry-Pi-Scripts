#!/bin/bash

if [ ! -e bookstore_records.txt ]; then
    touch bookstore_records.txt
    exit 0
else
    echo "Bookstore records have already been instantiated"
fi

name=$1

echo "-=-=-=-=-=-=$name-=-=-=-=-=-=" >> bookstore_records.txt

echo "Title has been added to bookstore_records.txt file"