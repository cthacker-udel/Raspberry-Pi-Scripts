from sense_hat import SenseHat
import random

sense = SenseHat() 


def flip_vertical():
    sense.flip_v(True)

def undo_vertical():
    sense.flip_v(False)

def flip_horizontal():
    sense.flip_h(True)

def undo_horizontal():
    sense.flip_h(False)

incrementer = 0
while incrementer <= 270:
    flip_vertical()
    sense.set_rotation(incrementer)
    sense.show_message("Hello world!")
    incrementer += 90
