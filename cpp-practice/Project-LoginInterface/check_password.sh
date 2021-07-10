#!/bin/bash

echo "before assignment"

firstname=$1
lastname=$2

echo "before execution"

if [ grep "$firstname $lastname" logindetails.txt ]; then
    echo "Account found, logging in"
else
    echo "Account not found, try again"
fi