#!/bin/bash

number=$(shuf -i 1-1000 -n 1)

./game ${number}
