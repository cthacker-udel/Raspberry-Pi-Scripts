import firstscript
import getcurrweather



def run():
    firstscript.scroll_message_default('Today\'s Weather Forecast ',500)
    result = getcurrweather.run();
    firstscript.scroll_message_default('{} degrees Fahrenheit with {}'.format(result[0],result[1]));



run()



