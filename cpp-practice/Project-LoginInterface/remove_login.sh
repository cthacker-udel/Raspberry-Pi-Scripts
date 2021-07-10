#!/bin/bash


if [ ! -z logindetails.txt ]; then
    rm -rf logindetails.txt
else
    echo "login file has not yet been created"
fi