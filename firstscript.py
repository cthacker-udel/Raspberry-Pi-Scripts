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

def clear_hat():
    sense.clear()

def clear_hat_color(r,g,b):
    sense.clear(r,g,b)

def scroll_message_default(amessage,afloat=None,text_color=None,back_color=None):
    if afloat != None and text_color != None and back_color != None:
        sense.show_message("first if")
        sense.show_message(amessage,afloat,text_color,back_color)
    elif afloat != None and text_color != None:
        sense.show_message("second_if")
        sense.show_message(amessage,afloat,text_color)
    elif afloat != None and text_color == None and back_color != None:
        sense.show_message("third if")
        sense.show_message(amessage,afloat,text_color,back_color)
    elif afloat == None and text_color != None and back_color != None:
        sense.show_message("fourth if")
        sense.show_message(amessage,afloat,text_color,back_color)
    else:
        sense.show_message(amessage)

def display_letter(aletter,textcolor=None,backcolor=None):
    if textcolor != None and backcolor != None:
        sense.show_letter(aletter,textcolor,backcolor)
    elif textcolor != None:
        sense.show_letter(aletter,textcolor)
    elif backcolor != None:
        sense.show_letter(aletter,backcolor)
    else:
        sense.show_letter(aletter)

#incrementer = 0
#while incrementer <= 270:
#    display_letter('a')
#    display_letter('w',[255,0,0])
   # flip_vertical()
   # scroll_message_default("Message",2.5,[255,0,0])
   # sense.set_pixel(random_coord(),random_coord(),random_pixel_number(),random_pixel_number(),random_pixel_number())
   # sense.set_pixels(generate_pixel_list())
   # sense.set_rotation(incrementer)
   # sense.show_message("Hello world!")
#    incrementer += 90
