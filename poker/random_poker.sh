#!/bin/bash

random_number=$(shuf -i 2-100 -n 1)

./poker ${random_number}
