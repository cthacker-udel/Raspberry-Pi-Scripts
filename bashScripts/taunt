#!/bin/bash


display_message(){

    fortune | cowsay -f tux
    exit 0

}

display_message2(){

    fortune | cowsay -f moofasa
    exit 0

}

display_message3(){

    fortune | cowsay
    exit 0

}

trap display_message SIGHUP

trap display_message2 SIGINT

while true; do
    sleep 1
done



