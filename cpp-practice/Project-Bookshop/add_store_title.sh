#!/bin/bash

if [ ! -e bookstore_records.txt ]; then
    touch bookstore_records.txt
else
    echo "Bookstore records have already been instantiated"
fi