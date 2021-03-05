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

def random_pixel_number():
    return random.randint(0,255)

def random_pixel_number_list():
    return [x for x in range(0,256)]

def generate_pixel_list():
    x = random_pixel_number_list()
    return [[random.choice(x),random.choice(x),random.choice(x)] for y in range(64)]

def get_the_pixels():
    return sense.get_pixels()

incrementer = 0
while incrementer <= 270:
   # flip_vertical()
    sense.set_pixels(generate_pixel_list())
   # sense.set_rotation(incrementer)
   # sense.show_message("Hello world!")
    incrementer += 90
