import time
import sys
import firstscript

def the_message(y,x):
    the_time = float(y)*60
    firstscript.scroll_message_default('Reminder of {} set for {} minutes'.format(x,(int(y)*60) / 60),10)
    while the_time > 60:
        time.sleep(60)
        the_time -= 60
    time.sleep(the_time)
    firstscript.scroll_message_default(x)




if __name__ == '__main__':
    the_message(sys.argv[1],sys.argv[2])
