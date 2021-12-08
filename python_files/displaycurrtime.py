from datetime import datetime
from firstscript import scroll_message_default
from requests import get

def func():
    now = datetime.now()

    current_time = now.strftime("%H:%M:%S")
    y = current_time.split(':')
    x = int(y[0])
    if x < 12:
        current_time += ' AM'
    elif x == 12:
        current_time += ' PM'
    elif x > 12:
        x -= 12
        current_time = '{}:{}:{} PM'.format(x,y[1],y[2])
    scroll_message_default(current_time)


while True:
    func()
