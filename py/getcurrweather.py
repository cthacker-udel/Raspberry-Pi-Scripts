import requests


def run():
    api_key = 'f258ca5a16d84339a5f6cdb4c7700756'
    query_map = {}
    url = 'http://api.weatherbit.io/v2.0/current'
    query_map['lat'] = 39.757
    query_map['lon'] = -75.742
    query_map['key'] = api_key
    query_map['lang'] = 'en'
    response = requests.get(url,params=query_map).json()
    return [(float(response['data'][0]['temp']) * 9/5) + 32,response['data'][0]['weather']['description']]



run()
