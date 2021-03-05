from datetime import datetime
from firstscript import scroll_message_default



now = datetime.now()

current_time = now.strftime("%H:%M:%S")

while True:
    scroll_message_default(current_time)
