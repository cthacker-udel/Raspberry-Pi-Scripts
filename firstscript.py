from sense_hat import SenseHat
import random


sense = SenseHat()
incrementer = 0
while True:
    sense.set_rotation(incrementer)
    sense.show_message("Hello world!")
    if incrementer == 270:
        incrementer = 0
    else:
        incrementer += 90 
