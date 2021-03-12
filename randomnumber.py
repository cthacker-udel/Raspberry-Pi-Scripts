import firstscript as sense
import random
import time



def get_random_time():
    random_time_frame = random.randrange(7,25)
    return random_time_frame


def get_random():
    numbers = [1,2,3,4,5,6,7,8,9]
    y = get_random_time()
    for i in range(y):
        sense.display_letter(str(random.choice(numbers)))
        time.sleep(.5)
        sense.clear_hat()
    sense.display_letter(str(random.choice(numbers)),[255,0,0])



if __name__ == '__main__':
    get_random()
