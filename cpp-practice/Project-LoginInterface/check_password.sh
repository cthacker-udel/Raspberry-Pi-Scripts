#!/bin/bash -x

echo "before assignment"

firstname=$1
lastname=$2

echo "before execution"

if [ -z logindetails.txt ]; then
    echo "login details file does not exist, cannot check login"
    exit 1
fi

grep "${firstname} ${lastname}" logindetails.txt

if [ $? -eq 0 ]; then
    echo "Account found, logging in"
else
    echo "Account not found, try again"
fi
