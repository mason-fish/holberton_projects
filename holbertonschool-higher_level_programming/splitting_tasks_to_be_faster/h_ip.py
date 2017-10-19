from threading import Thread
import requests
import socket
import json

class IPThread(Thread):
    def __init__(self, ip, callback):
        Thread.__init__(self)
        try:
            socket.inet_aton(ip)
        except socket.error:
            return "Invalid ip address"
        self.ip = ip
        self.callback = callback

    def run(self):
        print("Search: {0}".format(self.ip))
        url = "https://api.ip2country.info/ip?"
        res = requests.get(url + self.ip)
        data = json.loads(res.content)
        country = data['countryName']
        self.callback(country)
        print("countryName: {0}".format(country))