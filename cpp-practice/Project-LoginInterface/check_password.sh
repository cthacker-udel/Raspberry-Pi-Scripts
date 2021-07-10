#!/bin/bash

firstname=$1
lastname=$2

if [ grep "$firstname $lastname" logindetails.txt ]; then
    echo "Account found, logging in"
else
    echo "Account not found, try again"
fi