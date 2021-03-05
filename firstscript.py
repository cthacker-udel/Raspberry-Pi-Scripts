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


def set_the_pixel(x,y,r,g,b):
    sense.set_pixel(x,y,r,g,b)

def random_coord():
    return random.randint(0,7)

def get_the_pixel(x,y):
    return sense.get_pixel(x,y)


incrementer = 0
while incrementer <= 270:
   # flip_vertical()
    sense.set_pixel(random_coord(),random_coord(),random_pixel_number(),random_pixel_number(),random_pixel_number())
   # sense.set_pixels(generate_pixel_list())
   # sense.set_rotation(incrementer)
   # sense.show_message("Hello world!")
    incrementer += 90
