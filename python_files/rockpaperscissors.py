from sense_hat import SenseHat
import random

sense = SenseHat()

choices = ['Rock','Paper','Scissors']

def press_down(event):
    print('Ended game, exiting')
    return 0
   

def press_left(event):
    print('You chose rock')
    if random.choices(choices)[0] == 'paper':
        sense.show_message('Cpu won')
        return 0
    elif random.choices(choices)[0] == 'Scissors':
        sense.show_message('You won!')
        return 1
    else:
        sense.show_message('Tie!')
        return 0

def press_right(event):
    print('You chose paper')
    choice = random.choices(choices)
    print(choice)
    if choice[0] == 'Scissors':
        sense.show_message('The cpu won')
        return 0
    elif choice[0] == 'Paper':
        sense.show_message('Tie!')
        return 0
    else:
        sense.show_message('You won!')
        return 1

def press_up(event):
    print("You chose scissors")
    if random.choices(choices)[0] == 'Rock':
        sense.show_message("The cpu won")
        return 0
    elif random.choices(choices)[0] == 'Paper':
        sense.show_message('You won!')
        return 1
    else:
        sense.show_message('Tie!')
        return 0

def press_middle(event):
    print('exiting event')
    return 4

def refresh():
    sense.clear()


sense.stick.direction_up = press_up
sense.stick.direction_middle = press_down
sense.stick.direction_left = press_left
sense.stick.direction_right = press_right


def play():
    count = 0
    sense.show_message('Prepare to play rock paper scissors!')
    sense.show_message('RIGHT PAPER | LEFT - ROCK | UP - scissors | DOWN - END GAME',0.01)
    while True:
        event = sense.stick.wait_for_event()
        if event.direction == 'middle':
            break
        else:
            count += 1
    sense.show_message('Total number of games won : {}'.format(count))
            

if __name__ == '__main__':
    play()
