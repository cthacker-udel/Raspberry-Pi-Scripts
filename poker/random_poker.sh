#!/bin/bash

random_number=$(shuf -i 2-1000 -n 1)

./poker ${random_number}
