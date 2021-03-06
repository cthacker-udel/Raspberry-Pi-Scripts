import requests
from pprint import pprint
import sys
import json


def run():
    url = 'https://apex.oracle.com/pls/apex/raspberrypi/weatherstation/getallstations'
    data = requests.get(url).json()['items']
    #pprint(data)
    for eachvar in data:
        print(eachvar['weather_stn_id'])




if __name__ == '__main__':
    run()
