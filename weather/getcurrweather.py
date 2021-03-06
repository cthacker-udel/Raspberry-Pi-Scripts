import requests
from pprint import pprint

api_key = 'f258ca5a16d84339a5f6cdb4c7700756'

def run():
    query_map = {}
    url = 'http://api.weatherbit.io/v2.0/current'
    query_map['lat'] = -75.742
    query_map['lon'] = 39.757
    query_map['key'] = api_key
    query_map['lang'] = 'en'
    response = requests.get(url,params=query_map)
    pprint(response)







if __name__ == '__main__':
    run()
