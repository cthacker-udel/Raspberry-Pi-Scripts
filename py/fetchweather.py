import requests
import json
from pprint import pprint
import sys
from math import radians, cos, sin, asin, sqrt


def run():
   # url2 = 'https://apex.oracle.com/pls/apex/raspberrypi/weatherstation/getallstations'
   # data2 = requests.get(url2).json()['items']
   # for eachvar in data2:
    url = 'https://apex.oracle.com/pls/apex/raspberrypi/weatherstation/getlatestmeasurements/1806941'
        # pprint(url)
        # pprint(data2)
        # pprint('before the if')
        # try:
    stations = requests.get(url).json()['items']
    pprint(stations)
        #    if stations:

                # print('reached f')
                
                 # print('ID with {}, distance = {}'.format(eachvar['weather_stn_id'],haversine(39.757672,-75.742292,eachvar['weather_stn_long'],eachvar['weather_stn_lat'])))
        # except Exception as e:
        #     continue
            # pprint('id = {}'.format(eachvar))
            # pprint('longitude = {}'.format(eachvar['weather_stn_long']))
            # pprintf('latitude = {}'.format(eachvar['weather_stn_lat']))


def haversine(lon1,lat1,lon2,lat2):
    lon1 = radians(lon1)
    lat1 = radians(lat1)
    lon2 = radians(lon2)
    lat2 = radians(lat2)
    dlon = lon2 - lon1
    dlat = lat2 - lat1
    a = sin(dlat/2)**2 + cos(lat1) * cos(lat2) * sin(dlon/2)**2
    distance = 2 * asin(sqrt(a))
    return distance



if __name__ == '__main__':
    run()
